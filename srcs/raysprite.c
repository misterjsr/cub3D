/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raysprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:51:37 by jeserran          #+#    #+#             */
/*   Updated: 2020/07/29 13:51:38 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		put_spr(t_map *tab)
{
	tab->sprite[tab->count].texy = fabs((tab->countb -
		tab->sprite[tab->count].spstarty) / (tab->sprite[tab->count].sph /
		(double)tab->h[7]));
	if (tab->wdata[7][tab->sprite[tab->count].texy * tab->wsl[7] +
		tab->sprite[tab->count].texx * tab->wbpp[7] / 8] != 0)
		ft_memcpy(tab->img_ptr + (tab->wbpp[7] / 8) * tab->winx * tab->countb +
			tab->stripe * (tab->wbpp[7] / 8),
			&tab->wdata[7][tab->sprite[tab->count].texy * tab->wsl[7] +
			tab->sprite[tab->count].texx * tab->wbpp[7] / 8], sizeof(int));
	tab->countb++;
}

void		dy(t_map *tab)
{
	tab->stripe = tab->sprite[tab->count].spstartx - 1;
	while (tab->stripe < tab->sprite[tab->count].spendx)
	{
		tab->sprite[tab->count].texx = (int)((tab->stripe -
			tab->sprite[tab->count].spstartx) / (tab->sprite[tab->count].spw /
			(double)tab->w[7]));
		tab->countb = tab->sprite[tab->count].spstarty;
		if (tab->sprite[tab->count].transformy > 0 && tab->stripe > 0 &&
			tab->stripe < tab->winx
			&& tab->sprite[tab->count].transformy < tab->zbuffer[tab->stripe])
		{
			while (tab->countb < tab->sprite[tab->count].spendy)
				put_spr(tab);
		}
		tab->stripe++;
	}
	tab->obj = 0;
}

void		calc_transf(t_map *tab)
{
	double	inv_det;
	double	calc_det;

	calc_det = (tab->planex * tab->diry - tab->dirx * tab->planey);
	inv_det = 1.0 / calc_det;
	tab->sprite[tab->count].transformx = inv_det * (tab->diry *
		tab->sprite[tab->count].spritex - tab->dirx *
		tab->sprite[tab->count].spritey);
	tab->sprite[tab->count].transformy = inv_det * (-tab->planey *
		tab->sprite[tab->count].spritex + tab->planex *
		tab->sprite[tab->count].spritey);
	tab->sprite[tab->count].scx = (int)((tab->winx / 2) *
		(1 + tab->sprite[tab->count].transformx /
		tab->sprite[tab->count].transformy));
	tab->sprite[tab->count].sph = abs((int)(tab->winy /
		tab->sprite[tab->count].transformy));
	tab->sprite[tab->count].spw = abs((int)(tab->winy /
		tab->sprite[tab->count].transformy));
}

void		calc_sprite_place(t_map *tab)
{
	tab->sprite[tab->count].spstarty = -tab->sprite[tab->count].sph / 2 +
		tab->winy / 2;
	if (tab->sprite[tab->count].spstarty < 0)
		tab->sprite[tab->count].spstarty = 0;
	tab->sprite[tab->count].spendy = tab->sprite[tab->count].sph / 2 +
		tab->winy / 2;
	if (tab->sprite[tab->count].spendy >= tab->winy)
		tab->sprite[tab->count].spendy = tab->winy - 1;
	tab->sprite[tab->count].spstartx = -1 * tab->sprite[tab->count].spw / 2 +
		tab->sprite[tab->count].scx;
	if (tab->sprite[tab->count].spstartx < 0)
		tab->sprite[tab->count].spstartx = 0;
	tab->sprite[tab->count].spendx = tab->sprite[tab->count].spw / 2 +
		tab->sprite[tab->count].scx;
	if (tab->sprite[tab->count].spendx >= tab->winx)
		tab->sprite[tab->count].spendx = tab->winx - 1;
}

void		raysprite(t_map *tab)
{
	tab->count = 0;
	while (tab->count < tab->numsprite)
	{
		tab->sprite[tab->count].spritex =
			tab->sprite[tab->spriteorder[tab->count]].spriteposx - tab->posx;
		tab->sprite[tab->count].spritey =
			tab->sprite[tab->spriteorder[tab->count]].spriteposy - tab->posy;
		calc_transf(tab);
		calc_sprite_place(tab);
		dy(tab);
		tab->count++;
	}
}
