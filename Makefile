# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/21 18:42:58 by hyoghurt          #+#    #+#              #
#    Updated: 2021/02/22 17:54:30 by hyoghurt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	cub3D
SRC		=	srcs/main.c					\
			srcs/ft_gnl.c				\
			srcs/cub_parser.c			\
			srcs/cub_print_map.c		\
			srcs/cub_key_hook.c 		\
			srcs/cub_print_screen.c		\
			srcs/cub_resolution.c		\
			srcs/cub_map.c				\
			srcs/cub_check_err_map.c	\
			srcs/cub_player.c			\
			srcs/cub_floor_ceiling.c	\
			srcs/cub_texture.c			\
			srcs/cub_print_sprite.c		\
			srcs/cub_sprite_calc_sort.c	\
			srcs/cub_print_background.c	\
			srcs/cub_print_wall.c		\
			srcs/create_bmp.c			\
			srcs/cub_sprite.c			\
			srcs/cub_exit.c				\
			srcs/cub_identifier.c

SRC_B	=	srcs_b/main_bonus.c						\
			srcs_b/ft_gnl_bonus.c					\
			srcs_b/cub_parser_bonus.c				\
			srcs_b/cub_print_map_bonus.c			\
			srcs_b/cub_key_hook_bonus.c 			\
			srcs_b/cub_print_screen_bonus.c			\
			srcs_b/cub_resolution_bonus.c			\
			srcs_b/cub_map_bonus.c					\
			srcs_b/cub_check_err_map_bonus.c		\
			srcs_b/cub_player_bonus.c				\
			srcs_b/cub_floor_ceiling_bonus.c		\
			srcs_b/cub_texture_bonus.c				\
			srcs_b/cub_print_sprite_bonus.c			\
			srcs_b/cub_sprite_calc_sort_bonus.c		\
			srcs_b/cub_print_background_bonus.c		\
			srcs_b/cub_print_wall_bonus.c			\
			srcs_b/create_bmp_bonus.c				\
			srcs_b/cub_sprite_bonus.c				\
			srcs_b/cub_exit_bonus.c					\
			srcs_b/cub_identifier_bonus.c

OBJ		= $(SRC:.c=.o)
OBJ_B	= $(SRC_B:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

%.o:	%.c
		$(CC) $(CFLAGS) -Imlx -Ilibft -I. -c $^ -o $@

$(NAME):$(OBJ)
		make bonus -C libft
		make -C mlx
		$(CC) $(OBJ) -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)

bonus:	$(OBJ_B)
		make bonus -C libft
		make -C mlx
		$(CC) $(OBJ_B) -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)

all:	$(NAME)

clean:	
		make clean -C libft
		make clean -C mlx
		rm -rf $(OBJ)
		rm -rf $(OBJ_B)

fclean:	clean
		make fclean -C libft
		rm -rf $(NAME)

re:		fclean all
		make -C mlx
		make re -C libft

.PHONY:	all clean fclean re
