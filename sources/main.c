/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:58:09 by csinglet          #+#    #+#             */
/*   Updated: 2019/08/31 14:58:10 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

// 0x8eeffa

// #define vec3_sub(a, b)

t_xyz			vec3_multf(t_xyz a, float n)
{
	return ((t_xyz){a.x * n, a.y * n, a.z * n});
}

float			vec3_dot(t_xyz a, t_xyz b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_xyz			vec3_add(t_xyz a, t_xyz b)
{
	return ((t_xyz){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_xyz			vec3_sub(t_xyz a, t_xyz b)
{
	return ((t_xyz){a.x - b.x, a.y - b.y, a.z - b.z});
}

float			vec3_len(t_xyz v)
{
	float		value = (v.x * v.x + v.y * v.y + v.z * v.z);

	return (sqrtf(value));
}

int 			shade(float x, float y, float z, int color)
{
	float		ratio;
	int			r;
	int			g;
	int			b;

	ratio = (z - x) / (y - x);
	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = color & 0x0000FF;
	r *= ratio;
	g *= ratio;
	b *= ratio;
	return ((r << (8 * 2)) | (g << 8) | b);
}

int				render_loop(t_world *w)
{
	t_xyz		l;
	t_sphere	*s = (t_sphere *)w->objects->object;

	ft_bzero(w->image->buffer, w->image->image_length);
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	for (int i = 0; i < WIN_VRES; i++)
	{
		for (int j = 0; j < WIN_HRES; j++)
		{
			t_xyz uv = {j - WIN_HRES / 2, i - WIN_VRES / 2, 1};
			uv.x /= WIN_VRES;
			uv.y /= WIN_VRES;
			float l = vec3_len(uv);
			t_xyz rd = {uv.x / l, uv.y / l, uv.z / l};
			t_xyz ro = {0.0f, 0.0f, 0.0f};
			t_xyz so = s->pos;
			float t = vec3_dot(vec3_sub(so, ro), rd);
			t_xyz p = vec3_multf(vec3_add(ro, rd), t);
			float y = vec3_len(vec3_sub(so, p));
			if (y < s->radius)
			{
				float x = sqrtf(s->radius * s->radius - y * y);
				float t1 = t - x;
				float t2 = t + x;
				w->image->buffer[(int)(i * WIN_HRES + j)] = shade(so.z, so.z - s->radius, t1, w->objects->color);
			}
		}
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->image->ptr, 0, 0);
	return (0);
}

t_camera		*camera_init(void)
{
	t_camera	*c;

	if (!(c = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	c->direction.x = 0;
	c->direction.y = 1;
	c->pos.x = WIN_HRES / 2;
	c->pos.y = WIN_VRES / 2;
	c->pos.z = 0;
	return (c);
}

void			window_setup(void)
{
	t_world		w;

	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, WIN_HRES, WIN_VRES, "Hello");
	w.image = new_image(w.mlx_ptr, WIN_HRES, WIN_VRES);
	// w.camera = camera_init();
	w.background_color = 0;
	w.view_plane = (t_view_plane *)malloc(sizeof(t_view_plane));
	w.view_plane->hres = 200;
	w.view_plane->vres = 200;
	w.objects = (t_object *)malloc(sizeof(t_object));
	w.objects->object = (void *)&((t_sphere){(t_xyz){0.0f, 0.0f, 2.8f}, 1.0f});
	w.objects->color = 0x8eeffa;
	w.objects->light_absorption = 1.0f;
	w.objects->next = NULL;

	mlx_loop_hook(w.mlx_ptr, render_loop, &w);
	mlx_loop(w.mlx_ptr);
}

int				main(void)
{
	window_setup();
	return (0);
}
