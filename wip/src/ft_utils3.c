/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:49:25 by lreille           #+#    #+#             */
/*   Updated: 2023/03/19 16:40:16 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void		witch_object(t_objet *objet, t_ray *ray, double *has_inter)
{
	if (objet->type == SPHERE_D)
		*has_inter = hit_sphere(objet, ray);
	else if (objet->type == PLANE_D)
		*has_inter = hit_plane(objet, ray);
	else if (objet->type == CYLINDER_D)
		*has_inter = hit_cylinder(objet, ray);
}
t_colour	make_rrange(int rgb)
{
	t_colour result;

	result.r = rgb / 255;
	result.g = rgb / 255;
	result.b = rgb / 255;
	return (result);
}

double	max(double a, double b)
{
	double result;

	result = (a >= b) ? a : b;
	return (result);
}

double	min(double a, double b)
{
	double result;

	result = (a <= b) ? a : b;
	return (result);
}

int			merge(t_colour *data)
{
	return ((data->r * 256 * 256) + (data->g * 256) + data->b);
}
