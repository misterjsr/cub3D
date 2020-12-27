/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-co <jdiaz-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:01:48 by jeserran          #+#    #+#             */
/*   Updated: 2020/07/14 03:03:25 by jdiaz-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	char	*a;
	char	*b;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	a = (char*)s1;
	b = (char*)s2;
	dest = malloc((ft_strlen(a) + ft_strlen(b) + 1));
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0')
		dest[i++] = *s1++;
	while (*s2 != '\0')
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}
