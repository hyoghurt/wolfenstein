/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:25:57 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:25:58 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_print_sprite(t_win *win, int *h_wall)
{
	t_spr	*ptf;

	cub_sprite_calc(win);
	cub_sprite_sort(win->sprite);
	ptf = win->sprite;
	while (ptf)
	{
		cub_print_sprite_one(win, ptf, h_wall);
		ptf = ptf->next;
	}
}

int		get_color_sprite(t_img *img, int x, int y)
{
	char	*color;

	color = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int*)color);
}

void	cub_print_sprite_one(t_win *win, t_spr *spr, int *h_wall)
{
	float	pos_x;
	float	step;
	int		offset_x;
	int		i;

	step = SCALE / (float)spr->h;
	pos_x = 0;
	offset_x = spr->ang * (win->width / 2) / (M_PI / 6)
				+ win->width / 2 - spr->h / 2;
	i = offset_x;
	while (i <= offset_x + spr->h && i < win->width)
	{
		if (i >= 0)
			if (h_wall[i] < spr->h)
				cub_print_sprite_one_next(win, spr, (int)pos_x, i);
		i++;
		pos_x += step;
	}
}

void	cub_print_sprite_one_next(t_win *win, t_spr *spr, int pos_x, int i)
{
	float	pos_y;
	float	step;
	int		offset_y;
	int		j;
	int		color;

	step = SCALE / (float)spr->h;
	offset_y = win->height / 2 - spr->h / 2;
	j = offset_y;
	pos_y = 0;
	while (j < offset_y + spr->h && j < win->height)
	{
		if (j >= 0)
		{
			color = get_color_sprite(&win->spr, pos_x, (int)pos_y);
			if (color != 9961608)
				my_mlx_pixel_put(win, i, j, color);
		}
		j++;
		pos_y += step;
	}
}
