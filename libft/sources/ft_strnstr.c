/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchi <chuchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:28:51 by jeserran          #+#    #+#             */
/*   Updated: 2020/02/15 10:35:33 by chuchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*a;
	char	*b;

	i = 0;
	a = (char*)s1;
	b = (char*)s2;
	if (b[0] == '\0')
		return (a);
	while (a[i] != '\0' && i < n)
	{
		j = 0;
		while (a[i + j] != '\0' && i + j < n && a[i + j] == b[j])
		{
			if (b[j + 1] == '\0')
				return (&a[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
