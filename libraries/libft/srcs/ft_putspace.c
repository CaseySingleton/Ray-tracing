/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 22:12:31 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/30 22:16:22 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putspace(int num_spaces)
{
	char	spaces[1024];

	ft_memset(spaces, ' ', num_spaces);
	write(1, spaces, num_spaces);
}
