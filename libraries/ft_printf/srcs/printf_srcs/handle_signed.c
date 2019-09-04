/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:24:44 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/06 15:24:44 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*get_signed_data_type(t_pf *pf, int base, int upper)
{
	char		*ret;
	intmax_t	i;

	if (pf->flags & F_H)
		i = ((intmax_t)((short)va_arg(pf->arg, int)));
	else if (pf->flags & F_HH)
		i = ((intmax_t)((char)va_arg(pf->arg, int)));
	else if (pf->flags & F_L || pf->specifier == 'D')
		i = ((intmax_t)va_arg(pf->arg, long));
	else if (pf->flags & F_LL)
		i = ((intmax_t)va_arg(pf->arg, long long));
	else if (pf->flags & F_Z)
		i = ((intmax_t)va_arg(pf->arg, size_t));
	else if (pf->flags & F_J)
		i = va_arg(pf->arg, intmax_t);
	else
		i = ((intmax_t)va_arg(pf->arg, int));
	ret = ft_lltoa_base(i, base, upper);
	return (ret);
}

void			handle_signed(t_pf *pf)
{
	char		*ret;
	char		*temp;

	ret = get_signed_data_type(pf, 10, 0);
	if (ft_strcmp(ret, "0") == 0 && pf->precision == 0)
	{
		free(ret);
		ret = ft_strnew(0);
	}
	else if (ret[0] == '-')
	{
		BIT_ON(pf->flags, F_MINUS);
		BIT_OFF(pf->flags, F_PLUS);
		temp = ft_strdup(ret + 1);
		free(ret);
		ret = temp;
	}
	handle_padding(pf, &ret);
	free(ret);
}
