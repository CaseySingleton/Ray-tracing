/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:21:03 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 17:21:04 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int waldo)
{
	const char	*waldo_loc;

	waldo_loc = 0;
	while (*src)
	{
		if (*src == waldo)
			waldo_loc = src;
		src++;
	}
	if (*src == waldo)
		return ((char *)src);
	else if (waldo_loc != 0)
		return ((char *)waldo_loc);
	return (0);
}
