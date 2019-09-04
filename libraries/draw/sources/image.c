/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:50:09 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/26 22:50:10 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_image			*new_image(void *mlx, int width, int height)
{
	t_image		*i;

	if (!(i = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	i->ptr = mlx_new_image(mlx, width, height);
	i->buffer = (int *)mlx_get_data_addr(i->ptr, &(i->bits_per_pixel),
		&(i->image_length), &(i->endian));
	i->width = width;
	i->height = height;
	return (i);
}
