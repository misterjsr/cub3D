/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchi <chuchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:03:57 by jeserran          #+#    #+#             */
/*   Updated: 2020/02/15 10:33:22 by chuchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*c1;
	const char		*c2;
	unsigned int	i;

	c1 = s1;
	c2 = s2;
	i = 0;
	while (i < n)
	{
		*(c1 + i) = *(c2 + i);
		if (*(c2 + i) == (char)c)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
