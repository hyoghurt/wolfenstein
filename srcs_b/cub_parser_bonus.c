/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_bonus.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:25:00 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/28 14:27:42 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		cub_result_parser(t_list *list_cub, t_win *win)
{
	if (!cub_identifier(list_cub))
		return (cub_err(0, list_cub, 0));
	if (!cub_resolution(list_cub, win))
		return (cub_err(0, list_cub, 0));
	if (!cub_floor_ceiling(list_cub, win))
		return (cub_err(0, list_cub, 0));
	if (!cub_texture(list_cub, win))
		return (cub_err(0, list_cub, win));
	if (!cub_map(list_cub, win))
		return (cub_err(0, list_cub, win));
	ft_lstclear(&list_cub, free_list);
	if (!cub_sprite(win))
		return (cub_err(0, 0, win));
	if (!cub_player(win))
		return (cub_err(0, 0, win));
	if (!cub_check_err_map(win))
		return (cub_err(0, 0, win));
	return (1);
}

int		cub_create_list(int fd, t_list **list_cub)
{
	int		gnl;
	char	*line;
	t_list	*new;

	gnl = 1;
	while (gnl)
	{
		gnl = ft_gnl(fd, &line);
		if (gnl >= 0)
		{
			if (!(new = ft_lstnew(line)))
				return (cub_err("Error\n*malloc create list\n", *list_cub, 0));
			ft_lstadd_back(list_cub, new);
		}
	}
	if (gnl < 0)
		return (cub_err("Error\n*gnl\n", *list_cub, 0));
	return (1);
}

int		cub_check_file_name(char *string)
{
	char	*tmp;

	if (!string)
		return (0);
	if (!(tmp = ft_strnstr(string, ".cub", ft_strlen(string))))
		return (0);
	if (*(tmp + 4))
		return (0);
	return (1);
}

int		cub_parser(t_win *win, char *string)
{
	int		fd;
	int		gnl;
	t_list	*list_cub;

	list_cub = 0;
	if (!cub_check_file_name(string))
		return (cub_err("Error\n*file_name\n", 0, 0));
	if ((fd = open(string, O_RDONLY)) < 0)
		return (cub_err("Error\n*fd\n", 0, 0));
	gnl = cub_create_list(fd, &list_cub);
	close(fd);
	if (!gnl)
		return (0);
	if (!cub_result_parser(list_cub, win))
		return (0);
	return (1);
}
