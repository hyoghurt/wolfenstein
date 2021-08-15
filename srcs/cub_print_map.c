/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:25:31 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:25:32 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_print_ray(t_win *win, int scl)
{
	int		j;

	win->start = win->dir - (M_PI / 6);
	win->end = win->dir + (M_PI / 6);
	j = 0;
	while (win->start <= win->end && j <= win->width)
	{
		win->ray_x = ((win->pl_x - (SCALE / 2)) / SCALE) * scl + scl / 2;
		win->ray_y = ((win->pl_y - (SCALE / 2)) / SCALE) * scl + scl / 2;
		while (win->map[(int)win->ray_y / scl][(int)win->ray_x / scl] != '1')
		{
			win->ray_x += cos(win->start);
			win->ray_y += sin(win->start);
			my_mlx_pixel_put(win, win->ray_x, win->ray_y, 0xF08080);
		}
		j += 1;
		win->start += (M_PI / 3) / win->width;
	}
}

void	cub_print_pl(t_win *win, int scl)
{
	float	i;
	float	j;
	float	ie;
	float	je;

	i = ((win->pl_x - (SCALE / 2)) / SCALE) * scl;
	ie = i + scl;
	je = ((win->pl_y - (SCALE / 2)) / SCALE) * scl + scl;
	while (i <= ie)
	{
		j = ((win->pl_y - (SCALE / 2)) / SCALE) * scl;
		while (j <= je)
		{
			my_mlx_pixel_put(win, i, j, 0x822222);
			j++;
		}
		i++;
	}
}

void	cub_print_map_wall(t_win *win, int scl_m)
{
	int i;
	int j;
	int	s1;
	int	s2;

	j = -1;
	while (win->map[++j])
	{
		i = -1;
		while (win->map[j][++i])
		{
			if (win->map[j][i] == '1')
			{
				s1 = (j + 1) * scl_m;
				while (--s1 >= (j * scl_m))
				{
					s2 = (i + 1) * scl_m;
					while (--s2 >= (i * scl_m))
						my_mlx_pixel_put(win, s2, s1, 0xFFFFFF);
				}
			}
		}
	}
}

void	cub_print_map(t_win *win, int scl_m)
{
	cub_print_ray(win, scl_m);
	cub_print_pl(win, scl_m);
	cub_print_map_wall(win, scl_m);
}
