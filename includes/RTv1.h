/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:58:45 by csinglet          #+#    #+#             */
/*   Updated: 2019/08/31 14:58:45 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "draw.h"

# define WIN_HRES 900
# define WIN_VRES 600

typedef struct		s_view_plane
{
	int				hres;
	int				vres;
	float			pixel_size;
	float			gamma;
	float			inv_gamma;
}					t_view_plane;

typedef struct		s_object
{
	char			*object_type;
	float			light_absorption;
	int				color;
	void			*object;
	struct s_object	*next;
}					t_object;

typedef struct		s_world
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				background_color;
	t_image			*image;
	t_camera		*camera;
	t_view_plane	*view_plane;
	t_object		*objects;
}					t_world;

#endif
