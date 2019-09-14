/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:08:55 by csinglet          #+#    #+#             */
/*   Updated: 2019/09/12 18:08:56 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray			ray_new(t_xyz origin, t_xyz direction)
{
	return ((t_ray){origin, direction});
}

/*
**	The ray_at() functions moves a ray along the line determined by its
**	direction.
**	In terms of mathmatics: p(t) = A + tB where t is a real number,
**	A is the rays origin, and B is the rays direction.
*/
t_xyz			ray_at(t_ray r, float t)
{
	return (vec3_add(r.origin, vec3_multf(r.direction, t)));
}

/*
**	A lerp is always of the form: 
**	blended_value = (1-t)*start_value + t*end_value,​ with t going from 0 to 1
*/
t_xyz			ray_to_color(t_ray r)
{
	t_xyz		unit_direction;
	t_xyz		ratio_vector;
	t_xyz		base_colors;
	float		t;

	unit_direction = vec3_to_unit(r.direction);
	ratio_vector = vec3_new(1.0f, 1.0f, 1.0f);
	base_colors = vec3_new(0.5f, 0.7f, 1.0f);
	t = 0.5f * (unit_direction.y + 1.0f);
	return (vec3_add(vec3_multf(ratio_vector, 1.0f - t), vec3_multf(base_colors, t)));
}
