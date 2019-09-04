/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:43:37 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 10:43:38 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_cpy;

	dest_cpy = dest;
	while (*src != '\0')
	{
		*dest_cpy = *src;
		dest_cpy++;
		src++;
	}
	*dest_cpy = '\0';
	return (dest);
}
