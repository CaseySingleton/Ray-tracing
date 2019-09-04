/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:46:12 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/17 14:14:24 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*dest_cpy;
	char	*src_cpy;

	dest_cpy = (char *)dest;
	src_cpy = (char *)src;
	if (src < dest)
		while (len--)
			dest_cpy[len] = src_cpy[len];
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
