/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:24:40 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/22 13:07:37 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_hook(int keycode, t_win *win)
{
	if (keycode == 13)
		cub_keycode_w(win);
	if (keycode == 1)
		cub_keycode_s(win);
	if (keycode == 2)
		cub_keycode_d(win);
	if (keycode == 0)
		cub_keycode_a(win);
	if (keycode == 123)
		win->dir -= M_PI / 10;
	if (keycode == 124)
		win->dir += M_PI / 10;
	if (keycode == 53)
		cub_exit(win);
	while (win->dir > M_PI)
		win->dir -= 2 * M_PI;
	while (win->dir < -M_PI)
		win->dir += 2 * M_PI;
	return (1);
}

void	cub_keycode_a(t_win *win)
{
	win->pl_y += sin(win->dir - M_PI / 2) * SPEED;
	win->pl_x += cos(win->dir - M_PI / 2) * SPEED;
	if (win->map[(int)win->pl_y / SCALE][(int)win->pl_x / SCALE] == '1')
	{
		win->pl_y -= sin(win->dir - M_PI / 2) * SPEED;
		win->pl_x -= cos(win->dir - M_PI / 2) * SPEED;
	}
}

void	cub_keycode_d(t_win *win)
{
	win->pl_y += sin(win->dir + M_PI / 2) * SPEED;
	win->pl_x += cos(win->dir + M_PI / 2) * SPEED;
	if (win->map[(int)win->pl_y / SCALE][(int)win->pl_x / SCALE] == '1')
	{
		win->pl_y -= sin(win->dir + M_PI / 2) * SPEED;
		win->pl_x -= cos(win->dir + M_PI / 2) * SPEED;
	}
}

void	cub_keycode_w(t_win *win)
{
	win->pl_y += sin(win->dir) * SPEED;
	win->pl_x += cos(win->dir) * SPEED;
	if (win->map[(int)win->pl_y / SCALE][(int)win->pl_x / SCALE] == '1')
	{
		win->pl_y -= sin(win->dir) * SPEED;
		win->pl_x -= cos(win->dir) * SPEED;
	}
}

void	cub_keycode_s(t_win *win)
{
	win->pl_y -= sin(win->dir) * SPEED;
	win->pl_x -= cos(win->dir) * SPEED;
	if (win->map[(int)win->pl_y / SCALE][(int)win->pl_x / SCALE] == '1')
	{
		win->pl_y += sin(win->dir) * SPEED;
		win->pl_x += cos(win->dir) * SPEED;
	}
}
