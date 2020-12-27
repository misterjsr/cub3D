/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:51:07 by jeserran          #+#    #+#             */
/*   Updated: 2020/07/29 13:51:10 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	w_and_s(t_map *tab)
{
	if (tab->presedw == 1)
	{
		if ((tab->maparray[(int)(tab->posx + tab->dirx *
			(tab->movespeed + 0.6))][(int)tab->posy]) != 1)
			tab->posx += tab->dirx * tab->movespeed;
		if ((tab->maparray[(int)tab->posx][(int)(tab->posy + tab->diry *
			(tab->movespeed + 0.6))]) != 1)
			tab->posy += tab->diry * tab->movespeed;
	}
	if (tab->preseds == 1)
	{
		if ((tab->maparray[(int)(tab->posx - tab->dirx *
			(tab->movespeed + 0.6))][(int)tab->posy]) != 1)
			tab->posx -= tab->dirx * tab->movespeed;
		if ((tab->maparray[(int)tab->posx][(int)(tab->posy -
			tab->diry * (tab->movespeed + 0.6))]) != 1)
			tab->posy -= tab->diry * tab->movespeed;
	}
}

void	a_and_d(t_map *tab)
{
	if (tab->preseda == 1)
	{
		if ((tab->maparray[(int)(tab->posx - tab->diry *
			(tab->movespeed + 0.6))][(int)tab->posy]) != 1)
			tab->posx -= tab->diry * tab->movespeed;
		if ((tab->maparray[(int)tab->posx][(int)(tab->posy +
			tab->dirx * (tab->movespeed + 0.6))]) != 1)
			tab->posy += tab->dirx * tab->movespeed;
	}
	if (tab->presedd == 1)
	{
		if ((tab->maparray[(int)(tab->posx + tab->diry *
			(tab->movespeed + 0.6))][(int)tab->posy]) != 1)
			tab->posx += tab->diry * tab->movespeed;
		if ((tab->maparray[(int)tab->posx][(int)(tab->posy -
			tab->dirx * (tab->movespeed + 0.6))]) != 1)
			tab->posy -= tab->dirx * tab->movespeed;
	}
}

void	l_and_r(t_map *tab)
{
	tab->olddirx = tab->dirx;
	if (tab->presedl == 1)
	{
		tab->dirx = tab->dirx * cos(tab->rotspeed) - tab->diry *
					sin(tab->rotspeed);
		tab->diry = tab->olddirx * sin(tab->rotspeed) +
					tab->diry * cos(tab->rotspeed);
		tab->oldplanex = tab->planex;
		tab->planex = tab->planex * cos(-tab->rotspeed)
			- tab->planey * sin(tab->rotspeed);
		tab->planey = tab->oldplanex * sin(tab->rotspeed)
			+ tab->planey * cos(-tab->rotspeed);
	}
	if (tab->presedr == 1)
	{
		tab->dirx = tab->dirx * cos(-tab->rotspeed) - tab->diry *
					sin(-tab->rotspeed);
		tab->diry = tab->olddirx * sin(-tab->rotspeed) +
					tab->diry * cos(-tab->rotspeed);
		tab->oldplanex = tab->planex;
		tab->planex = tab->planex * cos(-tab->rotspeed) -
			tab->planey * sin(-tab->rotspeed);
		tab->planey = tab->oldplanex * sin(-tab->rotspeed)
			+ tab->planey * cos(-tab->rotspeed);
	}
}

int		deal_key(t_map *tab)
{
	raycasting(tab);
	w_and_s(tab);
	a_and_d(tab);
	l_and_r(tab);
	if (tab->presedesq == 1)
		ft_close(tab, 1);
	return (1);
}
