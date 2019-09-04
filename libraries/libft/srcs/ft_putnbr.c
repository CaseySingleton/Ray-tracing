/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:25:18 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/22 16:25:22 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr(int n)
{
	int		neg_flag;
	int		len;

	neg_flag = 1;
	len = ft_numlen(n);
	if (n < 0)
	{
		neg_flag = -1;
		ft_putchar('-');
	}
	while (len != 0)
	{
		ft_putchar((((n / len) % 10) * neg_flag) + '0');
		len /= 10;
	}
}
