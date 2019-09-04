/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:51:46 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/17 15:23:40 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int stop, size_t size)
{
	const unsigned char		*temp_src;
	unsigned char			*temp_dest;
	size_t					index;
	unsigned char			stop_cpy;

	temp_src = src;
	temp_dest = dest;
	index = 0;
	stop_cpy = stop;
	while (index < size)
	{
		if (temp_src[index] == stop_cpy)
		{
			*temp_dest = temp_src[index];
			temp_dest++;
			return (temp_dest);
		}
		*temp_dest = temp_src[index];
		temp_dest++;
		index++;
	}
	return (NULL);
}
