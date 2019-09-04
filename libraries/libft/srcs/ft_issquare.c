/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:37:52 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/05 16:37:54 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_issquare(int num)
{
	int		test;

	test = 1;
	while (test * test < num)
	{
		if (test * test == num)
			return (1);
		test++;
	}
	return (0);
}
