/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:51:27 by jeserran          #+#    #+#             */
/*   Updated: 2020/07/29 13:51:30 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycauxnext(t_map *tab)
{
	if (tab->side == 0)
		tab->perpwalldist = (tab->mapx - tab->posx +
		(1 - tab->stepx) / 2) / tab->raydirx;
	else
		tab->perpwalldist = (tab->mapy - tab->posy +
			(1 - tab->stepy) / 2) / tab->raydiry;
	tab->lineheight = (int)(tab->winy / tab->perpwalldist);
	tab->drawstart = -tab->lineheight / 2 + tab->winy / 2;
	if (tab->drawstart < 0)
		tab->drawstart = 0;
	tab->drawend = tab->lineheight / 2 + tab->winy / 2;
	if (tab->drawend >= tab->winy)
		tab->drawend = tab->winy - 1;
	ft_verline(tab);
	tab->col++;
}

void	raycauxtwo(t_map *tab)
{
	while (tab->hit == 0)
	{
		if (tab->sidedistx < tab->sidedisty)
		{
			tab->sidedistx += tab->deltadistx;
			tab->mapx += tab->stepx;
			tab->side = 0;
		}
		else
		{
			tab->sidedisty += tab->deltadisty;
			tab->mapy += tab->stepy;
			tab->side = 1;
		}
		if (tab->maparray[tab->mapx][tab->mapy] == 2)
			tab->obj = 1;
		if (tab->maparray[tab->mapx][tab->mapy] == 1)
			tab->hit = 1;
	}
	raycauxnext(tab);
}

void	raycaux(t_map *tab)
{
	if (tab->raydirx < 0)
	{
		tab->stepx = -1;
		tab->sidedistx = (tab->posx - tab->mapx) * tab->deltadistx;
	}
	else
	{
		tab->stepx = 1;
		tab->sidedistx = (tab->mapx + 1.0 - tab->posx) * tab->deltadistx;
	}
	if (tab->raydiry < 0)
	{
		tab->stepy = -1;
		tab->sidedisty = (tab->posy - tab->mapy) * tab->deltadisty;
	}
	else
	{
		tab->stepy = 1;
		tab->sidedisty = (tab->mapy + 1.0 - tab->posy) * tab->deltadisty;
	}
	raycauxtwo(tab);
}

void	raycasting(t_map *tab)
{
	tab->col = 0;
	tab->img = mlx_new_image(tab->mlx_ptr, tab->winx, tab->winy);
	tab->img_ptr = mlx_get_data_addr(tab->img, &tab->bpp, &tab->sl,
		&tab->endian);
	while (tab->col < tab->winx)
	{
		tab->camera = 2 * tab->col / (double)tab->winx - 1;
		tab->raydirx = tab->dirx + tab->planex * tab->camera;
		tab->raydiry = tab->diry + tab->planey * tab->camera;
		tab->mapx = (int)tab->posx;
		tab->mapy = (int)tab->posy;
		tab->deltadistx = fabs((1 / tab->raydirx));
		tab->deltadisty = fabs((1 / tab->raydiry));
		tab->hit = 0;
		raycaux(tab);
		tab->zbuffer[tab->col] = tab->perpwalldist;
	}
	if (tab->obj == 1)
		draw_sprite(tab);
	to_img(tab);
}
