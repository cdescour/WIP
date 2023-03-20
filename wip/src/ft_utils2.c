/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:26:49 by lreille           #+#    #+#             */
/*   Updated: 2023/03/18 12:48:23 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

t_colour		r_g_b(char *r, char *g, char *b)
{
	t_colour extr;

	extr.r = ft_atod(r);
	extr.g = ft_atod(g);
	extr.b = ft_atod(b);
	return (extr);
}
t_vector	x_y_z(char *x, char *y, char *z)
{
	t_vector extr;

	extr.x = ft_atod(x);
	extr.y = ft_atod(y);
	extr.z = ft_atod(z);
	return (extr);
}
static void	free_light(t_data *type)
{
	t_light *tmp_l;

	while (type->light != NULL)
	{
		tmp_l = type->light->next;
		free(type->light);
		type->light = NULL;
		type->light = tmp_l;
	}
}

int			free_exit(t_data *type, int wich)
{
	t_objet		*tmp_o;
	t_camera	*tmp_c;

	while (type->objet != NULL)
	{
		tmp_o = type->objet->next;
		free(type->objet);
		type->objet = NULL;
		type->objet = tmp_o;
	}
	while (type->camera != NULL)
	{
		tmp_c = type->camera->next;
		free(type->camera);
		type->camera = NULL;
		type->camera = tmp_c;
	}
	free_light(type);
	exit(wich);
}
