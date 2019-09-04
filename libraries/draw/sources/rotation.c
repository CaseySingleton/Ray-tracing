/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:41:10 by csinglet          #+#    #+#             */
/*   Updated: 2018/06/25 19:41:11 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		matrix_rotx_init(float matrix[4][4], float x)
{
	matrix_clear(matrix);
	matrix[0][0] = 1;
	matrix[1][1] = cos(x);
	matrix[1][2] = -sin(x);
	matrix[2][1] = sin(x);
	matrix[2][2] = cos(x);
	matrix[3][3] = 1;
}

void		matrix_roty_init(float matrix[4][4], float y)
{
	matrix_clear(matrix);
	matrix[0][0] = cos(y);
	matrix[0][2] = sin(y);
	matrix[1][1] = 1;
	matrix[2][0] = -sin(y);
	matrix[2][2] = cos(y);
	matrix[3][3] = 1;
}

void		matrix_rotz_init(float matrix[4][4], float z)
{
	matrix_clear(matrix);
	matrix[0][0] = cos(z);
	matrix[0][1] = -sin(z);
	matrix[1][0] = sin(z);
	matrix[1][1] = cos(z);
	matrix[2][2] = 1;
	matrix[3][3] = 1;
}

void		matrix_rotall(float matrix[4][4], float x, float y, float z)
{
	float	rotx[4][4];
	float	roty[4][4];
	float	rotz[4][4];
	float	temp1[4][4];
	float	temp2[4][4];

	matrix_rotx_init(rotx, x);
	matrix_roty_init(roty, y);
	matrix_rotz_init(rotz, z);
	matrix_multiply(temp1, rotx, matrix);
	matrix_multiply(temp2, roty, temp1);
	matrix_multiply(matrix, rotz, temp2);
}
