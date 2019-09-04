/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:46:21 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 11:46:23 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *addition)
{
	char	*dest_cpy;

	dest_cpy = dest;
	while (*dest_cpy)
		dest_cpy++;
	ft_strcpy(dest_cpy, addition);
	return (dest);
}
