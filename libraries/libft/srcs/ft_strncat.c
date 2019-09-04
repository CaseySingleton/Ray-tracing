/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:33:05 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 12:33:06 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *addition, size_t length)
{
	char	*dest_cpy;

	dest_cpy = dest;
	while (*dest_cpy)
		dest_cpy++;
	while (length--)
		if (!(*dest_cpy++ = *addition++))
			return (dest_cpy);
	*dest_cpy = '\0';
	return (dest);
}
