/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_pptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 04:36:00 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/17 04:36:00 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_free_strsplit(char ***strings)
{
	int			i;

	i = -1;
	while ((*strings)[++i] != NULL)
		free((*strings)[i]);
	free(*strings);
}
