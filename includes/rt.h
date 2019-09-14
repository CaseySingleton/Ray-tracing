/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:58:45 by csinglet          #+#    #+#             */
/*   Updated: 2019/08/31 14:58:45 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "draw.h"

# define WIN_HRES 800
# define WIN_VRES 400

# define SPHERE 1

// # define MIN(a, b) (a < b) ? a : b
// # define MAX(a, b) (a > b) ? a : b

typedef struct		s_light
{
	t_xyz			color;
	t_xyz			direction;
}					t_light;

typedef struct		s_material
{
	t_xyz			color;
	float			diffuse;
	float			specular;
}					t_material;

typedef struct		s_intersect
{
	float			len;
	t_xyz			normal;
	t_material		material;
}					t_intersect;

/*
**	3D primitives
*/

typedef struct		s_hit_list
{
	float			t;
	t_xyz			p;
	t_xyz			normal;
	t_xyz			material;
}					t_hit_list;

typedef struct		s_object
{
	int				object_type;
	void			*object;
	struct s_object	*next;
}					t_object;

typedef struct		s_plane
{
	t_xyz			normal;
	t_material		material;
}					t_plane;

typedef struct		s_sphere
{
	float			radius;
	t_xyz			position;
	t_material		material;
}					t_sphere;

typedef struct		s_view_plane
{
	int				hres;
	int				vres;
	float			pixel_size;
	float			gamma;
	float			inv_gamma;
}					t_view_plane;

typedef struct		s_world
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				background_color;
	t_image			*image;
	t_camera		*camera;
	t_view_plane	*view_plane;
	t_object		*objects;
	t_hit_list		*hit_list;
}					t_world;

/*
**	vector_math.c
*/

t_xyz				vec3_new(float x, float y, float z);
t_xyz				vec3_mult(t_xyz a, t_xyz b);
t_xyz				vec3_multf(t_xyz a, float n);
t_xyz				vec3_div(t_xyz a, t_xyz b);
t_xyz				vec3_divf(t_xyz a, float n);
t_xyz				vec3_add(t_xyz a, t_xyz b);
t_xyz				vec3_addf(t_xyz a, float n);
t_xyz				vec3_sub(t_xyz a, t_xyz b);
t_xyz				vec3_subf(t_xyz a, float n);
float				vec3_dot(t_xyz a, t_xyz b);
float				vec3_len(t_xyz v);
t_xyz				vec3_to_unit(t_xyz v);
t_xyz				vec3_norm(t_xyz v);
t_xyz				vec3_reflect(t_xyz v, t_xyz n);
float				vec3_angle(t_xyz a, t_xyz b, t_xyz c);
int					vec3_to_color(t_xyz v);

/*
**	ray.c
*/

t_ray				ray_new(t_xyz origin, t_xyz direction);
t_xyz				ray_at(t_ray r, float t);
t_xyz				ray_to_color(t_ray r);

/*
**	sphere.c
*/

t_sphere			sphere_new(t_xyz p, t_material m, float r);
// int					sphere_hit(t_sphere *s, t_ray *r, t_hit_list *h);
int					sphere_hit(t_sphere *s, t_ray *r, t_hit_list *h, float t_min, float t_max);
t_xyz				sphere_color(t_sphere *s, t_ray *r, float t);

/*
**	material.c
*/

#endif
