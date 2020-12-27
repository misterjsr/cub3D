/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchi <chuchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:51:18 by jeserran          #+#    #+#             */
/*   Updated: 2020/02/15 10:35:10 by chuchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*m;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((m = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		m[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	m[i] = '\0';
	return (m);
}
