/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:50:57 by jeserran          #+#    #+#             */
/*   Updated: 2020/08/13 17:28:50 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	initvar(t_map *tab)
{
	tab->no = NULL;
	tab->so = NULL;
	tab->we = NULL;
	tab->ea = NULL;
	tab->mlx_ptr = NULL;
	tab->win_ptr = NULL;
	tab->id = 0;
	tab->movespeed = 0.12;
	tab->rotspeed = 0.08;
	tab->planex = 0;
	tab->planey = 0.66;
	tab->pos = 0;
	tab->dirx = -1;
	tab->diry = 0;
	tab->sprite = NULL;
	tab->badrgb = 0;
	tab->nocont = 0;
	tab->socont = 0;
	tab->eacont = 0;
	tab->wecont = 0;
	tab->scont = 0;
	tab->fcont = 0;
	tab->ccont = 0;
	tab->rcont = 0;
}

char	*getstr(char *temp)
{
	while (*temp != '.')
		temp++;
	return (temp);
}

void	read_map(t_map *tab)
{
	tab->height = get_height(tab->mapchar);
	tab->width = get_width(tab->mapchar);
	skiptab(tab);
	matrix(tab);
}

void	read_file(int argc, char **file_name, t_map *tab)
{
	int		fd;
	char	*line;
	int		ret;

	ret = 1;
	tab->mapchar = ft_strdup("");
	if ((fd = open(file_name[1], O_RDONLY, 0)) == -1)
	{
		error(8);
		close(fd);
		exit(0);
	}
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		get_info(tab, line);
		free(line);
	}
	close(fd);
	if (parsecub(tab) == -1)
		exit(-1);
	if (argc == 3)
		tab->screenshot = 1;
	if (argc == 3 && ft_strncmp(file_name[2], "--save", 6))
		exit(error(4) * -1);
}

void	openall(t_map *tab)
{
	if (!(tab->mlx_ptr = mlx_init()))
	{
		write(1, "Error\nminilibx initialization failed\n", 38);
		exit(0);
	}
	tab->win_ptr = mlx_new_window(tab->mlx_ptr, tab->winx,
		tab->winy, "CUB3D 42");
	wall_texture(tab);
	tab->fpposx = tab->winx / 2 - tab->w[5] / 2;
	tab->fpposy = tab->winy - tab->h[5];
	raycasting(tab);
	mlx_hook(tab->win_ptr, 2, 1L << 0, nopulsed, tab);
	mlx_hook(tab->win_ptr, 3, 1L << 1, pulsed, tab);
	mlx_hook(tab->win_ptr, 17, 1L << 17, ft_close, tab);
	mlx_loop_hook(tab->mlx_ptr, deal_key, tab);
	mlx_loop(tab->mlx_ptr);
}
