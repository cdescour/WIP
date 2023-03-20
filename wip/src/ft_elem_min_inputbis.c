/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_min_inputbis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:53:26 by lreille           #+#    #+#             */
/*   Updated: 2023/03/19 16:03:30 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	trans_rot(t_data *type, t_objet *new_object, t_info object)
{
	if (type->tool.tran_rot > 0)
	{
		new_object->translation = x_y_z(object.translation[0],\
					object.translation[1], object.translation[2]);
		new_object->pos = vector_add(new_object->pos, new_object->translation);
		if (type->tool.tran_rot == 2)
		{
			new_object->rotation = x_y_z(object.rotation[0],\
					object.rotation[1], object.rotation[2]);
			new_object->v = rot_vector(new_object->v, new_object->rotation);
		}
	}
}

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

t_objet	*add_plane(t_data *type, t_info object)
{
	t_objet *tmp;
	t_objet *new_plane;

	tmp = type->objet;
	if (!(new_plane = (t_objet *)malloc(sizeof(t_objet))))
		free_exit(type, 1);
	new_plane->previous = NULL;
	new_plane->next = NULL;
	new_plane->type = PLANE_D;
	new_plane->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_plane->v = x_y_z(object.vector[0], object.vector[1], object.vector[2]);
	new_plane->v = unit_vector(new_plane->v);
	new_plane->colour = make_range(r_g_b(object.colour[0],\
				object.colour[1], object.colour[2]));
	trans_rot(type, new_plane, object);
	new_plane->i = type->tool.index;
	type->tool.index++;
	if (type->objet == NULL)
		return (new_plane);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_plane->previous = tmp;
	tmp->next = new_plane;
	return (type->objet);
}

static void	cy_contunied(t_data *type, t_objet *new_cylinder, t_info object)
{
	new_cylinder->radius = object.radius / 2;
	new_cylinder->height = object.height;
	trans_rot(type, new_cylinder, object);
	new_cylinder->i = type->tool.index;
	type->tool.index++;
}

t_objet		*add_cylinder(t_data *type, t_info object)
{
	t_objet *tmp;
	t_objet *new_cylinder;

	tmp = type->objet;
	if (!(new_cylinder = (t_objet *)malloc(sizeof(t_objet))))
		free_exit(type, 1);
	new_cylinder->previous = NULL;
	new_cylinder->next = NULL;
	new_cylinder->type = CYLINDER_D;
	new_cylinder->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_cylinder->v = x_y_z(object.vector[0],\
			object.vector[1], object.vector[2]);
	new_cylinder->v = unit_vector(new_cylinder->v);
	new_cylinder->colour = make_range(r_g_b(object.colour[0],\
				object.colour[1], object.colour[2]));
	cy_contunied(type, new_cylinder, object);
	if (type->objet == NULL)
		return (new_cylinder);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_cylinder->previous = tmp;
	tmp->next = new_cylinder;
	return (type->objet);
}
