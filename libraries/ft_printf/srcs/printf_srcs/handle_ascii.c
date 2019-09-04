/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:23:27 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/25 14:23:28 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					handle_str(t_pf *pf)
{
	char				*temp;
	char				*ret;
	int					len;

	temp = va_arg(pf->arg, char *);
	len = ft_strlen(temp);
	ret = NULL;
	if (temp == NULL)
		ret = ft_strdup("(null)");
	else if (len == 0)
		null_padding(pf);
	else if (pf->precision > 0 && pf->precision < len)
		ret = ft_strndup(temp, pf->precision);
	else
		ret = ft_strdup(temp);
	pf->precision = 0;
	BIT_OFF(pf->flags, F_PAD_ZEROS);
	if (len > 0 || temp == NULL)
		handle_padding(pf, &ret);
	if (ret)
		free(ret);
}

void					handle_char(t_pf *pf)
{
	unsigned int		c;
	int					num_bytes;
	char				*ret;

	ret = NULL;
	c = va_arg(pf->arg, unsigned int);
	num_bytes = wchar_size(c);
	if (c == 0)
	{
		if (pf->padding >= 1)
			pf->padding -= 1;
		if (!(pf->flags & F_REV))
			null_padding(pf);
		write_to_buffer(pf, "\0", 1);
		if (pf->flags & F_REV)
			null_padding(pf);
		return ;
	}
	else
	{
		ret = ft_strnew(1);
		*ret = c;
	}
	handle_padding(pf, &ret);
	free(ret);
}

void					handle_percent(t_pf *pf)
{
	if (!(pf->flags & F_REV))
		padding(pf, 1);
	write_to_buffer(pf, "%", 1);
	if (pf->flags & F_REV)
		padding(pf, 1);
}

void					handle_ascii(t_pf *pf)
{
	if (pf->specifier == 's')
		handle_str(pf);
	else if (pf->specifier == 'S')
		handle_wide_str(pf);
	else if (pf->specifier == 'c')
		handle_char(pf);
	else if (pf->specifier == 'C')
		handle_wide_char(pf);
	else if (pf->specifier == '%')
		handle_percent(pf);
}
