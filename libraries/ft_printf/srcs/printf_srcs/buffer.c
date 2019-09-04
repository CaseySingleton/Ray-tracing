/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:12:48 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/30 17:12:53 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_buffer(t_pf *pf, int bytes)
{
	write(1, pf->buffer, bytes);
	ft_bzero(pf->buffer, PF_BUFF_SIZE);
	pf->buffer_index = 0;
}

void			write_to_buffer(t_pf *pf, char *addition, int bytes)
{
	int			to_copy;

	if (addition == NULL || bytes == 0)
		return ;
	pf->total_bytes += bytes;
	while (PF_BUFF_SIZE - pf->buffer_index <= bytes)
	{
		to_copy = PF_BUFF_SIZE - pf->buffer_index;
		if (to_copy > 0)
		{
			ft_memcpy(pf->buffer + pf->buffer_index, addition, to_copy);
			bytes -= to_copy;
			addition += to_copy;
			pf->buffer_index += to_copy;
		}
		print_buffer(pf, pf->buffer_index);
	}
	if (bytes > 0)
		ft_memcpy(pf->buffer + pf->buffer_index, addition, bytes);
	pf->buffer_index += bytes;
}
