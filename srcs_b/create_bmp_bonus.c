/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:23:35 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/22 15:25:52 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		cub_bmp_exit(char *s, t_list *list_cub, t_win *win)
{
	cub_err(s, list_cub, win);
	exit(0);
}

void	cub_create_bmp(t_win *win, char *string)
{
	size_t	len;
	int		fd;

	if ((len = ft_strlen(string)) < 6)
		len = 6;
	if (ft_memcmp("--save", string, len) != 0)
		cub_bmp_exit("Error\n*argv[2]\n", 0, win);
	if ((fd = open("screenshot.bmp", O_RDWR | O_TRUNC)) < 0)
	{
		if ((fd = open("screenshot.bmp", O_CREAT | S_IWRITE)) < 0)
			cub_bmp_exit("Error\n*fd argv[2]\n", 0, win);
		close(fd);
		if ((fd = open("screenshot.bmp", O_RDWR | O_TRUNC)) < 0)
			cub_bmp_exit("Error\n*fd argv[2]\n", 0, win);
	}
	cub_print_images(win);
	bmp_file_header(win, fd);
	bmp_info_header(win, fd);
	bmp_pixel_data(win, fd);
	close(fd);
	cub_bmp_exit("Creat file \"screenshot.bmp\"\n", 0, win);
}

void	bmp_file_header(t_win *win, int fd)
{
	unsigned int	pix_data_offset;
	unsigned int	file_size;

	pix_data_offset = 54;
	file_size = 54 + (win->width * win->height * 4);
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0", 2);
	write(fd, "\0\0", 2);
	write(fd, &pix_data_offset, 4);
}

void	bmp_info_header(t_win *win, int fd)
{
	unsigned int	header_size;
	unsigned int	planes;
	unsigned int	bbp;
	unsigned int	image_size;

	header_size = 40;
	planes = 1;
	bbp = 32;
	image_size = win->width * win->height;
	write(fd, &header_size, 4);
	write(fd, &win->width, 4);
	write(fd, &win->height, 4);
	write(fd, &planes, 2);
	write(fd, &bbp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, "\0\0\0\0", 4);
}

void	bmp_pixel_data(t_win *win, int fd)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		color;

	i = 0;
	j = win->width * win->height;
	while (i <= win->width * win->height)
	{
		x = i % win->width;
		y = j / win->width;
		color = get_color_sprite(&win->img, x, y);
		write(fd, &color, 4);
		i++;
		j--;
	}
}
