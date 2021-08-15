/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:27:17 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/25 19:11:29 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	cub_exit_after(char *string, t_list *list_cub, t_win *win)
{
	cub_err(string, list_cub, win);
	exit(0);
}

void	init_win(t_win *win)
{
	win->map = 0;
	win->sprite = 0;
	win->height = 0;
	win->width = 0;
	win->img.img = 0;
	win->no.img = 0;
	win->so.img = 0;
	win->we.img = 0;
	win->ea.img = 0;
	win->spr.img = 0;
	win->sprite = 0;
}

int		main(int argc, char **argv)
{
	t_win	win;

	init_win(&win);
	if (argc > 3 || argc == 1)
		cub_exit_after("Error\n*count argc\n", 0, 0);
	if (!(win.mlx = mlx_init()))
		cub_exit_after("Error\n*init mlx\n", 0, 0);
	if (!cub_parser(&win, argv[1]))
		cub_exit_after(0, 0, 0);
	if (!(win.img.img = mlx_new_image(win.mlx, win.width, win.height)))
		cub_exit_after("Error\n*create img\n", 0, &win);
	win.img.addr = mlx_get_data_addr(win.img.img,
			&win.img.bits_per_pixel, &win.img.line_length, &win.img.endian);
	if (argc == 3)
		cub_create_bmp(&win, argv[2]);
	if (!(win.win = mlx_new_window(win.mlx, win.width, win.height, "cub3D")))
		cub_exit_after("Error\n*create window\n", 0, &win);
	mlx_hook(win.win, 2, 1L << 0, key_hook, &win);
	mlx_hook(win.win, 17, 1L << 1, cub_exit, &win);
	mlx_loop_hook(win.mlx, cub_print_window, &win);
	mlx_loop(win.mlx);
	return (1);
}
