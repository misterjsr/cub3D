/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:52:14 by jeserran          #+#    #+#             */
/*   Updated: 2020/07/29 16:04:52 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	more_texture(t_map *tab)
{
	tab->wlone[5] = mlx_xpm_file_to_image(tab->mlx_ptr,
		"./textures/jeringa.xpm", &tab->w[5], &tab->h[5]);
	tab->wdata[5] = mlx_get_data_addr(tab->wlone[5],
		&tab->wbpp[5], &tab->wsl[5], &tab->wendian[5]);
	tab->wlone[7] = mlx_xpm_file_to_image(tab->mlx_ptr,
		tab->s, &tab->w[7], &tab->h[7]);
	tab->wdata[7] = mlx_get_data_addr(tab->wlone[7],
		&tab->wbpp[7], &tab->wsl[7], &tab->wendian[7]);
	free(tab->we);
	free(tab->so);
	free(tab->ea);
	free(tab->no);
	free(tab->s);
}

void	wall_texture(t_map *tab)
{
	tab->wlone[0] = mlx_xpm_file_to_image(tab->mlx_ptr, tab->we,
					&tab->w[0], &tab->h[0]);
	tab->wdata[0] = mlx_get_data_addr(tab->wlone[0],
		&tab->wbpp[0], &tab->wsl[0], &tab->wendian[0]);
	tab->wlone[2] = mlx_xpm_file_to_image(tab->mlx_ptr, tab->so,
					&tab->w[2], &tab->h[2]);
	tab->wdata[2] = mlx_get_data_addr(tab->wlone[2],
		&tab->wbpp[2], &tab->wsl[2], &tab->wendian[2]);
	tab->wlone[3] = mlx_xpm_file_to_image(tab->mlx_ptr, tab->no,
					&tab->w[3], &tab->h[3]);
	tab->wdata[3] = mlx_get_data_addr(tab->wlone[3],
		&tab->wbpp[3], &tab->wsl[3], &tab->wendian[3]);
	tab->wlone[4] = mlx_xpm_file_to_image(tab->mlx_ptr, tab->ea,
					&tab->w[4], &tab->h[4]);
	tab->wdata[4] = mlx_get_data_addr(tab->wlone[4],
		&tab->wbpp[4], &tab->wsl[4], &tab->wendian[4]);
	more_texture(tab);
}

int		test_texture(char *str)
{
	int	a;

	a = 0;
	if (ft_strcmp(str, TEXTURE_1) != 0)
		a++;
	if (ft_strcmp(str, TEXTURE_2) != 0)
		a++;
	if (ft_strcmp(str, TEXTURE_3) != 0)
		a++;
	if (ft_strcmp(str, TEXTURE_4) != 0)
		a++;
	if (ft_strcmp(str, TEXTURE_5) != 0)
		a++;
	if (str != NULL)
		a++;
	if (a == 5)
		return (1);
	else
		return (-1);
}
