/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:56:14 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/20 12:07:23 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

t_colour	coleur(t_data *type)
{
	double		t1;
	t_objet		*tmp;
	t_colour	black;
	t_colour	phong_s;
	t_colour	shadow1;

	t1 = FLT_MAX;
	tmp = type->objet;
	black = make_number(0);
	hit_objet(type, &t1);
	if (type->tool.intersect == 1)
	{
		shadow1 = shadows(type, tmp);
		phong_s = phong(type, shadow1);
		type->objet = tmp;
		return(phong_s);
	}
	else
		return (black);
}

void		minirt(t_data *type)
{
	int			i;
	t_colour	colour;

	i = 0;
	type->rsl.x = 0;
	type->rsl.y = 0;
	camera_setting(type);
	while (type->rsl.y < type->rsl.height)
	{
		type->rsl.x = 0;
		while (type->rsl.x < type->rsl.width)
		{
			ray(type);
			colour = coleur(type);
			type->colour.r = (int)colour.r;
			type->colour.g = (int)colour.g;
			type->colour.b = (int)colour.b;
			type->mlx.img_data[i] = merge(&type->colour);
			type->rsl.x++;
			i++;
		}
		type->rsl.y++;
	}
}

int		key_press(int keycode, t_data *type)
{
	if (keycode == 0 || keycode == 2)
	{
		if (keycode == 0)
		{
			if (type->camera->previous != NULL)
				type->camera = type->camera->previous;
		}
		else if (keycode == 2)
		{
			if (type->camera->next != NULL)
				type->camera = type->camera->next;
		}
		minirt(type);
		mlx_put_image_to_window(type->mlx.mlx_ptr, type->mlx.win_ptr,\
		type->mlx.img_ptr, 0, 0);
	}
	if (keycode == 53)
		free_exit(type, 0);
	return (0);
}
void	ft_mlx(t_data *type, int wich)
{
	int endian;

	if (wich == 1)
	{
		type->mlx.mlx_ptr = mlx_init();
		type->mlx.img_ptr = mlx_new_image(type->mlx.mlx_ptr,\
			type->rsl.width, type->rsl.height);
		type->mlx.img_data = (int *)mlx_get_data_addr(type->mlx.img_ptr,\
			&type->mlx.bpp, &type->mlx.size_line, &endian);
	}
	else if (wich == 2)
	{
		type->mlx.win_ptr = mlx_new_window(type->mlx.mlx_ptr,\
			type->rsl.width, type->rsl.height, "miniRT");
		mlx_put_image_to_window(type->mlx.mlx_ptr, type->mlx.win_ptr,\
			type->mlx.img_ptr, 0, 0);
		mlx_hook(type->mlx.win_ptr, 2, 0, key_press, type);
		mlx_hook(type->mlx.win_ptr, 17, 0, ft_close, type);
		mlx_loop(type->mlx.mlx_ptr);
	}
}

int		main(int argc, char **argv)
{
	t_data type;
	ft_bzero(&type, sizeof(t_data));
	type.nb_cam = 0;
	type.nb_amb = 0;
	type.nb_spt = 0;
	parcing(&type, argv, argc);
	ft_mlx(&type, 1);
	minirt(&type);
	ft_mlx(&type, 2);
	return (0);
}
