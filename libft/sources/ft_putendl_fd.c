/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchi <chuchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:42:24 by jeserran          #+#    #+#             */
/*   Updated: 2020/02/15 10:34:05 by chuchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s || !fd)
		return ;
	ft_putstr_fd((char*)s, fd);
	ft_putchar_fd('\n', fd);
}
