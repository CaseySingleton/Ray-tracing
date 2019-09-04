/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:05:35 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 17:05:36 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int waldo)
{
	while (*src)
	{
		if (*src == waldo)
			return ((char *)src);
		src++;
	}
	if (*src == waldo)
		return ((char *)src);
	return (NULL);
}
