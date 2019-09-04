/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:01:16 by csinglet          #+#    #+#             */
/*   Updated: 2019/05/10 13:01:17 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		circle(t_image *image, t_xyz p, int radius, int color)
{
	int		x;
	int		y;
	int		error;

	x = radius;
	y = 0;
	error = 0;
	while (x >= y)
	{
		pixel(image, p.x + x, p.y + y, color);
		pixel(image, p.x + y, p.y + x, color);
		pixel(image, p.x - y, p.y + x, color);
		pixel(image, p.x - x, p.y + y, color);
		pixel(image, p.x - x, p.y - y, color);
		pixel(image, p.x - y, p.y - x, color);
		pixel(image, p.x + y, p.y - x, color);
		pixel(image, p.x + x, p.y - y, color);
		if (error <= 0)
			error += 2 * ++y + 1;
		if (error > 0)
			error -= 2 * --x + 1;
	}
}

void		ccircle(t_image *image, t_circle c, int color)
{
	int		x;
	int		y;
	int		error;

	x = c.radius;
	y = 0;
	error = 0;
	while (x >= y)
	{
		pixel(image, c.pos.x + x, c.pos.y + y, color);
		pixel(image, c.pos.x + y, c.pos.y + x, color);
		pixel(image, c.pos.x - y, c.pos.y + x, color);
		pixel(image, c.pos.x - x, c.pos.y + y, color);
		pixel(image, c.pos.x - x, c.pos.y - y, color);
		pixel(image, c.pos.x - y, c.pos.y - x, color);
		pixel(image, c.pos.x + y, c.pos.y - x, color);
		pixel(image, c.pos.x + x, c.pos.y - y, color);
		if (error <= 0)
			error += 2 * ++y + 1;
		if (error > 0)
			error -= 2 * --x + 1;
	}
}
