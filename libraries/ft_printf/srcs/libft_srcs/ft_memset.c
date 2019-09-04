/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:06:03 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/16 11:06:08 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t length)
{
	char		*str;
	size_t		index;

	str = ptr;
	index = 0;
	while (index < length)
		str[index++] = (unsigned char)value;
	return (ptr);
}
