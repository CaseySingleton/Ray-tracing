/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:09:43 by csinglet          #+#    #+#             */
/*   Updated: 2019/09/11 18:09:44 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_xyz			vec3_new(float x, float y, float z)
{
	return ((t_xyz){x, y, z});
}

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
	if (b.x == 0.0f || b.y == 0.0f || b.z == 0.0f)
		return ((t_xyz){0.0f, 0.0f, 0.0f});
	return ((t_xyz){a.x / b.x, a.y / b.y, a.z / b.z});
}

t_xyz			vec3_divf(t_xyz a, float n)
{
	if (n == 0.0f)
		return ((t_xyz){0.0f, 0.0f, 0.0f});
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

t_xyz			vec3_to_unit(t_xyz v)
{
	float		len;

	len = vec3_len(v);
	return ((t_xyz){v.x / len, v.y / len, v.z / len});
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

/*
**	Vector reflcetion: v - 2 * dot(v, n) * n
*/
t_xyz			vec3_reflect(t_xyz v, t_xyz n)
{
	t_xyz		r;
	float		vn_dot;

	vn_dot = vec3_dot(v, n);
	r = vec3_multf(n, vn_dot);
	r = vec3_multf(r, 2.0f);
	vec3_sub(v, r);
	return (r);
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

int				vec3_to_color(t_xyz v)
{
	int			r;
	int			g;
	int			b;

	r = CLAMP(v.x * 255, 0, 255);
	g = CLAMP(v.y * 255, 0, 255);
	b = CLAMP(v.z * 255, 0, 255);
	return ((r << 16) | (g << 8) | b);
}
