/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchi <chuchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:29:35 by jeserran          #+#    #+#             */
/*   Updated: 2020/02/15 10:31:15 by chuchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t x, size_t size)
{
	void	*result;

	result = malloc(size * x);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, x * size);
	return (result);
}
