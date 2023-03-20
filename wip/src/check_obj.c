/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:37:56 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/20 12:09:41 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int		check_element(t_data *type, char **parc, int check)
{
	if (check == AMBIENT_D)
	{
		if (type->nb_amb++ != 0)
			write(1,"ERREUR +A+\n", 11);
		return (check_ambient(type, parc));
	}
	else if (check == CAMERA_D)
	{
		if (type->nb_cam++ != 0)
			write(1,"ERREUR +C+\n", 11);
		return (check_camera(type, parc));
	}
	else if (check == LIGHT_D)
	{
		if (type->nb_spt++ != 0)
			write(1,"ERREUR +S+\n", 11);
		return (check_light(type, parc));
	}
	else if (check == SPHERE_D)
		return (check_sphere(type, parc));
	else if (check == PLANE_D)
		return (check_plane(type, parc));
	else 
		return (check_cylinder(type, parc));
}
void	parcing_tool(t_data *type, int indice, char *line)
{
	 if (indice == AMBIENT_D)
		parc_amb(type, line);
	else if (indice == CAMERA_D)
		parc_camera(type, line);
	else if (indice == LIGHT_D)
		parc_light(type, line);
	else if (indice == CAMERA_D)
		parc_camera(type, line);
	else if (indice == SPHERE_D)
		parc_sphere(type, line);
	else if (indice == PLANE_D)
		parc_plane(type, line);
	else if (indice == CYLINDER_D)
		parc_cylinder(type, line);
}
void	check_type(t_data *type, char **parc)
{
	if (ft_strnstr("A", parc[0], 2))
		type->parcing.check = AMBIENT_D;
	else if (ft_strnstr("C", parc[0], 2))
		type->parcing.check = CAMERA_D;
	else if (ft_strnstr("L", parc[0], 2))
		type->parcing.check = LIGHT_D;
	else if (ft_strnstr("sp", parc[0], 3))
		type->parcing.check = SPHERE_D;
	else if (ft_strnstr("pl", parc[0], 3))
		type->parcing.check = PLANE_D;
	else if (ft_strnstr("cy", parc[0], 3))
		type->parcing.check = CYLINDER_D;
	else
		type->parcing.check = 0;
}
