/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:50:13 by jeserran          #+#    #+#             */
/*   Updated: 2020/07/29 13:50:17 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pxl_to_img(t_map *tab, int x, int y)
{
	int n;

	if (x < tab->winx && y < tab->winy)
	{
		n = abs((((y * (tab->h[tab->id] * 4) - tab->winy * (tab->h[tab->id] * 2)
			+ tab->lineheight * (tab->h[tab->id] * 2)) * tab->h[tab->id])
					/ tab->lineheight) / (tab->h[tab->id] * 4));
		ft_memcpy(tab->img_ptr + (tab->wbpp[tab->id] / 8) * tab->winx * y
			+ x * (tab->wbpp[tab->id] / 8),
			&tab->wdata[tab->id][n % tab->h[tab->id] * tab->wsl[tab->id] +
			tab->x_text % tab->w[tab->id] *
			tab->wbpp[tab->id] / 8], sizeof(int));
	}
}

void	auxline(t_map *tab)
{
	if (tab->side == 1 && tab->raydiry < 0)
		tab->id = 0;
	tab->x_text = (int)(tab->x_wall * (double)tab->w[tab->id]);
	tab->x_text = abs(tab->x_text);
	while (tab->j <= tab->drawend)
		put_pxl_to_img(tab, tab->col, tab->j++);
	while (tab->j < tab->winy)
	{
		ft_memcpy(tab->img_ptr + 4 * tab->winx * tab->j +
			tab->col * 4, &tab->c, sizeof(int));
		tab->j++;
	}
}

void	ft_verline(t_map *tab)
{
	tab->j = 0;
	while (tab->j < tab->drawstart)
	{
		ft_memcpy(tab->img_ptr + 4 * tab->winx *
			tab->j + tab->col * 4,
			&tab->f, sizeof(int));
		tab->j++;
	}
	tab->j = tab->drawstart;
	if (tab->side == 0)
	{
		tab->id = 3;
		tab->x_wall = tab->posy + tab->perpwalldist * tab->raydiry;
	}
	else
	{
		tab->id = 4;
		tab->x_wall = tab->posx + tab->perpwalldist * tab->raydirx;
	}
	if (tab->side == 0 && tab->raydirx > 0)
		tab->id = 2;
	auxline(tab);
}
