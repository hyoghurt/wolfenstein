/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:26:54 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:26:55 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		cub_texture_put(t_win *win, t_img *img, char *s)
{
	img->img = mlx_xpm_file_to_image(win->mlx, s, &img->width, &img->height);
	if (img->img == 0)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
				&img->line_length, &img->endian);
	return (1);
}

int		cub_texture_init(t_win *win, t_img *img, char *string)
{
	char	*texture;
	char	*start;
	size_t	i;

	i = 0;
	string += 2;
	while (cub_isspace(*string))
		string++;
	start = string;
	while (!cub_isspace(*string))
	{
		string++;
		i++;
	}
	if (!(texture = ft_substr(start, 0, i)))
		return (cub_err("Error\n*malloc (create string texture)\n", 0, 0));
	i = cub_texture_put(win, img, texture);
	free(texture);
	if (i == 0)
		return (cub_err("Error\n*open file texture\n", 0, 0));
	return (1);
}

int		cub_texture(t_list *list_cub, t_win *win)
{
	char	*string;

	while (list_cub)
	{
		string = list_cub->content;
		if (ft_memcmp(string, "NO", 2) == 0)
			if (!cub_texture_init(win, &win->no, string))
				return (0);
		if (ft_memcmp(string, "SO", 2) == 0)
			if (!cub_texture_init(win, &win->so, string))
				return (0);
		if (ft_memcmp(string, "WE", 2) == 0)
			if (!cub_texture_init(win, &win->we, string))
				return (0);
		if (ft_memcmp(string, "EA", 2) == 0)
			if (!cub_texture_init(win, &win->ea, string))
				return (0);
		if (ft_memcmp(string, "S ", 2) == 0)
			if (!cub_texture_init(win, &win->spr, string))
				return (0);
		list_cub = list_cub->next;
	}
	return (1);
}
