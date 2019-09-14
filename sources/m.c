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

// 0x8eeffa

// #define vec3_sub(a, b)

t_xyz			vec3_mult(t_xyz a, t_xyz b)
{
	return ((t_xyz){a.x * b.x, a.y * b.y, a.z * b.z});
}

t_xyz			vec3_multf(t_xyz a, float n)
{
	return ((t_xyz){a.x * n, a.y * n, a.z * n});
}

t_xyz			vec3_div(t_xyz a, t_xyz b)
{
	return ((t_xyz){a.x / b.x, a.y / b.y, a.z / b.z});
}

t_xyz			vec3_divf(t_xyz a, float n)
{
	return ((t_xyz){a.x / n, a.y / n, a.z / n});
}

t_xyz			vec3_add(t_xyz a, t_xyz b)
{
	return ((t_xyz){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_xyz			vec3_addf(t_xyz a, float n)
{
	return ((t_xyz){a.x + n, a.y + n, a.z + n});
}

t_xyz			vec3_sub(t_xyz a, t_xyz b)
{
	return ((t_xyz){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_xyz			vec3_subf(t_xyz a, float n)
{
	return ((t_xyz){a.x - n, a.y - n, a.z - n});
}

float			vec3_dot(t_xyz a, t_xyz b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float			vec3_len(t_xyz v)
{
	float		len = (v.x * v.x + v.y * v.y + v.z * v.z);

	return (sqrtf(len));
}

t_xyz			vec3_norm(t_xyz v)
{
	t_xyz		normalized;
	float		len;

	normalized = (t_xyz){0.0f, 0.0f, 0.0f};
	len = vec3_len(v);
	if (len > 0.0f)
	{
		len = 1 / len;
		normalized = (t_xyz){v.x * len, v.y * len, v.z * len};
	}
	return (normalized);
}

float			vec3_angle(t_xyz a, t_xyz b, t_xyz c)
{
	t_xyz		ab;
	t_xyz		bc;
	float		ab_len;
	float		bc_len;
	float		angle;

	ab = vec3_sub(b, a);
	bc = vec3_sub(c, b);
	ab_len = vec3_len(ab);
	bc_len = vec3_len(bc);
	angle = vec3_dot(ab, bc) / ab_len * bc_len;
	return (angle);
}

int				vec3_color(t_xyz v)
{
	int			r;
	int			g;
	int			b;

	// printf("color vector: (%f, %f, %f)\n", v.x, v.y, v.z);
	r = CLAMP(v.x * 255, 0, 255);
	g = CLAMP(v.y * 255, 0, 255);
	b = CLAMP(v.z * 255, 0, 255);
	// printf("rgb: (%d, %d, %d)\n", r, g, b);
	return ((r << 16) | (g << 8) | b);
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

t_intersect		intersect_init(void)
{
	float		len;
	t_xyz		normal;
	t_material	material;
	t_intersect	intersect;

	len = 0.0f;
	normal = (t_xyz){0.0f, 0.0f, 0.0f};
	material = (t_material){(t_xyz){0.0f, 0.0f, 0.0f}, 0.0f, 0.0f};
	intersect = (t_intersect){len, normal, material};
	return (intersect);
}

t_intersect		sphere_intersect(t_ray ray, t_sphere sphere)
{
	t_intersect	intersection;
	t_xyz		oc;
	float		l;
	float		det;
	float		len;

	oc = vec3_sub(sphere.position, ray.origin);
	l = vec3_dot(ray.direction, oc);
	det = l * l - vec3_dot(oc, oc) + sphere.radius * sphere.radius;
	intersection = intersect_init();
	// printf("det: %f\n", det);
	if (det >= 0.0f)
	{
		if ((len = 1 - sqrtf(det)) < 0.0f)
			len = 1 + sqrtf(det);
		if (len >= 0.0f)
		{
			intersection.len = len;
			intersection.normal = vec3_multf(ray.direction, len);
			intersection.normal = vec3_add(ray.origin, intersection.normal);
			intersection.normal = vec3_sub(intersection.normal, sphere.position);
			intersection.normal = vec3_divf(intersection.normal, sphere.radius);
			intersection.material = sphere.material;
		}
	}
	return (intersection);
}



t_intersect		plane_intersect(t_ray ray, t_plane plane)
{
	t_intersect	intersection;
	float		len;

	intersection = intersect_init();
	len = -vec3_dot(ray.origin, plane.normal) / vec3_dot(ray.direction, plane.normal);
	// printf("len: %f\n", len);
	if (len >= 0.0f)
	{
		intersection.len = len;
		intersection.normal = plane.normal;
		intersection.material = plane.material;
	}
	return (intersection);
}

t_intersect		trace(t_ray ray)
{
	const int	num_spheres = 3;
	t_sphere	spheres[num_spheres];
	t_plane		plane;
	t_intersect	intersection;
	t_intersect plane_intersection;
	t_intersect	sphere_intersection;

	spheres[0] = (t_sphere) {
		2.0f,
		(t_xyz) {-4.0f, 3.0f, 0.0f},
		(t_material) {
			(t_xyz) {1.0f, 0.0f, 0.2f},
			1.0f,
			0.001f
		}
	};
	spheres[1] = (t_sphere) {
		3.0f,
		(t_xyz) {4.0f, 3.0f, 0.0f},
		(t_material) {
			(t_xyz) {0.0f, 0.2f, 1.0f},
			1.0f,
			0.0f
		}
	};
	spheres[2] = (t_sphere) {
		1.0f,
		(t_xyz) {0.5f, 1.0f, -6.0f},
		(t_material) {
			(t_xyz) {1.0f, 1.0f, 1.0f},
			0.5f,
			0.25f
		}
	};
	plane = (t_plane) {
		(t_xyz) {0.0f, 4.0f, 0.0f},
		(t_material) {
			(t_xyz) {0.4f, 0.4f, 0.4f},
			1.0f,
			0.0f
		}
	};
	intersection = intersect_init();
	plane_intersection = plane_intersect(ray, plane);
	if (plane_intersection.material.diffuse > 0.0f || plane_intersection.material.specular > 0.0f)
		intersection = plane_intersection;
	for (int i = 0; i < num_spheres; i++)
	{
		sphere_intersection = sphere_intersect(ray, spheres[i]);
		if (sphere_intersection.material.diffuse > 0.0f || sphere_intersection.material.specular > 0.0f)
			intersection = sphere_intersection;
	}
	return (intersection);
}

int				is_hit(t_intersect v)
{
	if (v.len == 0.0f
		&& v.normal.x == 0.0f
		&& v.normal.y == 0.0f
		&& v.normal.z == 0.0f
		&& v.material.color.x == 0
		&& v.material.color.y == 0
		&& v.material.color.z == 0)
		return (0);
	return (1);
}

t_xyz			reflect(t_xyz a, t_xyz b)
{
	t_xyz		reflection;

	reflection = vec3_multf(b, 2.0f * vec3_dot(a, b));
	reflection = vec3_sub(a, reflection);
	return (reflection);
}

t_xyz			radiance(t_ray ray)
{
	t_light		light;
	t_intersect	hit;
	t_xyz		r0;
	float		hv;
	t_xyz		color;
	t_xyz		fresnel;
	t_xyz		mask;
	t_ray		r;

	light.color = (t_xyz){1.0f, 1.0f, 1.0f,};
	light.direction = (t_xyz){-1.0f, 0.75f, 1.0f};
	color = (t_xyz){0.0f, 0.0f, 0.0f};
	fresnel = (t_xyz){0.0f, 0.0f, 0.0f};
	mask = (t_xyz){1.0f, 1.0f, 1.0f};
	for (int i = 0; i < 1; i++)
	{
		hit = trace(ray);
		if (is_hit(hit) == 1)
		{
			// float angle = vec3_len(hit.normal) - vec3_len(light.direction);
			// printf("angle: %f\n", angle);
			// color = vec3_divf(hit.material.color, angle);
			// printf("Magnitude of hit.direction: %f\n", hit.len);
			color = hit.material.color;
		}
	}
	// printf("color vector: (%f, %f, %f)\n", color.x, color.y, color.z);
	return (color);
}

int					render_loop(t_world *w)
{
	t_ray			ray;
	t_xy			uv;

	ft_bzero(w->image->buffer, w->image->image_length);
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	ray.origin = (t_xyz){0.5f, 0.5f, 0.5f};
	for (float y = 0; y < WIN_VRES; y++)
	{
		for (float x = 0; x < WIN_HRES; x++)
		{
			uv = (t_xy){x / WIN_HRES - 0.5f, y / WIN_VRES - 0.5f};
			uv.x *= (float)WIN_HRES / (float)WIN_VRES;
			ray.direction = vec3_norm((t_xyz){uv.x, uv.y, -1.0f});
			pixel(w->image, x, y, vec3_color(radiance(ray)));
		}
	}
	ft_printf("Displaying image\n");
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->image->ptr, 0, 0);
	return (0);
}

// int				render_loop(t_world *w)
// {
// 	t_xyz		l;
// 	t_sphere	*s = (t_sphere *)w->objects->object;

// 	ft_bzero(w->image->buffer, w->image->image_length);
// 	mlx_clear_window(w->mlx_ptr, w->win_ptr);
// 	for (int i = 0; i < WIN_VRES; i++)
// 	{
// 		for (int j = 0; j < WIN_HRES; j++)
// 		{
// 			t_xyz uv = {j - WIN_HRES / 2, i - WIN_VRES / 2, 1};
// 			uv.x /= WIN_VRES;
// 			uv.y /= WIN_VRES;
// 			float l = vec3_len(uv);
// 			t_xyz rd = {uv.x / l, uv.y / l, uv.z / l};
// 			t_xyz ro = {0.0f, 0.0f, 0.0f};
// 			t_xyz so = s->position;
// 			float t = vec3_dot(vec3_sub(so, ro), rd);
// 			t_xyz p = vec3_multf(vec3_add(ro, rd), t);
// 			float y = vec3_len(vec3_sub(so, p));
// 			if (y < s->radius)
// 			{
// 				float x = sqrtf(s->radius * s->radius - y * y);
// 				float t1 = t - x;
// 				float t2 = t + x;
// 				w->image->buffer[(int)(i * WIN_HRES + j)] = shade(so.z, so.z - s->radius, t1, w->objects->color);
// 			}
// 		}
// 	}
// 	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->image->ptr, 0, 0);
// 	return (0);
// }

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
	w.objects->object = (void *)&((t_sphere){1.0f, (t_xyz){0.0f, 0.0f, 2.8f}, 1.0f, 0});
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
