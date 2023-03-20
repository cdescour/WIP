/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_min_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:25:43 by lreille           #+#    #+#             */
/*   Updated: 2023/03/19 15:45:55 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	parc_sphere(t_data *type, char *line)
{
	char	**sphere;
	t_info	object;

	sphere = ft_split(line, ' ');
	object.pos = ft_split(sphere[1], ',');
	object.colour = ft_split(sphere[3], ',');
	object.radius = ft_atod(sphere[2]);
	if (type->tool.tran_rot > 0)
		object.translation = ft_split(sphere[4], ',');
	type->objet = add_sphere(type, object);
}

void	parc_plane(t_data *type, char *line)
{
	char	**plane;
	t_info	object;

	plane = ft_split(line, ' ');
	object.pos = ft_split(plane[1], ',');
	object.vector = ft_split(plane[2], ',');
	object.colour = ft_split(plane[3], ',');
	if (type->tool.tran_rot > 0)
	{
		object.translation = ft_split(plane[4], ',');
		if (type->tool.tran_rot == 2)
			object.rotation = ft_split(plane[5], ',');
	}
	type->objet = add_plane(type, object);
}

void	parc_cylinder(t_data *type, char *line)
{
	char	**cylinder;
	t_info	object;

	cylinder = ft_split(line, ' ');
	object.pos = ft_split(cylinder[1], ',');
	object.vector = ft_split(cylinder[2], ',');
	object.colour = ft_split(cylinder[3], ',');
	object.radius = ft_atod(cylinder[4]);
	object.height = ft_atod(cylinder[5]);
	if (type->tool.tran_rot > 0)
	{
		object.translation = ft_split(cylinder[6], ',');
		if (type->tool.tran_rot == 2)
			object.rotation = ft_split(cylinder[7], ',');
	}
	type->objet = add_cylinder(type, object);
}
