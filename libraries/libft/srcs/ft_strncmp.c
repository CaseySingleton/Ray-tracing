/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:41:50 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/19 11:41:52 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int diff;

	if (n == 0)
		return (0);
	if (*s1 == '\0' || *s2 == '\0')
		return (diff = *(unsigned char *)s1 - *(unsigned char *)s2);
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && (*s1 && *s2)
		&& --n > 0)
	{
		s1++;
		s2++;
	}
	return (diff = *(unsigned char *)s1 - *(unsigned char *)s2);
}
