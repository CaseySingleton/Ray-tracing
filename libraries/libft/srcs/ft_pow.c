/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:02:49 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/05 16:45:15 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int num, int power)
{
	long	result;

	if (power == 0)
		return (1);
	if (num == 0 || power < 0)
		return (0);
	result = num;
	while (--power > 0)
	{
		if (result * num < -2147483648 || result * num > 2147483647)
			return (-2147483648);
		result *= num;
	}
	return ((int)result);
}
