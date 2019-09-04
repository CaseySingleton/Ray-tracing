/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:16:45 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/08 15:08:01 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	ncpy;

	len = ft_numlen(n);
	ncpy = n;
	if (n < 0)
		len++;
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		ncpy *= -1;
		str[0] = '-';
	}
	str[len--] = (ncpy % 10) + '0';
	while (ncpy /= 10)
		str[len--] = (ncpy % 10) + '0';
	return (str);
}
