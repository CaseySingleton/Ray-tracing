/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 08:56:34 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/28 17:41:41 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int waldo, size_t length)
{
	const unsigned char		*str_cpy;
	unsigned char			waldo_cpy;

	str_cpy = str;
	waldo_cpy = waldo;
	while (length)
	{
		if (*str_cpy == waldo_cpy)
		{
			return ((void *)str_cpy);
		}
		str_cpy++;
		length--;
	}
	return (NULL);
}
