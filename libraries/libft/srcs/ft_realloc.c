/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:49:50 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/05 15:49:51 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, int size)
{
	char			*new;

	if (!(new = ft_strnew(size)))
		return (0);
	if (!ptr)
		return (new);
	ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}
