/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:50:49 by jeserran          #+#    #+#             */
/*   Updated: 2020/07/29 13:50:52 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		doscreenshot(t_map *tab)
{
	int file;
	int filesize;
	int	pad;

	pad = (4 - ((int)tab->winx * 3) % 4) % 4;
	filesize = 60 + (3 * ((int)tab->winx + pad) * (int)tab->winy);
	remove("screenshot.bmp");
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT
		| O_TRUNC | O_APPEND, 777)) < 0)
		return (0);
	if (!write_bmp_header(file, filesize, tab))
		return (0);
	if (!write_bmp_data(file, tab, pad))
		return (0);
	close(file);
	return (1);
}

void	to_img(t_map *tab)
{
	mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr, tab->img, 0, 0);
	mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr,
		tab->wlone[5], tab->fpposx, tab->fpposy);
	if (tab->screenshot == 1)
	{
		doscreenshot(tab);
		exit(1);
	}
	mlx_destroy_image(tab->mlx_ptr, tab->img);
}
