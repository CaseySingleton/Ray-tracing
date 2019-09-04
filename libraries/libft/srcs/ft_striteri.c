/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 12:51:48 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/20 12:51:49 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	index;
	unsigned int	size;

	index = 0;
	if (str && f)
	{
		size = ft_strlen(str);
		while (index < size)
		{
			f(index, str + index);
			index++;
		}
	}
}
