/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:48:57 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/20 14:48:58 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*new_str;

	if (!s || !f)
		return (0);
	index = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	while (s[index])
	{
		new_str[index] = f(s[index]);
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
