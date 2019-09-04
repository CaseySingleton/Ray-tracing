/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:44:19 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/19 09:44:20 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int diff;

	if (*s1 == '\0' || *s2 == '\0')
		return (diff = *(unsigned char *)s1 - *(unsigned char *)s2);
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && (*s1 && *s2))
	{
		s1++;
		s2++;
	}
	return (diff = *(unsigned char *)s1 - *(unsigned char *)s2);
}
