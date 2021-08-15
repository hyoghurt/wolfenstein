/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:25:08 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:25:09 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		cub_player(t_win *win)
{
	if (!cub_player_position(win))
		return (cub_err("Error\n*count player\n", 0, 0));
	cub_player_dir(win);
	win->pl_x = win->pl_x * SCALE + (SCALE / 2);
	win->pl_y = win->pl_y * SCALE + (SCALE / 2);
	return (1);
}

int		cub_player_position(t_win *win)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (win->map[++i])
	{
		j = -1;
		while (win->map[i][++j])
		{
			if (ft_strchr("NSWE", win->map[i][j]))
			{
				win->pl_x = j;
				win->pl_y = i;
				count++;
			}
		}
	}
	if (count != 1)
		return (0);
	return (1);
}

void	cub_player_dir(t_win *win)
{
	char	**map;
	int		x;
	int		y;

	map = win->map;
	x = win->pl_x;
	y = win->pl_y;
	if (map[y][x] == 'N')
		win->dir = -M_PI / 2;
	if (map[y][x] == 'S')
		win->dir = M_PI / 2;
	if (map[y][x] == 'W')
		win->dir = -M_PI;
	if (map[y][x] == 'E')
		win->dir = 0;
	win->map[y][x] = '0';
}
