/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:26:11 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:26:12 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		cub_check_color_wall(t_win *win, int side)
{
	if (side == -1)
	{
		if (win->map[(int)((win->ray_y) / SCALE)]
			[(int)((win->ray_x - 1) / SCALE)] == '0')
		{
			if (win->pl_x < win->ray_x)
				return (1);
		}
	}
	else if (side == 1)
	{
		if (win->map[(int)((win->ray_y) / SCALE)]
			[(int)((win->ray_x + 1) / SCALE)] == '0')
		{
			if (win->pl_x > win->ray_x)
				return (1);
		}
	}
	return (0);
}

int		cub_return_color(t_win *win, float text_pos)
{
	int		color;

	if (win->map[(int)(win->ray_y + 1) / SCALE]
		[(int)(win->ray_x) / SCALE] == '0')
	{
		if (cub_check_color_wall(win, -1))
			color = get_color_images(&win->ea, win->ray_y, text_pos);
		else if (cub_check_color_wall(win, 1))
			color = get_color_images(&win->we, win->ray_y, text_pos);
		else
			color = get_color_images(&win->no, win->ray_x, text_pos);
	}
	else if (cub_check_color_wall(win, -1))
		color = get_color_images(&win->ea, win->ray_y, text_pos);
	else if (cub_check_color_wall(win, 1))
		color = get_color_images(&win->we, win->ray_y, text_pos);
	else
		color = get_color_images(&win->so, win->ray_x, text_pos);
	return (color);
}

void	cub_print_wall(t_win *win, int x, int *h_wall)
{
	int			y_start;
	int			y_end;
	int			h;
	float		step;
	float		text_pos;

	h = (SCALE / (sqrt(pow(win->ray_x - win->pl_x, 2)
		+ pow(win->ray_y - win->pl_y, 2))
		* cos(win->start - win->dir))) * ((win->width / 2) / 0.577);
	h_wall[x] = h;
	if ((y_start = (win->height - h) / 2) < 0)
		y_start = 0;
	if ((y_end = (win->height + h) / 2) > win->height)
		y_end = win->height;
	step = SCALE / (float)h;
	text_pos = 0;
	if (h > win->height)
		text_pos = (h / 2 - win->height / 2) * step;
	while (y_start < y_end)
	{
		my_mlx_pixel_put(win, x, y_start, cub_return_color(win, text_pos));
		text_pos += step;
		y_start++;
	}
}

void	cub_print_ray_wall(t_win *win, int *h_wall)
{
	int		x;

	win->start = win->dir - (M_PI / 6);
	win->end = win->dir + (M_PI / 6);
	x = 0;
	while (win->start <= win->end && x < win->width)
	{
		win->ray_x = win->pl_x;
		win->ray_y = win->pl_y;
		while (win->map[(int)win->ray_y / SCALE]
				[(int)win->ray_x / SCALE] != '1')
		{
			win->ray_x += cos(win->start);
			win->ray_y += sin(win->start);
		}
		cub_print_wall(win, x, h_wall);
		x++;
		win->start += (M_PI / 3) / win->width;
	}
}
