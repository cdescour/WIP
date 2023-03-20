/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_min_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:50:18 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/19 15:43:24 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int			check_sphere(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, SPHERE_D, 1));
	if (ft_2strlen(parc) > 4)
	{
		if (ft_2strlen(parc) > 5)
			return (miss_or_out(type, SPHERE_D, 7));
		if (ft_2strlen(parc) >= 5)
		{
			if (check_pos(parc[4]) == 0)
				return (wrong_trans_rot(type, SPHERE_D, 1));
			type->tool.tran_rot = 1;
		}
	}
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, SPHERE_D));
	else if (check_double(parc[2]) == 0 || ft_atod(parc[2]) < 0)
		ft_print_cont(type, "Error\nSphere", SPHERE_D, 0);
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, SPHERE_D));
	return (SPHERE_D);
}

static void	plane(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 6)
		miss_or_out(type, PLANE_D, 7);
	if (ft_2strlen(parc) >= 5)
	{
		if (check_pos(parc[4]) == 0)
			wrong_trans_rot(type, PLANE_D, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 6)
	{
		if (check_rotation(parc[5]) == 0)
			wrong_trans_rot(type, PLANE_D, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_plane(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, PLANE_D, 1));
	else if (ft_2strlen(parc) > 4)
		plane(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, PLANE_D));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, PLANE_D));
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, PLANE_D));
	return (PLANE_D);
}

static void	cylinder(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 8)
		miss_or_out(type, CYLINDER_D, 7);
	if (ft_2strlen(parc) >= 7)
	{
		if (check_pos(parc[6]) == 0)
			wrong_trans_rot(type, CYLINDER_D, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 8)
	{
		if (check_rotation(parc[7]) == 0)
			wrong_trans_rot(type, CYLINDER_D, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_cylinder(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 6)
		return (miss_or_out(type, CYLINDER_D, 1));
	else if (ft_2strlen(parc) > 6)
		cylinder(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, CYLINDER_D));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, CYLINDER_D));
	else if (check_rgb(parc[3]) == 0)
		return (wrong_rgb(type, CYLINDER_D));
	else if (check_double(parc[4]) == 0 || ft_atod(parc[4]) < 0)
		ft_print_cont(type, "Error\nCylinder", CYLINDER_D, 1);
	else if (check_double(parc[5]) == 0 || ft_atod(parc[5]) < 0)
		ft_print_cont(type, "Error\nCylinder", CYLINDER_D, 2);
	return (CYLINDER_D);
}
