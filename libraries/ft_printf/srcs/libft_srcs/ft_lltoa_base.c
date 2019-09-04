/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 00:27:19 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/29 00:27:20 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_lltoa_base(intmax_t n, int base, int upper)
{
	char	*ret;
	int		num_len;

	if (base < 2 || base > 16)
		return (NULL);
	if (n == 0)
		return ((ret = ft_strdup("0")));
	num_len = ft_numlen(n) + ((n < 0) ? 1 : 0);
	ret = ft_strnew(num_len);
	if (n < 0)
		ret[0] = '-';
	while (--num_len >= 0 && ret[num_len] != '-')
	{
		if (base > 10 && (n % base >= 10))
			ret[num_len] = ft_abs(n % base) - 10 + ((upper == 0) ? 'a' : 'A');
		else
			ret[num_len] = ft_abs(n % base) + '0';
		n /= base;
	}
	return (ret);
}
