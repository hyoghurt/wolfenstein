/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite_calc_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:26:43 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:26:45 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_sprite_sort(t_spr *spr)
{
	t_spr	*ptr;
	t_spr	*tu;

	ptr = spr;
	while (ptr)
	{
		tu = ptr->next;
		while (tu)
		{
			if (tu->h < ptr->h)
				cub_sprite_sort_buf(ptr, tu);
			tu = tu->next;
		}
		ptr = ptr->next;
	}
}

void	cub_sprite_sort_buf(t_spr *ptr, t_spr *tu)
{
	float	b_x;
	float	b_y;
	float	b_ang;
	int		b_h;

	b_x = ptr->x;
	b_y = ptr->y;
	b_h = ptr->h;
	b_ang = ptr->ang;
	ptr->x = tu->x;
	ptr->y = tu->y;
	ptr->h = tu->h;
	ptr->ang = tu->ang;
	tu->x = b_x;
	tu->y = b_y;
	tu->h = b_h;
	tu->ang = b_ang;
}

void	cub_sprite_calc(t_win *win)
{
	t_spr	*spr;
	float	rad;
	float	dir;

	spr = win->sprite;
	while (spr)
	{
		spr->h = (SCALE / (sqrt(pow(spr->x - win->pl_x, 2)
		+ pow(spr->y - win->pl_y, 2)))) * ((win->width / 2) / 0.577);
		dir = win->dir;
		rad = atan2(win->pl_y - spr->y, win->pl_x - spr->x);
		if (rad <= 0 && dir < -M_PI / 2)
			dir += M_PI;
		else if (rad <= 0)
			dir -= M_PI;
		else if (dir < M_PI / 2)
			dir += M_PI;
		else
			dir -= M_PI;
		spr->ang = rad - dir;
		spr = spr->next;
	}
}
