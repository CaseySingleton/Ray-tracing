/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 09:27:22 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 09:27:24 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t length)
{
	unsigned char	*str1_cpy;
	unsigned char	*str2_cpy;

	str1_cpy = (unsigned char *)str1;
	str2_cpy = (unsigned char *)str2;
	while (length--)
		if (*str1_cpy++ != *str2_cpy++)
			return (*(--str1_cpy) - *(--str2_cpy));
	return (0);
}
