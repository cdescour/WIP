/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_cap_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:01:28 by lreille           #+#    #+#             */
/*   Updated: 2023/03/19 15:42:25 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int			check_ambient(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 3)
		return (miss_or_out(type, AMBIENT_D, 1));
	else if (ft_2strlen(parc) > 3)
		return (miss_or_out(type, AMBIENT_D, 7));
	if (check_double(parc[1]) == 0 ||\
			(ft_atod(parc[1]) < 0 || ft_atod(parc[1]) > 1))
		ft_print_cont(type, "Error\nAmbient", AMBIENT_D, 0);
	else if (check_rgb(parc[2]) == 0)
		return (wrong_rgb(type, AMBIENT_D));
	if (type->parcing.a == 1)
		write(1, "Error\nYou must declare just one Ambient\n", 34);
	return (AMBIENT_D);
}

int			check_light(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 3)
		return (miss_or_out(type, LIGHT_D, 1));
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, LIGHT_D));
	else if (check_double(parc[2]) == 0 ||\
			(ft_atod(parc[2]) < 0 || ft_atod(parc[2]) > 1))
		ft_print_cont(type, "Error\nLight", LIGHT_D, 0);
	return (LIGHT_D);
}

static void	camera(t_data *type, char **parc)
{
	if (ft_2strlen(parc) > 6)
		miss_or_out(type, CAMERA_D, 7);
	if (ft_2strlen(parc) >= 5)
	{
		if (check_pos(parc[4]) == 0)
			wrong_trans_rot(type, CAMERA_D, 1);
		type->tool.tran_rot = 1;
	}
	if (ft_2strlen(parc) >= 6)
	{
		if (check_rotation(parc[5]) == 0)
			wrong_trans_rot(type, CAMERA_D, 2);
		type->tool.tran_rot = 2;
	}
}

int			check_camera(t_data *type, char **parc)
{
	if (ft_2strlen(parc) < 4)
		return (miss_or_out(type, CAMERA_D, 1));
	else if (ft_2strlen(parc) > 4)
		camera(type, parc);
	if (check_pos(parc[1]) == 0)
		return (wrong_pos(type, CAMERA_D));
	else if (check_vec_ort(parc[2]) == 0)
		return (wrong_vec_ort(type, CAMERA_D));
	else if (check_double(parc[3]) == 0 ||\
			(ft_atod(parc[3]) < 0 || ft_atod(parc[3]) > 180))
		ft_print_cont(type, "Error\nCamera", CAMERA_D, 0);
	return (CAMERA_D);
}

