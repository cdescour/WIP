/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:09:49 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/19 16:46:11 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"
/*
t_objet	*add_plane(t_data *type, t_info object)
{
	t_objet *tmp;
	t_objet *new_plane;

	tmp = type->objet;
	if (!(new_plane = (t_objet *)malloc(sizeof(t_objet))))
		free_exit(type, 1);
	new_plane->previous = NULL;
	new_plane->next = NULL;
//	printf("here\n");
	new_plane->type = PLANE_D;
	new_plane->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_plane->v = x_y_z(object.vector[0], object.vector[1], object.vector[2]);
	new_plane->v = unit_vector(new_plane->v);
	new_plane->colour = make_range(r_g_b(object.colour[0],\
				object.colour[1], object.colour[2]));
	trans_rot(type, new_plane, object);
	new_plane->i = type->tool.index;
	type->tool.index++;
	//printf("here\n");
	if (type->objet == NULL)
		printf("here\n");//	return (new_plane);
//	printf("here\n");
	while (tmp->next != NULL)
		tmp = tmp->next;
//	printf("here\n");
	new_plane->previous = tmp;
	tmp->next = new_plane;
	return (type->objet);
}
*/
