/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:26:23 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 17:26:24 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		index;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		index = 0;
		while (haystack[index] == needle[index])
		{
			if (needle[index + 1] == '\0')
				return ((char *)haystack);
			index++;
		}
		haystack++;
	}
	return (NULL);
}
