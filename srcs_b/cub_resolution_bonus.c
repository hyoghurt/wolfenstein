/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:26:21 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:26:22 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cub_isspace(char s)
{
	if (s == '\t' || s == '\n' || s == '\v'
		|| s == '\r' || s == '\f' || s == ' ')
		return (1);
	return (0);
}

int	cub_resolution(t_list *list_cub, t_win *win)
{
	char	*string;

	while (list_cub)
	{
		string = list_cub->content;
		if (ft_memcmp(string, "R", 1) == 0)
			if (!cub_value_resolution(string, win))
				return (cub_err("Error\n*value resolution\n", 0, 0));
		list_cub = list_cub->next;
	}
	return (1);
}

int	cub_value_resolution(char *s, t_win *win)
{
	int	width;
	int	height;

	mlx_get_screen_size(&width, &height);
	while (!ft_isdigit(*s) && *s)
		s++;
	if (*s)
		win->width = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	if (*s)
		win->height = ft_atoi(s);
	if (win->height <= 0 || win->width <= 0)
		return (0);
	if (win->height > height)
		win->height = height;
	if (win->width > width)
		win->width = width;
	return (1);
}
