/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:33:13 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 17:33:14 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		index;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len)
	{
		index = 0;
		while (haystack[index] == needle[index] && index <= len)
		{
			if (needle[index + 1] == '\0')
				return ((char *)haystack);
			index++;
		}
		haystack++;
		len--;
	}
	return (0);
}
