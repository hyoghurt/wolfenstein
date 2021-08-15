/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:25:20 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:25:22 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_print_background(t_win *win)
{
	int i;
	int j;

	i = -1;
	while (++i < (win->height / 2))
	{
		j = -1;
		while (++j < win->width)
			my_mlx_pixel_put(win, j, i, win->ceiling);
	}
	i = (win->height / 2);
	while (++i < win->height)
	{
		j = -1;
		while (++j < win->width)
			my_mlx_pixel_put(win, j, i, win->floor);
	}
}
