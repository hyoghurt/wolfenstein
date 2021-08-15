/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_identifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:24:33 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/21 15:24:35 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		cub_identifier(t_list *list_cub)
{
	char	*s;
	int		count;

	count = 0;
	while (list_cub)
	{
		s = list_cub->content;
		count += cub_help_my(s, "R");
		count += cub_help_my(s, "NO");
		count += cub_help_my(s, "SO");
		count += cub_help_my(s, "WE");
		count += cub_help_my(s, "EA");
		count += cub_help_my(s, "S");
		count += cub_help_my(s, "F");
		count += cub_help_my(s, "C");
		list_cub = list_cub->next;
	}
	if (count != 8)
		return (cub_err("Error\n*count identifier\n", 0, 0));
	return (1);
}

int		cub_help_my(char *s1, char *s2)
{
	while (!cub_isspace(*s1) || *s2)
	{
		if (*s1++ != *s2++)
			return (0);
	}
	return (1);
}
