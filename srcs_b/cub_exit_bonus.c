/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:24:15 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 19:08:24 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_list(void *s)
{
	free(s);
}

void	free_img(t_win *win)
{
	if (win->img.img)
		mlx_destroy_image(win->mlx, win->img.img);
	if (win->no.img)
		mlx_destroy_image(win->mlx, win->no.img);
	if (win->so.img)
		mlx_destroy_image(win->mlx, win->so.img);
	if (win->we.img)
		mlx_destroy_image(win->mlx, win->we.img);
	if (win->ea.img)
		mlx_destroy_image(win->mlx, win->ea.img);
	if (win->spr.img)
		mlx_destroy_image(win->mlx, win->spr.img);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int		cub_err(char *string, t_list *list_cub, t_win *win)
{
	if (list_cub)
	{
		ft_lstclear(&list_cub, free_list);
		free(list_cub);
	}
	if (string)
		ft_putstr_fd(string, 1);
	if (win)
	{
		free_img(win);
		if (win->map)
			free_map(win->map);
		if (win->sprite)
			free_spr(win->sprite);
	}
	return (0);
}

int		cub_exit(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	cub_err(0, 0, win);
	exit(0);
}
