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

#include <time.h>
#include <sys/time.h>
#include "rt.h"

t_object		*create_scene_objects(void)
{
	t_object	*o;
	t_sphere	*s1;
	t_sphere	*s2;
	t_sphere	*s3;

	if (!(o = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	if (!(o->next = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	if (!(o->next->next = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	if (!(s1 = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	if (!(s2 = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	if (!(s3 = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);

	s1->position = vec3_new(0.0f, 0.0f, -1.0f);
	s1->radius = 0.5f;
	s2->position = vec3_new(0.0f, -100.5f, -1.0f);
	s2->radius = 100.0f;
	s3->position = vec3_new(-1.0f, 0.0f, -1.0f);
	s3->radius = 0.5f;

	o->object_type = SPHERE;
	o->object = s1;
	o->next->object_type = SPHERE;
	o->next->object = s2;
	o->next->next->object_type = SPHERE;
	o->next->next->object = s3;
	o->next->next->next = NULL;
	return (o);
}

int					hit(t_object *objects, t_ray *r, t_hit_list *h, float t_min, float t_max)
{
	t_object		*o;
	t_hit_list		temp_h;
	float			closest;
	int				hit_anything;

	o = objects;
	hit_anything = 0;
	closest = t_max;
	while (o != NULL)
	{
		if (o->object_type == SPHERE && sphere_hit((t_sphere *)(o->object), r, &temp_h, t_min, closest) == 1)
		{
			hit_anything = 1;
			closest = temp_h.t;
			h->normal = temp_h.normal;
			h->t = temp_h.t;
			h->p = temp_h.p;
		}
		o = o->next;
	}
	return (hit_anything);
}

t_xyz			random_in_unit_sphere(void)
{
	t_xyz		p;

	p = vec3_sub(vec3_multf(vec3_new(drand48(), drand48(), drand48()), 2.0f), vec3_new(1.0f, 1.0f, 1.0f));
	while (p.x * p.x + p.y * p.y + p.z * p.z >= 1.0f)
	{
		p = vec3_sub(vec3_multf(vec3_new(drand48(), drand48(), drand48()), 2.0f), vec3_new(1.0f, 1.0f, 1.0f));
	}
	return (p);
}

t_xyz			get_color(t_object *objects, t_ray *r)
{
	t_hit_list	hit_list;
	t_xyz		unit_direction;
	t_xyz		ratios;
	t_xyz		colors;
	float		t;

	ft_bzero(&hit_list, sizeof(t_hit_list));
	ratios = vec3_new(1.0f, 1.0f, 1.0f);
	colors = vec3_new(0.5f, 0.7f, 1.0f);
	if (hit(objects, r, &hit_list, 0.001f, MAXFLOAT) == 1)
	{
		t_xyz target = vec3_add(hit_list.p, hit_list.normal);
		target = vec3_add(target, random_in_unit_sphere());
		t_ray nr = ray_new(hit_list.p, vec3_sub(target, hit_list.p));
		return (vec3_multf(get_color(objects, &nr), 0.5f));
	}
	unit_direction = vec3_to_unit(r->direction);
	t = 0.5f * (unit_direction.y + 1.0f);
	return (vec3_add(vec3_multf(ratios, (1.0f - t)), vec3_multf(colors, t)));
}

int					render_loop(t_world *w)
{
	t_ray			ray;
	t_xy			uv;
	t_xyz			color;
	t_object		*objects;

	ft_bzero(w->image->buffer, w->image->image_length);
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	ray.origin = vec3_new(0.0f, 0.0f, 0.0f);
	objects = create_scene_objects();
	for (int y = WIN_VRES - 1; y >= 0; y--)
	{
		for (int x = 0; x < WIN_HRES; x++)
		{
			color.x = 0.0f;
			color.y = 0.0f;
			color.z = 0.0f;
			for (int j = 0; j < 100; j++)
			{
				uv.x = ((float)x + drand48()) / (float)WIN_HRES;
				uv.y = ((float)y + drand48()) / (float)WIN_VRES;
				ray.direction = vec3_new(-2.0f + uv.x * 4.0f, -1.0 + uv.y * 2.0f, -1.0f);
				color = vec3_add(color, get_color(objects, &ray));
			}
			color = vec3_divf(color, 100.0f);
			color = vec3_new(sqrtf(color.x), sqrtf(color.y), sqrtf(color.z));
			pixel(w->image, x, WIN_VRES - 1 - y, vec3_to_color(color));
		}
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->image->ptr, 0, 0);
	return (0);
}

void			window_setup(void)
{
	t_world		w;

	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, WIN_HRES, WIN_VRES, "Hello");
	w.image = new_image(w.mlx_ptr, WIN_HRES, WIN_VRES);
	mlx_loop_hook(w.mlx_ptr, render_loop, &w);
	mlx_loop(w.mlx_ptr);
}

int				main(void)
{
	window_setup();
	return (0);
}
