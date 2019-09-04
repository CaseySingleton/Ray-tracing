/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:41:25 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/23 10:41:25 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nlen(int n)
{
	int		len;

	len = 1;
	if (n == 0)
		return (1);
	while (n / 10 != 0)
	{
		n /= 10;
		len *= 10;
	}
	return (len);
}

void			ft_putnbr_fd(int n, int fd)
{
	int		neg_flag;
	int		len;

	neg_flag = 1;
	len = ft_nlen(n);
	if (n < 0)
	{
		neg_flag = -1;
		ft_putchar_fd('-', fd);
	}
	while (len != 0)
	{
		ft_putchar_fd((((n / len) % 10) * neg_flag) + '0', fd);
		len /= 10;
	}
}
