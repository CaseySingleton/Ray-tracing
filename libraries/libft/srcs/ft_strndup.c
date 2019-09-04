/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:14:12 by csinglet          #+#    #+#             */
/*   Updated: 2018/11/09 23:20:36 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *src, size_t n)
{
	char		*new;
	int			i;

	if (!(new = ft_strnew(n)))
		return (NULL);
	i = -1;
	while (++i < (int)n)
		new[i] = src[i];
	return (new);
}
