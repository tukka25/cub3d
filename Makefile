# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 00:30:54 by talsaiaa          #+#    #+#              #
#    Updated: 2023/07/08 19:00:10 by talsaiaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

SRCS =	cub3d.c              \
		drawing.c            \
		hooks.c              \
		rotation.c           \
		raycasting.c         \
		raycasting_utils.c	\
		utils.c              \
		moves_utils.c         \
		gnl/get_next_line.c gnl/get_next_line_utils.c \
		parsing/cu_utils.c parsing/cu_saving_file.c \
		parsing/cu_saving_components.c parsing/freedom.c \
		parsing/cu_strtrimchar.c parsing/cu_texture_utils.c \
		parsing/cu_saving_colors.c parsing/cu_saving_map.c \
		parsing/cu_check_map.c parsing/cu_map_utils.c \

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	cd libft && make

MLX		:=

LIB		:=

INCLUDE	:=

LINKS	:=

GCC		=	gcc

FLAGS	=	-g -Wall -Wextra -Werror -fsanitize=address

OS		=	$(shell uname)

ifeq ($(OS), Linux)
	MLX += cd mlx_linux && make
	LIB += libft/libft.a mlx/libmlx.a
	INCLUDE += -I/usr/include -Imlx_linux -Iutils -O3
	LINKS += -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif
ifeq ($(OS), Darwin)
	MLX += cd mlx && make
	LIB += libft/libft.a mlx/libmlx.a
	INCLUDE += -I mlx
	LINKS += -L mlx -l mlx -framework OpenGL -framework AppKit
endif

all: comp_start $(NAME) 
	@printf '		          ▓▓▓▓▓▓▓▓                                                                 \n'
	@printf '                        ▓▓▓▓▓▓▓▓▓▓██  ▓▓▓▓▓▓▓▓                                            \n'
	@printf '                      ▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓                                        \n'
	@printf '                    ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓                                      \n'
	@printf '                ▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒                                    \n'
	@printf '              ▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓                                  \n'
	@printf '            ▓▓▓▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓                                \n'
	@printf '            ▓▓▓▓▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓████                            \n'
	@printf '          ▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓                        \n'
	@printf '          ▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓                    \n'
	@printf '          ▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓██                  \n'
	@printf '          ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓██                \n'
	@printf '          ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓██              \n'
	@printf '          ██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓██            \n'
	@printf '            ██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓██          \n'
	@printf '            ░░▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██          \n'
	@printf '              ██▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓░░      \n'
	@printf '              ██▓▓▓▓██▓▓▓▓██▓▓▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒░░░░██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓░░      \n'
	@printf '                ██▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒░░░░▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓██░░    \n'
	@printf '                ▓▓▓▓▒▒██▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓██▒▒░░░░▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓      \n'
	@printf '                ▓▓▓▓▒▒▓▓██▓▓▒▒▓▓▓▓░░░░▓▓▓▓▒▒▒▒▒▒▓▓██▒▒▒▒░░░░░░░░██▒▒▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓      \n'
	@printf '                ██▓▓░░░░▓▓██▓▓▓▓▓▓░░░░██▓▓▒▒▓▓██░░░░▒▒░░░░░░░░░░▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓      \n'
	@printf '                ░░▓▓░░░░▒▒▓▓▓▓▓▓▓▓░░░░▒▒▓▓▓▓██▒▒░░░░▒▒▒▒░░░░░░░░▒▒▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓      \n'
	@printf '                  ██░░░░▒▒▒▒▓▓▓▓▓▓░░░░░░▒▒▒▒░░▓▓▓▓▓▓░░▒▒░░░░░░░░░░▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓    \n'
	@printf '                  ██▓▓░░      ▓▓██░░░░░░░░      ▓▓██  ░░░░░░░░░░░░▓▓▒▒▒▒▒▒▒▒▒▒    ░░▒▒██  \n'
	@printf '                  ██▓▓░░    ██▓▓██░░░░░░░░    ██▓▓▓▓  ░░░░░░░░░░░░▓▓▒▒▒▒▒▒▓▓░░░░  ░░░░▒▒██\n'
	@printf '                ▓▓▓▓▓▓░░    ██▓▓██░░░░░░░░    ▓▓▓▓██  ░░░░░░░░░░░░▓▓▒▒▒▒▓▓▒▒░░░░▒▒░░░░▒▒██\n'
	@printf '                ▓▓▓▓░░░░░░  ▓▓██▓▓░░░░░░░░░░  ▓▓██▓▓░░░░░░░░░░░░░░▓▓▒▒▒▒░░░░░░░░▓▓▒▒░░░░██\n'
	@printf '              ██▓▓▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ░░░░░░▒▒▓▓▒▒░░░░░░▒▒▓▓░░░░░░██\n'
	@printf '              ██▓▓░░        ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▒▒▒▒▒▒░░░░░░▓▓▒▒░░░░░░██\n'
	@printf '            ▓▓▓▓▒▒░░          ░░░░░░░░░░░░░░▒▒▒▒▓▓▒▒▒▒░░░░░░░░▓▓▒▒▒▒▒▒▒▒░░░░░░▒▒░░░░░░░░██\n'
	@printf '            ██▓▓░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░██  \n'
	@printf '          ▒▒▓▓▓▓▒▒░░░░░░░░░░░░░░░░░░░░▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓░░░░░░░░░░░░██  \n'
	@printf '          ▓▓▓▓▓▓▓▓▒▒░░░░░░░░░░░░▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒░░░░▒▒▓▓░░  \n'
	@printf '        ▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓░░    \n'
	@printf '      ██▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓          \n'
	@printf '    ▓▓▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓          \n'
	@printf '    ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓██            \n'
	@printf '  ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓██            \n'
	@printf '  ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓░░            \n'
	@printf '  ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓██              \n'
	@printf '  ▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓██                \n'
	@printf '  ██▓▓▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓██                \n'
	@printf '   ██▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓██                   \n'
	@printf '    ██▓▓▓▓▓▓▓▓██▓▓▒▒▒▒▒▒▒▒▒▒▓▓██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓██░░                  \n'
	@printf '      ██▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓██▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓██                      \n'
	@printf '        ██▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                        \n'
	@printf '          ▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████                            \n'
	@printf '                    ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                \n'
	@printf '                        ▓▓████▓▓██    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓██                                    \n'

$(NAME): $(OBJS)
	@$(GCC) $(FLAGS) $(OBJS) $(LINKS) $(LIB) -o $(NAME)
	@tput setaf 2
	@printf 'Executable ready\n'
	@tput setaf 7

comp_start:
	@$(LIBFT)
	@$(MLX)
	@tput setaf 2
	@printf 'LIBFT Compiled\n'
	@tput setaf 7

.c.o:
	@$(GCC) $(FLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean
	@cd mlx && make clean
	@cd mlx_linux && make clean
	@tput setaf 2
	@printf '.o files are removed\n'
	@tput setaf 7

fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean
	@tput setaf 2
	@printf '.o and executable is removed\n'
	@tput setaf 7

re: fclean all

.PHONY: all comp_start clean fclean re

