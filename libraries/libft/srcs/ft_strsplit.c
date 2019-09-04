/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 13:43:45 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/21 13:43:46 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordlen(char const *str, char c)
{
	int				len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**splits;
	int				word_count;
	int				i;
	int				j;

	if (s == NULL)
		return (NULL);
	word_count = ft_wrdcount(s, c);
	if (!(splits = (char **)malloc((sizeof(char *) * (word_count + 1)))))
		return (NULL);
	splits[word_count] = NULL;
	i = -1;
	j = 0;
	while (++i < word_count)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		splits[i] = ft_strsub(s + j, 0, ft_wordlen(s + j, c));
		j += ft_wordlen(s + j, c);
	}
	return (splits);
}
