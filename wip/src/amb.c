/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:50:23 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/19 16:33:45 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

static t_colour	ft_ambient(t_data *type)
{
	t_colour ambient;
	t_colour scal;

	scal = colour_scal(type->ambient.int_amb, type->ambient.rgb_amb);
	ambient.r = type->objet->colour.r * scal.r;
	ambient.g = type->objet->colour.g * scal.g;
	ambient.b = type->objet->colour.b * scal.b;
	ambient.r = min(1, ambient.r);
	ambient.g = min(1, ambient.g);
	ambient.b = min(1, ambient.b);
	return (ambient);
}

static t_colour	ft_diffuse(t_data *type)
{
	double		dot;
	t_colour	diffuse;
	t_vector	l_norm;

	l_norm = unit_vector(type->objet->light);
	dot = vector_dot(l_norm, type->objet->normal);
	dot = max(0.0, dot) * type->light->int_light;
	diffuse.r = type->light->rgb_light.r * type->objet->colour.r * dot;
	diffuse.g = type->light->rgb_light.g * type->objet->colour.g * dot;
	diffuse.b = type->light->rgb_light.b * type->objet->colour.b * dot;
	return (diffuse);
}
/*
static void		cofficient(t_data *type, double *ks, double *shininess)
{
	if (type->objet->type == PLANE_D)
	{
		*shininess = 1;
		*ks = 0.2;
	}
	else if (type->objet->type == CYLINDER_D)
	{
		*shininess = 2;
		*ks = 0.2;
	}
	else if (type->objet->type == SPHERE_D)
	{
		*shininess = 50;
		*ks = 0.5;
	}
}*/

t_colour		phong(t_data *type, t_colour shadow)
{
	t_light		*light;
	t_colour	somme;
	t_colour	pixel;//phong_s;

	ft_bzero(&type->phong, sizeof(t_phong));
	light = type->light;
	while (type->light != NULL)
	{
		type->objet->light = vector_sub(type->light->pos, type->objet->point);
		type->phong.diffuse = colour_add(type->phong.diffuse, ft_diffuse(type));
			type->light = type->light->next;
	}
	type->phong.diffuse = colour_scal(255, type->phong.diffuse);
	type->phong.ambiant = colour_scal(255, ft_ambient(type));
	somme = colour_create(type->phong.diffuse);//, type->phong.specular);
	pixel = colour_prd(shadow, somme);
	pixel = colour_add(pixel, type->phong.ambiant);
	type->light = light;
	pixel = min_max(pixel);
	return (pixel);
}
