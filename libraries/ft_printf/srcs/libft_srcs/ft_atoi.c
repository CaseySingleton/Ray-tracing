/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:13:26 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/19 14:13:27 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		ret;
	int		neg_flag;
	int		too_long;

	ret = 0;
	neg_flag = 1;
	too_long = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		neg_flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret = (ret * 10) + (int)(*str++ - '0');
		if (too_long++ > 18)
			return ((neg_flag == 0) ? -1 : 0);
	}
	return (ret * neg_flag);
}
