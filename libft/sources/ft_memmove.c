/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchi <chuchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:17:28 by jeserran          #+#    #+#             */
/*   Updated: 2020/02/15 10:33:44 by chuchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*str;
	char	*dst;

	dst = (char *)s1;
	str = (char *)s2;
	if (s1 == s2)
		return (s1);
	if (s1 < s2)
		ft_memcpy(s1, s2, n);
	else
	{
		dst += n;
		str += n;
		while (n--)
			*(--dst) = *(--str);
	}
	return (s1);
}
