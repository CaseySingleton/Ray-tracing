/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:31:20 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/20 16:31:21 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	index;

	if (s == NULL || !(new_str = ft_strnew(len)))
		return (NULL);
	index = 0;
	while (index < len)
		new_str[index++] = s[start++];
	return (new_str);
}
