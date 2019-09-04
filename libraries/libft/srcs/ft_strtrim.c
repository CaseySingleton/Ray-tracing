/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:29:34 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/20 17:29:34 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

char				*ft_strtrim(char const *s)
{
	char			*trim;
	int				start;
	int				end;
	int				i;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (is_space(s[start]) == 1 && s[start] != '\0')
		start++;
	end = ft_strlen(s);
	while (is_space(s[end - 1]) == 1 && end >= start)
		end--;
	if (!(trim = ft_strnew(end - start)))
		return (NULL);
	i = 0;
	while (start < end)
	{
		trim[i] = s[start];
		i++;
		start++;
	}
	return (trim);
}
