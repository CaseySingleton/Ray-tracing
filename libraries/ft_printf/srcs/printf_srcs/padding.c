/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:00:22 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/21 16:00:23 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Padding will only show if the number to be padded is greater than the
**	length of the argument
**
**	ex:
**	  printf("|%3s|\n", "Hello 42!")   -> |Hello 42!|
**	  printf("|%-3s|\n", "Hello 42!")  -> |Hello 42!|
**	  printf("|%15s|\n", "Hello 42!")  -> |      Hello 42!|
**	  printf("|%-15s|\n", "Hello 42!") -> |Hello 42!      |
**
**	A positive value will place spaces to the right
**	A negative value will place spaces to the left
*/

static int		prefix_size(t_pf *pf)
{
	if (signed_specifier_check(pf->specifier))
		if (pf->flags & F_MINUS || pf->flags & F_PLUS)
			return (1);
	if (pf->flags & F_PREFIX)
	{
		if (pf->specifier == 'x' || pf->specifier == 'X' ||
		pf->specifier == 'p')
			return (2);
		if (pf->specifier == 'o')
			return (1);
	}
	return (0);
}

void			padding(t_pf *pf, int arglen)
{
	char		*pad;
	int			padding_len;

	pad = NULL;
	padding_len = pf->padding;
	if (pf->flags & F_PREFIX || pf->flags & F_MINUS || pf->flags & F_PLUS)
		padding_len -= prefix_size(pf);
	if (pf->flags & F_SPACE)
		padding_len--;
	if (pf->precision < arglen)
		padding_len -= arglen;
	else if (pf->precision >= arglen)
		padding_len -= pf->precision;
	if (padding_len > 0)
	{
		if (pf->flags & F_PAD_ZEROS && pf->flags & F_REV)
			BIT_OFF(pf->flags, F_PAD_ZEROS);
		pad = ft_strnew(padding_len);
		if (pf->flags & F_PAD_ZEROS && pf->precision <= 0)
			ft_memset(pad, '0', padding_len);
		else
			ft_memset(pad, ' ', padding_len);
		write_to_buffer(pf, pad, padding_len);
		free(pad);
	}
}

void			null_padding(t_pf *pf)
{
	char		*pad;

	pad = ft_strnew(pf->padding);
	ft_memset(pad, ' ', pf->padding);
	if (!(pf->flags & F_REV))
		write_to_buffer(pf, pad, pf->padding);
	if (pf->flags & F_PREFIX)
		get_prefix(pf);
	if (pf->flags & F_REV)
		write_to_buffer(pf, pad, pf->padding);
	free(pad);
}

void			handle_precision(char **str, t_pf *pf)
{
	int			len;
	char		*temp;

	len = pf->precision - ft_strlen(*str);
	temp = NULL;
	if (len > 0)
	{
		if (!(temp = ft_strnew(len)))
			return ;
		ft_memset(temp, '0', len);
		if ((pf->flags & F_MINUS) == 1)
			temp[0] = '-';
		write_to_buffer(pf, temp, len);
		free(temp);
	}
}

void			handle_padding(t_pf *pf, char **str)
{
	int			arglen;

	arglen = ft_strlen(*str);
	if (!(pf->flags & F_MINUS) && !(pf->flags & F_PLUS) &&
	ft_tolower(pf->specifier) != 'u')
		get_space(pf);
	if (pf->flags & F_PAD_ZEROS)
		get_prefix(pf);
	if (!(pf->flags & F_REV))
		padding(pf, arglen);
	if (!(pf->flags & F_PAD_ZEROS))
		get_prefix(pf);
	handle_precision(str, pf);
	write_to_buffer(pf, *str, arglen);
	if (pf->flags & F_REV)
		padding(pf, arglen);
}
