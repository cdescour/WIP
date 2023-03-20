/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:15 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/19 16:15:45 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"
/*
t_objet	*add_sphere(t_data *type, t_info object)
{
	t_objet *tmp;
	t_objet *new_sphere;

	tmp = type->objet;
	if (!(new_sphere = (t_objet *)malloc(sizeof(t_objet))))
		free_exit(type, 1);
	new_sphere->previous = NULL;
	new_sphere->next = NULL;
	new_sphere->type = SPHERE_D;
	new_sphere->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_sphere->colour = make_range(r_g_b(object.colour[0],\
				object.colour[1], object.colour[2]));
	trans_rot(type, new_sphere, object);
	new_sphere->radius = object.radius / 2;
	new_sphere->i = type->tool.index;
	type->tool.index++;
	if (type->objet == NULL)
		return (new_sphere);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_sphere->previous = tmp;
	tmp->next = new_sphere;
	return (type->objet);
}

t_sphere	*init_sphere(char **info1, char *info2, char **info3)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->pos = save_pos(info1);
	sphere->diam = save_distance(info2);
	sphere->color = save_color(info3);
	sphere->next = NULL;
	return (sphere);
}

int	save_distance(char *str)
{
	int	i;
	char **tab;

	tab = ft_split(str, '.');
	i = ft_atoi(tab[0]) * 1000;
	if (tab[1] != NULL)
		i += ft_atoi_size(tab[1], 3);
	free_tab(tab);
	return (i);
}*/
