/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrumax_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchi <chuchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 00:14:08 by dhojt             #+#    #+#             */
/*   Updated: 2020/02/20 01:34:10 by chuchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbrumax_fd(unsigned long int n, int fd)
{
	if (n > 9)
		ft_putnbrumax_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
