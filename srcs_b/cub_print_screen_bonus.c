/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_screen_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:25:46 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/22 14:45:33 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length
			+ x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		get_color_images(t_img *img, int x, int y)
{
	char	*color;

	color = img->addr + (y * img->line_length
			+ (x % SCALE) * (img->bits_per_pixel / 8));
	return (*(unsigned int*)color);
}

void	cub_print_images(t_win *win)
{
	int	h_wall[win->width];

	cub_print_background(win);
	cub_print_ray_wall(win, h_wall);
	cub_print_sprite(win, h_wall);
	cub_print_map(win, 6);
}

int		cub_print_window(t_win *win)
{
	cub_print_images(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	return (1);
}
