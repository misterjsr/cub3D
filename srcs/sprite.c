/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:52:05 by jeserran          #+#    #+#             */
/*   Updated: 2020/07/29 13:52:08 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			spritepos(t_map *tab, int x, int y)
{
	tab->sprite[tab->numsprite].spriteposx = x + 0.5;
	tab->sprite[tab->numsprite].spriteposy = y + 0.5;
	tab->numsprite++;
}

static	void	how_gap(int *gap)
{
	*gap = (*gap * 10) / 13;
	if (*gap == 9 || *gap == 10)
		*gap = 11;
	if (*gap < 1)
		*gap = 1;
}

static void		sortsprite(t_map *tab)
{
	int		gap;
	int		swapped;
	int		i;
	int		j;

	gap = tab->numsprite;
	while (gap > 1 || swapped)
	{
		how_gap(&gap);
		swapped = 0;
		i = 0;
		while (i < tab->numsprite - gap)
		{
			j = i + gap;
			if (tab->spritedistance[i] < tab->spritedistance[j])
			{
				ft_swap_double(&tab->spritedistance[i],
					&tab->spritedistance[j]);
				ft_swap_int(&tab->spriteorder[i], &tab->spriteorder[j]);
				swapped = 1;
			}
			i++;
		}
	}
}

void			sprite_order(t_map *tab)
{
	int		i;

	i = 0;
	tab->spriteorder = malloc(tab->numsprite * sizeof(int));
	tab->spritedistance = malloc(tab->numsprite * sizeof(double));
	while (i < tab->numsprite)
	{
		tab->spriteorder[i] = i;
		tab->spritedistance[i] = ((tab->posx - tab->sprite[i].spritex) *
			(tab->posx - tab->sprite[i].spritex) +
			(tab->posy - tab->sprite[i].spritey) *
			(tab->posy - tab->sprite[i].spritey));
		i++;
	}
	sortsprite(tab);
}

void			draw_sprite(t_map *tab)
{
	sprite_order(tab);
	raysprite(tab);
}
