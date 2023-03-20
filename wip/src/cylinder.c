/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:41:35 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/19 16:36:00 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	sphere_p_n(t_data *type)
{
	t_vector produit;

	produit = vector_scal(type->objet->t, type->ray.direction);
	type->objet->point = vector_add(type->ray.origin, produit);
	type->objet->normal = vector_sub(type->objet->point, type->objet->pos);
	type->objet->normal = unit_vector(type->objet->normal);
}

void	plane_p_n(t_data *type)
{
	double		a;
	t_vector	produit;

	a = vector_dot(type->ray.direction, type->objet->v);
	produit = vector_scal(type->objet->t, type->ray.direction);
	type->objet->point = vector_add(type->ray.origin, produit);
	type->objet->normal = type->objet->v;
	if (a > 0)
		type->objet->normal = vector_scal(-1, type->objet->normal);
}

void	cylinder_p_n(t_data *type)
{
	double		m;
	t_vector	x;
	t_vector	sub;
	t_vector	scal;
	t_vector	produit;

	type->objet->v = unit_vector(type->objet->v);
	produit = vector_scal(type->objet->t, type->ray.direction);
	type->objet->point = vector_add(type->ray.origin, produit);
	x = vector_sub(type->ray.origin, type->objet->pos);
	m = vector_dot(type->ray.direction, type->objet->v) *\
		type->objet->t + vector_dot(x, type->objet->v);
	sub = vector_sub(type->objet->point, type->objet->pos);
	scal = vector_scal(m, type->objet->v);
	type->objet->normal = vector_sub(sub, scal);
	if (vector_dot(type->ray.direction, type->objet->normal) > 0.000)
		type->objet->normal = vector_scal(-1, type->objet->normal);
	type->objet->normal = unit_vector(type->objet->normal);
}

void		calcul_delta_cy(t_objet *objet, t_ray *ray, t_varcal *var)
{
	var->oc = vector_sub(ray->origin, objet->pos);
	var->a = vector_dot(ray->direction, ray->direction) -\
	(vector_dot(ray->direction, objet->v)\
	* vector_dot(ray->direction, objet->v));
	var->b = 2 * (vector_dot(ray->direction, var->oc) -\
	(vector_dot(ray->direction, objet->v) *\
	vector_dot(var->oc, objet->v)));
	var->c = vector_dot(var->oc, var->oc)\
	- (vector_dot(var->oc, objet->v) * vector_dot(var->oc, objet->v))\
	- (objet->radius * objet->radius);
	var->delta = var->b * var->b - 4 * var->a * var->c;
}
