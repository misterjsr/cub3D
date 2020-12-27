/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:50:03 by jeserran          #+#    #+#             */
/*   Updated: 2020/08/12 20:08:29 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			get_height(char *str)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			h++;
		i++;
	}
	return (h);
}

int			get_width(char *str)
{
	int		w;
	int		i;
	int		temp;

	w = 0;
	i = 0;
	temp = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			temp++;
		if (str[i] == '\n')
		{
			if (temp > w)
				w = temp - 1;
			temp = 0;
		}
		i++;
	}
	return (w);
}

void		skiptab(t_map *tab)
{
	int	i;

	i = 0;
	while (tab->mapchar[i] != '\0')
	{
		if (tab->mapchar[i] == '\t')
			tab->mapchar[i] = '8';
		if (tab->mapchar[i] == ' ')
			tab->mapchar[i] = '9';
		if (tab->mapchar[i] == 'N' || tab->mapchar[i] == 'S'
			|| tab->mapchar[i] == 'W' || tab->mapchar[i] == 'E')
		{
			tab->dir = tab->mapchar[i];
			tab->mapchar[i] = '3';
		}
		if (tab->mapchar[i] == '2')
			tab->numsprite++;
		i++;
	}
	tab->sprite = malloc(tab->numsprite * sizeof(t_sprite));
	tab->numsprite = 0;
}

void		stringtoarray(t_map *tab)
{
	if (tab->mapchar[tab->n] == '8')
	{
		tab->maparray[tab->x][tab->y++] = 9;
		tab->maparray[tab->x][tab->y++] = 9;
		tab->maparray[tab->x][tab->y++] = 9;
		tab->maparray[tab->x][tab->y] = 9;
	}
	else if (tab->mapchar[tab->n] == '9')
		tab->maparray[tab->x][tab->y] = 9;
	else if (tab->mapchar[tab->n] == '\n' || tab->mapchar[tab->n] == '\0')
	{
		while (tab->y <= get_width(tab->mapchar))
		{
			tab->maparray[tab->x][tab->y] = 9;
			tab->y++;
		}
		tab->n -= 1;
	}
	else
		tab->maparray[tab->x][tab->y] = tab->mapchar[tab->n] - 48;
	tab->n++;
	tab->y++;
}

void		matrix(t_map *tab)
{
	tab->x = 0;
	tab->n = 0;
	if (!(tab->maparray = malloc(sizeof(int *) *
		(get_height(tab->mapchar) + 1))))
		return ;
	while (tab->x <= get_height(tab->mapchar))
	{
		if (!(tab->maparray[tab->x] = malloc(sizeof(int) *
			(get_width(tab->mapchar) + 1))))
			return ;
		tab->y = 0;
		while (tab->y <= get_width(tab->mapchar))
			stringtoarray(tab);
		tab->n++;
		tab->y = 0;
		tab->x++;
	}
}
