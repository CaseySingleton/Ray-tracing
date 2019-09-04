/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:16:20 by csinglet          #+#    #+#             */
/*   Updated: 2018/12/14 14:16:35 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_lstdup(char **list)
{
	char		**list_cpy;
	int			i;

	i = -1;
	while (list[++i] != NULL)
		;
	if (!(list_cpy = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	list_cpy[i] = NULL;
	i = -1;
	while (list[++i] != NULL)
		list_cpy[i] = ft_strdup(list[i]);
	return (list_cpy);
}
