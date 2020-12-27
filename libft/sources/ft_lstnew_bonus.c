/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchi <chuchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 08:07:58 by jeserran          #+#    #+#             */
/*   Updated: 2020/02/15 10:32:42 by chuchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list		*element;

	if ((element = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	element->content = (void*)content;
	element->next = NULL;
	return (element);
}
