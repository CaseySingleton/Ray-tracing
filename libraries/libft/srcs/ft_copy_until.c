/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_until.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:12:34 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/28 17:12:59 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int				ft_copy_until(char **dest, char *src, int stop)
{
	int		len;

	len = -1;
	while (src[++len])
		if (src[len] == stop)
			break ;
	if (!(*dest = ft_strnew(len)))
		return (-1);
	*dest = (char *)ft_memcpy(*dest, src, len);
	return (len);
}
