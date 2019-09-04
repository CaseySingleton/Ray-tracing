/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:02:51 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/27 13:02:52 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		vector_init(t_xyz *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void		vector_matrix_multi(t_xyz *vd, float m[4][4], t_xyz *vs)
{
	float	x;
	float	y;
	float	z;

	x = vs->x * m[0][0] + vs->y * m[0][1] + vs->z * m[0][2] + m[0][3];
	y = vs->x * m[1][0] + vs->y * m[1][1] + vs->z * m[1][2] + m[1][3];
	z = vs->x * m[2][0] + vs->y * m[2][1] + vs->z * m[2][2] + m[2][3];
	vd->x = x;
	vd->y = y;
	vd->z = z;
}

void		vector_translate(t_xyz *v, float x, float y, float z)
{
	float	m[4][4];

	matrix_init(m, 1, 1, 1);
	matrix_translate(m, x, y, z);
	vector_matrix_multi(v, m, v);
}

void		scale_vector(t_xyz *v, float x, float y, float z)
{
	float	m[4][4];

	matrix_set_scale(m, x, y, z);
	vector_matrix_multi(v, m, v);
}

void		vector_rotate_around_p2(t_xyz *p1, t_xyz p2, float z)
{
	float	m[4][4];
	float	rx;
	float	ry;

	rx = p2.x;
	ry = p2.y;
	matrix_rotz_init(m, z);
	vector_translate(p1, -rx, -ry, 0);
	vector_matrix_multi(p1, m, p1);
	vector_translate(p1, rx, ry, 0);
}

void		vector_rotate_xyz(t_xyz *v, float x, float y, float z)
{
	float	mat[4][4];
	float	vx;
	float	vy;
	float	vz;

	vx = v->x;
	vy = v->y;
	vz = v->z;
	matrix_init(mat, 1, 1, 1);
	matrix_rotall(mat, x, y, z);
	vector_translate(v, -vx, -vy, 0);
	vector_matrix_multi(v, mat, v);
	vector_translate(v, vx, vy, vz);
}
