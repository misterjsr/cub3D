/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 11:46:42 by jeserran          #+#    #+#             */
/*   Updated: 2020/08/13 18:22:43 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	error(int i)
{
	if (i == 0)
		write(1, "Error\nIncorrect file entered\n", 30);
	else if (i == 1)
		write(1, "Check the map, it´s wrong\n", 28);
	else if (i == 2)
		write(1, "Error\nWrong arguments, leaving CUB3D\n", 38);
	else if (i == 3)
		write(1, "Error\nMalloc error\n", 20);
	else if (i == 4)
		write(1, "Error\nBad argument\n", 20);
	else if (i == 5)
		write(1, "Error\nTwo or more players in the map\n", 38);
	else if (i == 6)
		write(1, "Error\nWrong map, close walls\n", 30);
	else if (i == 7)
		write(1, "Error\nThe border´s map are wrong\n", 35);
	else if (i == 8)
		write(1, "Error\nFile read failure\n", 25);
	else if (i == 9)
		write(1, "Error\nNo players on the map\n", 29);
	else if (i == 10)
		write(1, "Error\nTextures on map are wrong\n", 33);
	else if (i == 11)
		write(1, "Error\nColors wrong, no RGB (0,255)\n", 36);
	return (-1);
}

int	parsecub(t_map *tab)
{
	if (tab->badrgb == 1)
		return (error(11));
	if (tab->rcont > 1)
		return (error(8));
	if (tab->nocont > 1)
		return (error(8));
	if (tab->eacont > 1)
		return (error(8));
	if (tab->socont > 1)
		return (error(8));
	if (tab->wecont > 1)
		return (error(8));
	if (tab->scont > 1)
		return (error(8));
	if (tab->fcont > 1)
		return (error(8));
	if (tab->ccont > 1)
		return (error(8));
	return (1);
}
