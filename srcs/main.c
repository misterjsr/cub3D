/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:51:14 by jeserran          #+#    #+#             */
/*   Updated: 2020/07/29 13:51:17 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		pulsed(int key, t_map *tab)
{
	if (key == KEY_W)
		tab->presedw = 0;
	if (key == KEY_S)
		tab->preseds = 0;
	if (key == KEY_A)
		tab->preseda = 0;
	if (key == KEY_D)
		tab->presedd = 0;
	if (key == KEY_LEFT)
		tab->presedl = 0;
	if (key == KEY_RIGHT)
		tab->presedr = 0;
	if (key == KEY_ESQ)
		tab->presedr = 0;
	if (key == KEY_SHIFT)
		tab->movespeed = 0.12;
	return (0);
}

int		nopulsed(int key, t_map *tab)
{
	if (key == KEY_W)
		tab->presedw = 1;
	if (key == KEY_S)
		tab->preseds = 1;
	if (key == KEY_A)
		tab->preseda = 1;
	if (key == KEY_D)
		tab->presedd = 1;
	if (key == KEY_LEFT)
		tab->presedl = 1;
	if (key == KEY_RIGHT)
		tab->presedr = 1;
	if (key == KEY_ESQ)
		tab->presedesq = 1;
	if (key == KEY_SHIFT)
		tab->movespeed = 0.35;
	return (0);
}

int		ft_close(t_map *tab, int win)
{
	free(tab->maparray);
	free(tab);
	if (win == 1)
		mlx_destroy_window(tab->mlx_ptr, tab->win_ptr);
	free(tab->mlx_ptr);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_map	*tab;

	if (argc == 2 || argc == 3)
	{
		if (!(tab = malloc(sizeof(t_map))))
			return (error(3));
		if (parsename(argv) == -1)
			return (error(0));
		initvar(tab);
		read_file(argc, argv, tab);
		read_map(tab);
		if (checkmap(tab) == -1)
			return (-1);
		free(tab->mapchar);
		openall(tab);
		return (0);
	}
	return (error(2));
}
