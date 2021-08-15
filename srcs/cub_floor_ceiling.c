/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:24:24 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/27 20:36:40 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cub_floor_ceiling(t_list *list_cub, t_win *win)
{
	char	*string;

	while (list_cub)
	{
		string = list_cub->content;
		if (ft_memcmp(string, "C", 1) == 0)
		{
			if (!cub_fine_color_string(&win->ceiling, string))
				return (cub_err("Error\n*value color ceiling\n", 0, 0));
		}
		else if (ft_memcmp(string, "F", 1) == 0)
		{
			if (!cub_fine_color_string(&win->floor, string))
				return (cub_err("Error\n*value color floor\n", 0, 0));
		}
		list_cub = list_cub->next;
	}
	return (1);
}

int	cub_check_digit_f_c(char *string)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*string)
	{
		while (!ft_isdigit(*string) && *string)
			string++;
		if (*string)
			i++;
		while (*string != ',' && *string)
			string++;
		if (*string)
			j++;
	}
	if (i != 3 || j != 2)
		return (0);
	return (1);
}

int	cub_fine_color_string(int *itog, char *string)
{
	int		r;
	int		g;
	int		b;

	if (!cub_check_digit_f_c(string))
		return (0);
	string++;
	r = ft_atoi(string);
	string = ft_strchr(string, ',');
	string++;
	g = ft_atoi(string);
	string = ft_strchr(string, ',');
	string++;
	b = ft_atoi(string);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		return (0);
	*itog = create_trgb(0, r, g, b);
	return (1);
}
