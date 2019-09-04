/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:54:31 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/06 16:54:31 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int		flag_check(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int				signed_specifier_check(char c)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return (1);
	return (0);
}

int				unsigned_specifier_check(char c)
{
	if (c == 'p' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		c == 'x' || c == 'X')
		return (1);
	return (0);
}

int				ascii_specifier_check(char c)
{
	if (c == 's' || c == 'S' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

inline int		specifier_check(char c)
{
	if (ascii_specifier_check(c) || signed_specifier_check(c) ||
		unsigned_specifier_check(c))
		return (1);
	return (0);
}
