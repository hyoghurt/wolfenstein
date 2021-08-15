/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:23:56 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/02/28 14:31:48 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define SCALE 64
# define SPEED 30

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_spr
{
	float			x;
	float			y;
	float			ang;
	int				h;
	struct s_spr	*next;
}					t_spr;

typedef struct		s_img
{
	void			*img;
	void			*addr;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_img			no;
	t_img			so;
	t_img			we;
	t_img			ea;
	t_img			spr;
	t_spr			*sprite;
	int				floor;
	int				ceiling;
	char			**map;
	int				width;
	int				height;
	float			pl_x;
	float			pl_y;
	float			dir;
	float			start;
	float			end;
	float			ray_x;
	float			ray_y;
}					t_win;

int					cub_create_bmp_file(t_win *win, char *string);
void				my_mlx_pixel_put(t_win *data, int x, int y, int color);
int					ft_gnl(int fd, char **line);
int					cub_parser(t_win *win, char *string);
void				cub_print_ray(t_win *win, int scl);
void				cub_print_pl(t_win *win, int scl);
void				cub_print_map_wall(t_win *win, int scl_m);
void				cub_print_map(t_win *win, int scl_m);
int					key_hook(int keycode, t_win *win);
void				cub_keycode_w(t_win *win);
void				cub_keycode_s(t_win *win);
void				cub_keycode_d(t_win *win);
void				cub_keycode_a(t_win *win);
void				cub_print_background(t_win *win);
void				cub_print_wall(t_win *win, int j, int *h_wall);
void				cub_print_ray_wall(t_win *win, int *h_wall);
int					cub_print_screen(t_win *win);
void				cub_print_images(t_win *win);
int					cub_print_window(t_win *win);
void				cub_print_sprite(t_win *win, int *h_wall);
void				cub_print_sprite_one(t_win *win, t_spr *spr, int *h_wall);
void				cub_print_sprite_one_next(t_win *win, t_spr *spr,
					int pos_x, int i);
void				cub_sprite_sort(t_spr *spr);
void				cub_sprite_sort_buf(t_spr *ptr, t_spr *tu);
void				cub_sprite_calc(t_win *win);
int					cub_value_resolution(char *s, t_win *win);
int					cub_resolution(t_list *list_cub, t_win *win);
int					cub_identifier(t_list *list_cub);
int					cub_help_my(char *s1, char *s2);
int					cub_err(char *string, t_list *list_cub, t_win *win);
int					cub_exit(t_win *win);
void				cub_exit_after(char *string, t_list *list_cub, t_win *win);
int					cub_bmp_exit(char *s, t_list *list_cub, t_win *win);
int					cub_map(t_list *list_cub, t_win *win);
int					cub_create_bi_map(t_list *list_cub, t_win *win);
int					cub_check_wall_map(char **map, int i);
int					cub_check_space_map(char **map, int i);
int					cub_check_trash_map(char **map, int i);
int					cub_check_err_map(t_win *win);
int					cub_check_file_name(char *string);
int					create_trgb(int t, int r, int g, int b);
int					cub_player(t_win *win);
int					cub_player_position(t_win *win);
void				cub_player_dir(t_win *win);
int					cub_fine_color_string(int *itog, char *string);
int					cub_floor_ceiling(t_list *list_cub, t_win *win);
int					get_color_images(t_img *img, int x, int y);
int					get_color_sprite(t_img *img, int x, int y);
int					cub_texture_put(t_win *win, t_img *img, char *s);
int					cub_texture_init(t_win *win, t_img *img, char *string);
int					cub_texture(t_list *list_cub, t_win *win);
void				cub_print_sprite(t_win *win, int *h_wall);
void				cub_create_bmp(t_win *win, char *string);
void				bmp_file_header(t_win *win, int fd);
void				bmp_info_header(t_win *win, int fd);
void				bmp_pixel_data(t_win *win, int fd);
t_spr				*cub_newspr(int y, int x);
void				cub_add_back_spr(t_spr **sprite, t_spr *new);
int					cub_sprite(t_win *win);
void				free_list(void *s);
void				free_map(char **map);
void				free_spr(t_spr *sprite);
int					cub_err(char *string, t_list *list_cub, t_win *win);
int					cub_isspace(char s);

#endif
