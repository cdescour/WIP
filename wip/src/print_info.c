/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 04:27:47 by lreille           #+#    #+#             */
/*   Updated: 2023/03/19 16:13:21 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"
/*
void	ft_print_head(void)
{
	
	printf("\n Item |  Position  |  Direction  | Diam");
	printf("eter | Height | Color 	| Intensity \n");
	printf(" [][] | X   Y   Z  |  X   Y   Z  | [][]");
	printf("[][] | [][][] | R  G  B  | [][][][][]\n");
	printf(" VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV");
	printf("VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n");
}

void	ft_print_colors(char *info)
{
	char **str;

	str = ft_split(info, ',');
	printf("Colors: ");
	printf("Red   = %s\n", str[0]);
	printf("	Green = %s\n", str[1]);
	printf("	Blue  = %s\n", str[2]);
	free_tab(str);
}

void	ft_print_coord(char *info)
{
	char **str;

	str = ft_split(info, ',');
	printf("Coords: ");
	printf("X = %s\n", str[0]);
	printf("	Y = %s\n", str[1]);
	printf("	Z = %s\n", str[2]);
	free_tab(str);
}

void	ft_print_lum_ratio(char *info)
{
	printf("Lum Ratio: %s\n", info);
}

void	ft_print_fov(char *info)
{
	printf("FOV range: %s\n", info);
}

void	ft_print_vector(char *info)
{
	char **str;

	str = ft_split(info, ',');
	printf("VDirection :");	
	printf("X = %s\n", str[0]);
	printf("	    Y = %s\n", str[1]);
	printf("	    Z = %s\n", str[2]);
	free_tab(str);
}

void	ft_print_height(char *info)
{
	printf("Height : %s\n", info);
}

void	ft_print_diameter(char *info)
{
	printf("Diameter : %s\n", info);
}


void	ft_print_A_info(char **info, t_item *item)
{
	(void)info;
	(void)item;
//	printf("struct outpu%d\n", item->amb->intensity);

}

void	ft_print_C_info(char **info)
{
	(void)info;
		int	i;

	i = 0;
	while (info[i])
		printf("%s\n", info[i++]);

	printf("* Item->%s\n", info[0]);
	ft_print_coord(info[1]);
	ft_print_vector(info[2]);
	ft_print_fov(info[3]);
	printf("\n");
}

void	ft_print_L_info(char **info)
{
	(void)info;
		int	i;

	i = 0;
	while (info[i])
		printf("%s\n", info[i++]);

	printf("* Item->%s\n", info[0]);
	ft_print_coord(info[1]);
	ft_print_lum_ratio(info[2]);
	printf("\n");
}

void	ft_print_sp_info(char **info)
{
	(void)info;
		int	i;

	i = 0;
	while (info[i])
		printf("%s\n", info[i++]);

	printf("* Item->%s\n", info[0]);
	ft_print_coord(info[1]);
	printf("%s\n", info[2]);
	ft_print_diameter(info[2]);
	ft_print_colors(info[3]);
	printf("\n");
}

void	ft_print_pl_info(char **info)
{	
	(void)info;
	int	i;

	i = 0;
	while (info[i])
		printf("%s\n", info[i++]);

	printf("* Item->%s\n", info[0]);
	ft_print_coord(info[1]);
	ft_print_vector(info[2]);
	ft_print_colors(info[3]);
	printf("\n");

}
void	ft_print_cyl_info(char **info)
{
	(void)info;
		int	i;

	i = 0;
	while (info[i])
		printf("%s\n", info[i++]);

	printf("* Item->%s\n", info[0]);
	ft_print_coord(info[1]);
	ft_print_vector(info[2]);
	ft_print_diameter(info[3]);
	ft_print_height(info[4]);
	ft_print_colors(info[5]);
	printf("\n");
}

void	ft_print_info(char **info, t_item *item)
{
	if (!info[0])
		printf("\n");
	else if (!ft_strcmp("A", info[0]))
		ft_print_A_info(info, item);
	else if (!ft_strcmp("C", info[0]))	
		ft_print_C_info(info);
	else if (!ft_strcmp("L", info[0]))
		ft_print_L_info(info);
	else if (!ft_strcmp("sp", info[0]))
		ft_print_sp_info(info);
	else if (!ft_strcmp("pl", info[0]))
		ft_print_pl_info(info);
	else if (!ft_strcmp("cy", info[0]))
		ft_print_cyl_info(info);
}*/
