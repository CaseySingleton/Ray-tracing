/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:35:39 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 10:35:40 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		len;
	char	*new;

	len = ft_strlen(src);
	if (src == NULL || (new = ft_strnew(len)) == NULL)
		return (NULL);
	ft_memcpy(new, src, len);
	return (new);
}
