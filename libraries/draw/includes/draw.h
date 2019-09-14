/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:59:55 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/26 21:59:56 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "mlx.h"

# define NUMBER_OF_THREADS 100

# define MIN(a, b) ((a < b) ? a : b)
# define MAX(a, b) ((a > b) ? a : b)
# define CLAMP(n, min, max) MIN(MAX(n, min), max)

# define VXP(x1, y1, x2, y2) ((x1 * y2) - (x2 * y1))

# define OVERLAP(a0, a1, b0, b1)	(MIN(a0, a1) <= (MAX(b0, b1)) && MIN(b0, b1) <= MAX(a0, a1))
# define INTERSECT_BOX(x0,y0, x1,y1, x2,y2, x3,y3)	(OVERLAP(x0,x1,x2,x3) && OVERLAP(y0,y1,y2,y3))
# define POINT_SIZE(px,py, x0,y0, x1,y1)	VXP((x1)-(x0), (y1)-(y0), (px)-(x0), (py)-(y0))
/*
**	#define Intersect(x1,y1, x2,y2, x3,y3, x4,y4) ((struct xy) { \
**	vxs(vxs(x1,y1, x2,y2), (x1)-(x2), vxs(x3,y3, x4,y4), (x3)-(x4)) / vxs((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4)), \
**	vxs(vxs(x1,y1, x2,y2), (y1)-(y2), vxs(x3,y3, x4,y4), (y3)-(y4)) / vxs((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4)) })
*/
# define ANGLE	M_PI / 64

typedef struct		s_image
{
	void			*ptr;
	int				*buffer;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				image_length;
	int				endian;
}					t_image;

typedef struct		s_bresline
{
	float			diff_x;
	float			diff_y;
	float			diff_z;
	float			slope;
	float			error;
}					t_bresline;

typedef struct		s_xy
{
	float			x;
	float			y;
}					t_xy;

typedef struct		s_xyz
{
	float			x;
	float			y;
	float			z;
}					t_xyz;

typedef struct		s_line
{
	t_xyz			p1;
	t_xyz			p2;
}					t_line;

typedef struct		s_ray
{
	t_xyz			origin;
	t_xyz			direction;

}					t_ray;

/*
**	2D primitives
*/

typedef struct		s_circle
{
	t_xyz			pos;
	float			radius;
}					t_circle;

typedef struct		s_rectangle
{
	t_xyz			pos;
	float			width;
	float			height;
}					t_rectangle;

typedef struct		s_cube
{
	t_xyz			pos;
	float			width;
	float			height;
	float			depth;
}					t_cube;

typedef struct		s_gfx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			*image;
}					t_gfx;

typedef struct		s_camera
{
	t_xyz			pos;
	t_xyz			direction;
}					t_camera;

/*
**	line.c
*/

void				pixel(t_image *image, int x, int y, int color);
void				line(t_image *image, t_xyz p1, t_xyz p2, int color);
void				lline(t_image *image, t_line l, int color);

/*
**	circle.c
*/

void				circle(t_image *image, t_xyz point, int radius, int color);
void				ccircle(t_image *image, t_circle c, int color);

/*
**	sphere.c
*/

// void				sphere(t_image *image, t_sphere *s);

/*
**	image.c
*/

t_image				*new_image(void *mlx, int width, int height);

/*
**	rotation.c
*/

void				matrix_rotx_init(float matrix[4][4], float x);
void				matrix_roty_init(float matrix[4][4], float x);
void				matrix_rotz_init(float matrix[4][4], float z);
void				matrix_rotall(float matrix[4][4], float x, float y, float z);

/*
**	matrix.c
*/

void				matrix_init(float matrix[4][4], float x, float y, float z);
void				matrix_clear(float matrix[4][4]);
void				matrix_multiply(float dst[4][4], float m1[4][4], float m2[4][4]);
void				matrix_translate(float matrix[4][4], float x, float y, float z);
void				matrix_set_scale(float matrix[4][4], float x, float y, float z);

/*
**	vector.c
*/

void				vector_init(t_xyz *v, float x, float y, float z);
void				vector_matrix_multi(t_xyz *vd, float m[4][4], t_xyz *vs);
void				vector_translate(t_xyz *v, float x, float y, float z);
void				vector_rotate_around_p2(t_xyz *p1, t_xyz p2, float z);
void				cross_product(t_xyz a, t_xyz b, t_xyz *c);
void				vector_rotate_xyz(t_xyz *v, float x, float y, float z);

#endif
