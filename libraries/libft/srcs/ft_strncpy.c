/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:25:00 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 11:25:02 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t length)
{
	char		*dest_cpy;
	size_t		index;

	dest_cpy = dest;
	index = 0;
	while (index < length)
	{
		if (*src)
		{
			dest_cpy[index] = *src;
			src++;
		}
		else
			dest_cpy[index] = '\0';
		index++;
	}
	return (dest_cpy);
}
