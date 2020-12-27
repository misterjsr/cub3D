/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:51:49 by jeserran          #+#    #+#             */
/*   Updated: 2020/08/13 18:25:49 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		resolution(char *temp, t_map *tab)
{
	int			i;
	int			aux;
	char		*temp2;

	i = 0;
	while (!(ft_isdigit(temp[i])))
		i++;
	aux = i;
	while (ft_isdigit(temp[i]))
		i++;
	temp2 = ft_substr(temp, aux, i);
	tab->winx = ft_atoi(temp2);
	free(temp2);
	while (temp[i] == ' ')
		i++;
	aux = i;
	while (ft_isdigit(temp[i]))
		i++;
	temp2 = ft_substr(temp, aux, i);
	tab->winy = ft_atoi(temp2);
	free(temp2);
}

static int		getcolor(unsigned int *color, char *line, t_map *tab)
{
	int			i;

	i = 0;
	while (line[i])
	{
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		tab->r = ft_atoi_color(line, &i);
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		if (line[i] == '\0')
			break ;
		tab->g = ft_atoi_color(line, &i);
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		if (line[i] == '\0')
			break ;
		tab->b = ft_atoi_color(line, &i);
	}
	*color = tab->r * 256 * 256 + tab->g * 256 + tab->b;
	if (tab->r > 255 || tab->g > 255 || tab->b > 255)
		tab->badrgb = 1;
	return (0);
}

static void		get_info3(t_map *tab, char *line)
{
	char	*temp;
	char	*temp2;

	if ((temp = ft_strchr(line, 'C')))
	{
		getcolor(&tab->c, line, tab);
		tab->ccont++;
	}
	else if ((temp = ft_strchr(line, '1')))
	{
		temp = ft_strjoin(line, "\n");
		temp2 = tab->mapchar;
		tab->mapchar = ft_strjoin(tab->mapchar, temp);
		free(temp2);
		free(temp);
	}
}

static void		get_info2(t_map *tab, char *line, int len)
{
	char	*temp;

	if ((temp = ft_strnstr(line, "WE", len)))
	{
		tab->we = ft_strdup(getstr(line));
		tab->wecont++;
	}
	else if ((temp = ft_strnstr(line, "EA", len)))
	{
		tab->ea = ft_strdup(getstr(line));
		tab->eacont++;
	}
	else if ((temp = ft_strnstr(line, "S .", len)))
	{
		tab->s = ft_strdup(getstr(line));
		tab->scont++;
	}
	else if ((temp = ft_strchr(line, 'F')))
	{
		getcolor(&tab->f, line, tab);
		tab->fcont++;
	}
	else
		get_info3(tab, line);
}

void			get_info(t_map *tab, char *line)
{
	char	*temp;
	int		len;

	len = ft_strlen(line);
	if ((temp = ft_strchr(line, 'R')))
	{
		resolution(line, tab);
		tab->rcont++;
	}
	else if ((temp = ft_strnstr(line, "NO", len)))
	{
		tab->no = ft_strdup(getstr(line));
		tab->nocont++;
	}
	else if ((temp = ft_strnstr(line, "SO", len)))
	{
		tab->so = ft_strdup(getstr(line));
		tab->socont++;
	}
	else
		get_info2(tab, line, len);
}
