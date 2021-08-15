/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:24:49 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:24:51 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cub_map(t_list *list_cub, t_win *win)
{
	char	*string;

	while (list_cub)
	{
		string = list_cub->content;
		while (*string == ' ')
			string++;
		if (*string)
		{
			while (*string == '1' || *string == '0' || *string == ' ')
				string++;
			if (*string == '\0')
				break ;
		}
		list_cub = list_cub->next;
	}
	if (!list_cub)
		return (cub_err("Error\n*no map\n", 0, 0));
	if (!cub_create_bi_map(list_cub, win))
		return (cub_err("Error\n*create **char map\n", 0, 0));
	return (1);
}

int	cub_find_big_len(t_list *list_cub)
{
	t_list	*cub;
	size_t	len;
	size_t	buf;

	cub = list_cub;
	len = 0;
	while (cub)
	{
		buf = ft_strlen(cub->content);
		if (buf > len)
			len = buf;
		cub = cub->next;
	}
	return (len);
}

int	cub_create_bi_map(t_list *list_cub, t_win *win)
{
	int		size;
	size_t	len;
	int		i;
	char	*string;
	char	**map;

	i = 0;
	size = ft_lstsize(list_cub);
	if (!(map = (char**)ft_calloc(size + 1, sizeof(char*))))
		return (0);
	win->map = map;
	len = cub_find_big_len(list_cub);
	while (i < size)
	{
		string = list_cub->content;
		if (!(map[i] = (char*)ft_calloc(len + 1, sizeof(char))))
			return (0);
		ft_memset(map[i], ' ', len);
		ft_memcpy(map[i], string, ft_strlen(string));
		list_cub = list_cub->next;
		i++;
	}
	return (1);
}
