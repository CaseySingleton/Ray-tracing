/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:42:28 by csinglet          #+#    #+#             */
/*   Updated: 2019/09/12 18:42:28 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere		sphere_new(t_xyz p, t_material m, float r)
{
	t_sphere	s;

	s.position = p;
	s.material = m;
	s.radius = r;
	return (s);
}

/*
**	The below is taken from "Ray Tracing in a Weekend"
**
**	The equation for a sphere centered at the origin of radius ​R​ is:
**	​x*x + y*y + z*z = R*R
**
**	The way you can read that equation is “for any ​(x, y, z),​
**	if x​ *x + y*y + z*z = R*R​ then ​(x,y,z)​ is on the sphere and otherwise it
**	is not”
**
**	The equation of the sphere in vector form is: dot((p​ ​-c​ )​,(p​ ​-​c​))=R*R
**	We can read this as “any point p that satisfies this equation is on the sphere”
**
**	If it does hit the sphere, there is ​some​ ​t for which ​p(​ t)​ satisfies the
**	sphere equation. So we are looking for any ​t​ where this is true:
**	dot((p​ ​(t) - c​ )​ ,(p​ (​ t) - ​c​)) = R*R or expanding the full form of the ray 
**	p(​ t) ​: d o t ( ( A​ ​ + t * ​ B ​ - ​ C ) ​ , ( A​ ​ + t * B​ ​ - C​ ​ ) ) = R * R
**
**	The rules of vector algebra are all that we would want here, and if we
**	expand that equation and move all the terms to the left hand side we get:
**	t*t*dot(B​ ,​ B​ )​ + 2*t*dot(B​ ,A-​ ​C​) + dot(A​ -C,A​-​C​) - R*R = 0
*/

int				sphere_hit(t_sphere *s, t_ray *r, t_hit_list *h, float t_min, float t_max)
{
	t_xyz		oc;
	float		a;
	float		b;
	float		c;
	float		discriminant;
	float		temp;

	oc = vec3_sub(r->origin, s->position);
	a = vec3_dot(r->direction, r->direction);
	b = vec3_dot(oc, r->direction);
	c = vec3_dot(oc, oc) - s->radius * s->radius;
	discriminant = b * b - a * c;
	if (discriminant > 0.0f)
	{
		temp = (-b - sqrtf(b * b - a * c)) / a;
		if (t_min < temp && temp < t_max)
		{
			h->t = temp;
			h->p = ray_at(*r, h->t);
			h->normal = vec3_divf(vec3_sub(h->p, s->position), s->radius);
			return (1);
		}
		temp = (-b + sqrtf(b * b - a * c)) / a;
		if (t_min < temp && temp < t_max)
		{
			h->t = temp;
			h->p = ray_at(*r, h->t);
			h->normal = vec3_divf(vec3_sub(h->p, s->position), s->radius);
			return (1);
		}
	}
	return (0);
}

t_xyz			sphere_color(t_sphere *s, t_ray *r, float t)
{
	t_xyz		n;

	n = vec3_to_unit(vec3_sub(ray_at(*r, t), vec3_new(0.0f, 0.0f, -1.0f)));
	return (vec3_multf(vec3_addf(n, 1.0f), 0.5f));
}
