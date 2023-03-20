/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:42:21 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/19 16:28:03 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int	miss_or_out(t_data *type, int object, int wich)
{
	if (object == AMBIENT_D)
		ft_print(type, "Error\nAmbient", wich);
	else if (object == LIGHT_D)
		ft_print(type, "Error\nLight", wich);
	else if (object == CAMERA_D)
		ft_print(type, "Error\nCamera", wich);
	else if (object == SPHERE_D)
		ft_print(type, "Error\nSphere", wich);
	else if (object == PLANE_D)
		ft_print(type, "Error\nPlane", wich);
	else if (object == CYLINDER_D)
		ft_print(type, "Error\nCylinder", wich);
	return (free_exit(type, 1));
}

int	wrong_pos(t_data *type, int object)
{
	if (object == LIGHT_D)
		ft_print(type, "Error\nLight", 2);
	else if (object == CAMERA_D)
		ft_print(type, "Error\nCamera", 2);
	else if (object == SPHERE_D)
		ft_print(type, "Error\nSphere", 2);
	else if (object == PLANE_D)
		ft_print(type, "Error\nPlane", 2);
	else if (object == CYLINDER_D)
		ft_print(type, "Error\nCylinder", 2);
	return (free_exit(type, 1));
}

int	wrong_vec_ort(t_data *type, int object)
{
	if (object == CAMERA_D)
		ft_print(type, "Error\nCamera", 3);
	else if (object == PLANE_D)
		ft_print(type, "Error\nPlane", 3);
	else if (object == CYLINDER_D)
		ft_print(type, "Error\nCylinder", 3);
	return (free_exit(type, 1));
}

int	wrong_rgb(t_data *type, int object)
{
	if (object == AMBIENT_D)
		ft_print(type, "Error\nAmbient", 4);
	else if (object == LIGHT_D)
		ft_print(type, "Error\nLight", 4);
	else if (object == SPHERE_D)
		ft_print(type, "Error\nSphere", 4);
	else if (object == PLANE_D)
		ft_print(type, "Error\nPlane", 4);
	else if (object == CYLINDER_D)
		ft_print(type, "Error\nCylinder", 4);
	return (free_exit(type, 1));
}

int	wrong_trans_rot(t_data *type, int object, int wich)
{
	int i;

	if (wich == 1)
		i = 5;
	else
		i = 6;
	if (object == LIGHT_D)
		ft_print(type, "Error\nLight", i);
	else if (object == CAMERA_D)
		ft_print(type, "Error\nCamera", i);
	else if (object == SPHERE_D)
		ft_print(type, "Error\nSphere", i);
	else if (object == PLANE_D)
		ft_print(type, "Error\nPlane", i);
	else if (object == CYLINDER_D)
		ft_print(type, "Error\nCylinder", i);
	return (free_exit(type, 1));
}

