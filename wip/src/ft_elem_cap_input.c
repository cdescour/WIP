/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_cap_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:34:47 by lreille           #+#    #+#             */
/*   Updated: 2023/03/18 12:42:42 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	parc_amb(t_data *type, char *line)
{
	char	**amb;
	char	**rgb;

	amb = ft_split(line, ' ');
	rgb = ft_split(amb[2], ',');
	type->ambient.int_amb = ft_atod(amb[1]);
	type->ambient.rgb_amb = r_g_b(rgb[0], rgb[1], rgb[2]);
	type->ambient.rgb_amb = make_range(type->ambient.rgb_amb);
	type->parcing.a = 1;
}

void	parc_camera(t_data *type, char *line)
{
	char	**camera;
	t_info	object;

	camera = ft_split(line, ' ');
	object.pos = ft_split(camera[1], ',');
	object.vector = ft_split(camera[2], ',');
	object.fov = ft_atod(camera[3]);
	if (type->tool.tran_rot > 0)
	{
		object.translation = ft_split(camera[4], ',');
		if (type->tool.tran_rot == 2)
			object.rotation = ft_split(camera[5], ',');
	}
	type->camera = add_camera(type, object);
	type->parcing.c = 1;
}

void	parc_light(t_data *type, char *line)
{
	char	**light;
	t_info	object;

	light = ft_split(line, ' ');
	object.pos = ft_split(light[1], ',');
	object.colour = ft_split(light[3], ',');
	object.int_light = ft_atod(light[2]);
	if (type->tool.tran_rot > 0)
		object.translation = ft_split(light[4], ',');
	type->light = add_light(type, object);
}
