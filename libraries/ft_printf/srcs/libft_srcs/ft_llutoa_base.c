/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 23:50:02 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/28 23:50:02 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numlen_base(uintmax_t n, int base)
{
	int			len;

	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char			*ft_llutoa_base(uintmax_t n, int base, int upper)
{
	char		*ret;
	int			num_len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == UINTMAX_MAX)
		return (ft_strdup("18446744073709551615"));
	if (base < 2 || base > 16)
		return (NULL);
	num_len = ft_numlen_base(n, base);
	ret = ft_strnew(num_len);
	while (--num_len >= 0)
	{
		if (base > 10 && (n % base >= 10))
			ret[num_len] = (n % base) - 10 + ((upper == 0) ? 'a' : 'A');
		else
			ret[num_len] = (n % base) + '0';
		n /= base;
	}
	return (ret);
}
