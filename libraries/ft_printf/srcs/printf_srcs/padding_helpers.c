/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:42:32 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/19 19:42:32 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_prefix(t_pf *pf)
{
	if (signed_specifier_check(pf->specifier))
	{
		if (pf->flags & F_MINUS)
			write_to_buffer(pf, "-", 1);
		else if (pf->flags & F_PLUS)
			write_to_buffer(pf, "+", 1);
	}
	else if (pf->flags & F_PREFIX)
	{
		if (pf->specifier == 'x' || pf->specifier == 'p')
			write_to_buffer(pf, "0x", 2);
		else if (pf->specifier == 'X')
			write_to_buffer(pf, "0X", 2);
		else if (pf->specifier == 'o')
			write_to_buffer(pf, "0", 1);
	}
}

void			get_space(t_pf *pf)
{
	if (pf->flags & F_SPACE)
		write_to_buffer(pf, " ", 1);
}
