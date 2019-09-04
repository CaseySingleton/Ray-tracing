/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:16:28 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/20 17:16:34 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_strnew(len);
	new_str[len] = '\0';
	i = -1;
	while (s1[++i] != '\0')
		new_str[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		new_str[i + j] = s2[j];
	return (new_str);
}
