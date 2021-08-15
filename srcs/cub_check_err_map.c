/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check_err_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:24:08 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:24:09 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cub_check_err_map(t_win *win)
{
	char	**map;
	int		i;

	map = win->map;
	i = 0;
	while (map[i])
	{
		if (map[i + 1])
		{
			if (!cub_check_wall_map(map, i))
				return (cub_err("Error\n*wrong wall\n", 0, 0));
			if (!cub_check_space_map(map, i))
				return (cub_err("Error\n*trash map\n", 0, 0));
		}
		if (!cub_check_trash_map(map, i))
			return (cub_err("Error\n*trash map\n", 0, 0));
		i++;
	}
	return (1);
}

int	cub_check_wall_map(char **map, int i)
{
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(map[i + 1]);
	while (map[i][j] && (len >= j + 1))
	{
		if (map[i][j] == '1')
		{
			if (map[i + 1][j + 1] == '1')
				if ((map[i][j + 1] != '1') && (map[i + 1][j] != '1'))
					return (0);
			if (j)
				if (map[i + 1][j - 1] == '1')
					if ((map[i][j - 1] != '1') && (map[i + 1][j] != '1'))
						return (0);
		}
		j++;
	}
	return (1);
}

int	cub_check_space_map(char **map, int i)
{
	int		j;
	int		len;

	len = ft_strlen(map[i + 1]);
	j = 0;
	while (map[i][j] && (len >= j + 1))
	{
		if (map[i][j] == ' ')
			if (map[i + 1][j] == '0' || map[i][j + 1] == '0')
				return (0);
		if (map[i][j] == '0')
			if (map[i + 1][j] == ' ' || map[i][j + 1] == ' ')
				return (0);
		j++;
	}
	return (1);
}

int	cub_check_trash_map(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (!ft_strchr(" 10", map[i][j]))
			return (0);
		if (i == 0 && map[i][j] == '0')
			return (0);
		if (j == 0 && map[i][j] == '0')
			return (0);
		if (!map[i][j + 1] && map[i][j] == '0')
			return (0);
		if (!map[i + 1])
			if (map[i][j] == '0')
				return (0);
		j++;
	}
	return (1);
}
