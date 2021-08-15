/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:26:35 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:26:36 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		cub_sprite(t_win *win)
{
	int		x;
	int		y;
	t_spr	*new;

	y = -1;
	while (win->map[++y])
	{
		x = -1;
		while (win->map[y][++x])
		{
			if (win->map[y][x] == '2')
			{
				if (!(new = cub_newspr(y, x)))
					return (0);
				cub_add_back_spr(&win->sprite, new);
				win->map[y][x] = '0';
			}
		}
	}
	return (1);
}

t_spr	*cub_newspr(int y, int x)
{
	t_spr	*new;

	if (!(new = (t_spr*)malloc(sizeof(t_spr))))
		return (0);
	new->x = x * SCALE + SCALE / 2;
	new->y = y * SCALE + SCALE / 2;
	new->next = 0;
	return (new);
}

void	free_spr(t_spr *sprite)
{
	t_spr	*bg;
	t_spr	*tmp;

	tmp = sprite;
	while (tmp)
	{
		bg = tmp;
		tmp = tmp->next;
		free(bg);
	}
}

void	cub_add_back_spr(t_spr **sprite, t_spr *new)
{
	t_spr	*ptf;

	ptf = *sprite;
	if (!ptf)
		*sprite = new;
	else
	{
		while (ptf->next)
			ptf = ptf->next;
		ptf->next = new;
	}
}
