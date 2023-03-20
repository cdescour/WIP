/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:27:38 by lreille           #+#    #+#             */
/*   Updated: 2023/03/19 16:12:23 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"
/*
int	ft_convert_float(char *info)
{
	int	i;
	int	j;
	int	ret;
	int	dot_pos;
	char	*str;

	i = 0;
	j = 0;
	dot_pos = ft_dot_pos(info);
	str = malloc(sizeof(char *) * dot_pos + 4);
	while (info[i] && i <= dot_pos + 3)
	{
		if (info[i] == '.' && info[i + 1] != '\0')
			i++;
		str[j++] = info[i++];
	}
	while (i++ <= dot_pos + 3)
		str[j++] = '0';
	str[j] = '\0';
	ret = ft_atoibis(str);
	free (str);
	return (ret);
}

int	ft_is_input(char *info)
{
	if (ft_count_dot(info) > 0)
		return (ft_convert_float(info));
	else
		return (ft_is_nofloat(info));
}

int	ft_is_nofloat(char *info)
{
	int	i;
	int	j;
	int	ret;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * ft_strlen(info) + 4);
	while (info[i])
		str[j++] = info[i++];
	i = 0;
	while (i++ < 3)
		str[j++] = '0';
	str[j] = '\0';
	ret = ft_atoibis(str);
	free (str);
	return (ret);
}*/
