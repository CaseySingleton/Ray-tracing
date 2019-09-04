/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:37:37 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/30 14:14:19 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc_str(char *str, size_t size)
{
	char	*new;

	if (!str)
	{
		new = ft_strnew(size);
		return (new);
	}
	if (!(new = ft_strnew(size + ft_strlen(str))))
		return (NULL);
	ft_memcpy(new, str, ft_strlen(str));
	free(str);
	str = NULL;
	return (new);
}
