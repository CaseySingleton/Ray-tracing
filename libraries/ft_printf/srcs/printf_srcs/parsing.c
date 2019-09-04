/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 02:13:09 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/25 02:13:11 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		pleasing_the_norm(t_pf *pf)
{
	int			i;

	i = 1;
	while (specifier_check(pf->master[i]) != 1 && pf->master[i] != '\0')
	{
		if (pf->master[i] == '#')
			BIT_ON(pf->flags, F_PREFIX);
		if (flag_check(pf->master[i]) == 1)
			i = get_flags(pf, i);
		if (ft_isdigit(pf->master[i]) == 1)
			i = get_padding(pf, i);
		if (pf->master[i] == '.')
			i = get_precision(pf, i);
		if (pf->master[i] == ' ')
			BIT_ON(pf->flags, F_SPACE);
		if (pf->master[i] == '+')
			BIT_ON(pf->flags, F_PLUS);
		if (pf->master[i] == '-')
			BIT_ON(pf->flags, F_REV);
		if (specifier_check(pf->master[i]) != 1)
			i++;
	}
	return (i);
}

int				get_info(t_pf *pf)
{
	int			i;

	i = pleasing_the_norm(pf);
	if (pf->master[i] != '\0')
		pf->specifier = pf->master[i++];
	if (pf->count_spaces != i - 2 || (pf->specifier != 'd' &&
	pf->specifier != 'D' && pf->specifier != 'i'))
		pf->count_spaces = 0;
	return (i);
}

int				get_flags(t_pf *pf, int i)
{
	if (pf->master[i] == pf->master[i + 1])
	{
		BIT_ON(pf->flags, ((pf->master[i] == 'l') ? F_LL : F_HH));
		return (i + 2);
	}
	if (pf->master[i] == 'z')
		BIT_ON(pf->flags, F_Z);
	else if (pf->master[i] == 'j')
		BIT_ON(pf->flags, F_J);
	else if (pf->master[i] == 'l')
		BIT_ON(pf->flags, F_L);
	else if (pf->master[i] == 'h')
		BIT_ON(pf->flags, F_H);
	return (i + 1);
}

int				get_padding(t_pf *pf, int i)
{
	if (pf->master[i] == '0')
	{
		BIT_ON(pf->flags, F_PAD_ZEROS);
		i++;
	}
	if (ft_isdigit(pf->master[i]) == 1)
	{
		pf->padding = ft_atoi(pf->master + i);
		if (pf->padding < 0)
			i++;
		return (i += ft_numlen(ft_abs(pf->padding)));
	}
	else
		return (i);
}

/*
**	Precision value can not be negative. If the value is negative
**	an error occures
*/

int				get_precision(t_pf *pf, int i)
{
	if (pf->master[i] == '+')
		i++;
	if (ft_isdigit(pf->master[i + 1]) != 1)
	{
		pf->precision = 0;
		return (i);
	}
	i++;
	pf->precision = ft_atoi(pf->master + i);
	if (pf->precision < 0)
		pf->precision = 0;
	return (i += ft_numlen(pf->precision));
}

/*
**	%[char flags][num width][num .precision][num length] char specifier
**	Specifiers: sSpdDioOuUxXcC
*/
