/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:02:57 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/20 16:02:58 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		index;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	index = 0;
	if (!(new_str = (char *)malloc(size + 1)))
		return (NULL);
	while (index < size)
	{
		new_str[index] = f(index, s[index]);
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
