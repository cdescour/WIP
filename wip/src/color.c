/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:11:59 by lreille           #+#    #+#             */
/*   Updated: 2023/03/19 16:05:00 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

t_colour	colour_create(t_colour v1)
{
	t_colour result;

	result.r = v1.r;
	result.g = v1.g;
	result.b = v1.b;
	return (result);
}

t_colour	colour_add(t_colour v1, t_colour v2)
{
	t_colour result;

	result.r = v1.r + v2.r;
	result.g = v1.g + v2.g;
	result.b = v1.b + v2.b;
	return (result);
}

t_colour	colour_scal(double nbr, t_colour rgb)
{
	t_colour result;

	result.r = rgb.r * nbr;
	result.g = rgb.g * nbr;
	result.b = rgb.b * nbr;
	return (result);
}

t_colour	colour_prd(t_colour col1, t_colour col2)
{
	t_colour result;

	result.r = col1.r * col2.r;
	result.g = col1.g * col2.g;
	result.b = col1.b * col2.b;
	return (result);
}

t_colour	min_max(t_colour rgb)
{
	t_colour result;

	result.r = min(255, max(0, rgb.r));
	result.g = min(255, max(0, rgb.g));
	result.b = min(255, max(0, rgb.b));
	return (result);
}

t_colour	make_number(double nbr)
{
	t_colour result;

	result.r = nbr;
	result.g = nbr;
	result.b = nbr;
	return (result);
}

