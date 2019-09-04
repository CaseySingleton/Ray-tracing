/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:27:51 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/26 21:27:51 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void			pixel(t_image *image, int x, int y, int color)
{
	int			location;

	location = x + (y * image->width);
	if (location < image->width * image->height)
		image->buffer[location] = color;
}

static int		swap_value(t_xyz *p1, t_xyz *p2)
{
	int			temp;

	temp = 0;
	if (fabs(p2->x - p1->x) > fabs(p2->y - p1->y))
		return (0);
	temp = p1->x;
	p1->x = p1->y;
	p1->y = temp;
	temp = p2->y;
	p2->y = p2->x;
	p2->x = temp;
	return (1);
}

void			line(t_image *image, t_xyz p1, t_xyz p2, int color)
{
	t_bresline	line;
	int			swap;

	swap = swap_value(&p1, &p2);
	line.diff_x = p2.x - p1.x;
	line.diff_y = p2.y - p1.y;
	line.diff_z = p2.z - p1.z;
	line.slope = fabs(line.diff_y / line.diff_x);
	line.error = -1.0f;
	while ((int)p1.x != (int)p2.x)
	{
		pixel(image, swap ? p1.y : p1.x, swap ? p1.x : p1.y, color);
		line.error += line.slope;
		if ((int)line.error >= 0)
		{
			p1.y += (p1.y > p2.y) ? -1 : 1;
			line.error -= 1;
		}
		p1.z += line.diff_z / fabs(line.diff_x);
		p1.x += (p1.x > p2.x) ? -1 : 1;
	}
	pixel(image, swap ? p1.y : p1.x, swap ? p1.x : p1.y, color);
}

void			lline(t_image *image, t_line l, int color)
{
	t_bresline	line;
	int			swap;

	swap = swap_value(&l.p1, &l.p2);
	line.diff_x = l.p2.x - l.p1.x;
	line.diff_y = l.p2.y - l.p1.y;
	line.diff_z = l.p2.z - l.p1.z;
	line.slope = fabs(line.diff_y / line.diff_x);
	line.error = -1.0f;
	while (floor(l.p1.x) != floor(l.p2.x))
	{
		pixel(image, swap ? l.p1.y : l.p1.x, swap ? l.p1.x : l.p1.y, color);
		line.error += line.slope;
		if (floor(line.error) >= 0)
		{
			l.p1.y += (l.p1.y > l.p2.y) ? -1 : 1;
			line.error -= 1;
		}
		l.p1.z += line.diff_z / fabs(line.diff_x);
		l.p1.x += (l.p1.x > l.p2.x) ? -1 : 1;
	}
}
