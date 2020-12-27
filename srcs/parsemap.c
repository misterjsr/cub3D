/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:14:45 by jeserran          #+#    #+#             */
/*   Updated: 2020/08/13 17:24:44 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			parsename(char **argv)
{
	char *aux;

	if (!(aux = ft_strchr(argv[1], '.')))
		return (-1);
	if (*(++aux) != 'c')
		return (-1);
	if (*(++aux) != 'u')
		return (-1);
	if (*(++aux) != 'b')
		return (-1);
	return (1);
}

static int	checkborder(t_map *tab)
{
	int i;

	i = -1;
	while (i++ < tab->width)
		if (tab->maparray[0][i] != 1 && tab->maparray[0][i] != 9)
			return (-1);
	i = -1;
	while (i++ < tab->width)
		if (tab->maparray[tab->height][i] != 1 &&
			tab->maparray[tab->height][i] != 9)
			return (-1);
	i = -1;
	while (i++ < tab->height)
		if (tab->maparray[i][0] != 1 && tab->maparray[i][0] != 9)
			return (-1);
	i = -1;
	while (i++ < tab->height)
		if (tab->maparray[i][tab->width] != 1 &&
			tab->maparray[i][tab->width] != 9)
			return (-1);
	return (1);
}

static void	getdirandpos(t_map *tab, int x, int y)
{
	tab->pos++;
	tab->posx = x + 0.5;
	tab->posy = y + 0.5;
	if (tab->dir == 'S')
	{
		tab->dirx = 1;
		tab->diry = 0;
		tab->planex = 0;
		tab->planey = -0.66;
	}
	if (tab->dir == 'W')
	{
		tab->dirx = 0;
		tab->diry = -1;
		tab->planex = -0.66;
		tab->planey = 0;
	}
	if (tab->dir == 'E')
	{
		tab->dirx = 0;
		tab->diry = 1;
		tab->planex = 0.66;
		tab->planey = 0;
	}
}

static int	checkcontent(t_map *tab)
{
	int	i;
	int	j;

	i = 1;
	while (i < tab->height)
	{
		j = 0;
		while (j < tab->width)
		{
			tab->maparray[i][j] == 3 ? getdirandpos(tab, i, j) : 0;
			tab->maparray[i][j] == 2 ? spritepos(tab, i, j) : 0;
			if (((tab->maparray[i][j] == 0) || (tab->maparray[i][j] == 2) ||
				(tab->maparray[i][j] == 3)) && ((tab->maparray[i - 1][j] == 9)
				|| (tab->maparray[i + 1][j] == 9) ||
				(tab->maparray[i][j - 1] == 9) ||
				(tab->maparray[i][j + 1] == 9)))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int			checkmap(t_map *tab)
{
	if (checkborder(tab) == -1)
		return (error(7));
	if (checkcontent(tab) == -1)
		return (error(6));
	if (tab->pos > 1)
		return (error(5));
	if (tab->pos == 0)
		return (error(9));
	if ((test_texture(tab->no) == -1 || test_texture(tab->so) == -1 ||
		test_texture(tab->we) == -1 || test_texture(tab->ea) == -1) ||
		(test_texture(tab->s) == -1))
		return (error(10));
	if (tab->winx > MAXX)
		tab->winx = MAXX;
	if (tab->winy > MAXY)
		tab->winy = MAXY;
	return (1);
}
