/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_ascii.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 00:07:44 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/15 00:07:47 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_sort_list_ascii(char ***lst, int start, int stop)
{
	char		*temp;
	int			i;
	int			j;

	if (start == stop)
		return ;
	i = start - 1;
	while (++i < stop - 1)
	{
		j = start - 1;
		while (++j < stop - 1)
		{
			if (ft_ascii_cmp((*lst)[j], (*lst)[j + 1]) != 1)
			{
				temp = (*lst)[j];
				(*lst)[j] = (*lst)[j + 1];
				(*lst)[j + 1] = temp;
				temp = NULL;
			}
		}
	}
}
