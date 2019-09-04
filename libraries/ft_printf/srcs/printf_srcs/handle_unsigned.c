/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:05:55 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/30 16:05:56 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*get_unsigned_data_type(t_pf *pf, int base, int upper)
{
	uintmax_t	i;
	char		*ret;

	if ((pf->flags & F_H) && pf->specifier != 'U')
		i = ((uintmax_t)((unsigned short)va_arg(pf->arg, unsigned int)));
	else if ((pf->flags & F_L) || pf->specifier == 'U')
		i = ((uintmax_t)va_arg(pf->arg, unsigned long));
	else if (pf->flags & F_LL || pf->specifier == 'p')
		i = ((uintmax_t)va_arg(pf->arg, unsigned long long));
	else if (pf->flags & F_Z)
		i = ((uintmax_t)va_arg(pf->arg, size_t));
	else if (pf->flags & F_J)
		i = va_arg(pf->arg, uintmax_t);
	else
		i = (uintmax_t)va_arg(pf->arg, unsigned int);
	ret = ft_llutoa_base(i, base, upper);
	return (ret);
}

static int		get_base(t_pf *pf)
{
	int			base;

	base = 10;
	if (pf->specifier == 'x' || pf->specifier == 'X' || pf->specifier == 'p')
		base = 16;
	else if (pf->specifier == 'o' || pf->specifier == 'O')
		base = 8;
	return (base);
}

void			handle_unsigned(t_pf *pf)
{
	char		*ret;
	int			base;
	int			upper;

	base = get_base(pf);
	upper = ((pf->specifier == 'X') ? 1 : 0);
	ret = get_unsigned_data_type(pf, base, upper);
	if (pf->specifier == 'p')
		BIT_ON(pf->flags, F_PREFIX);
	if (ft_strcmp(ret, "0") == 0)
	{
		if (pf->specifier != 'p' && pf->specifier != 'o')
			BIT_OFF(pf->flags, F_PREFIX);
		if (pf->precision == 0)
		{
			null_padding(pf);
			free(ret);
			return ;
		}
		if (pf->specifier == 'o')
			BIT_OFF(pf->flags, F_PREFIX);
	}
	handle_padding(pf, &ret);
	free(ret);
}
