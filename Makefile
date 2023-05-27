# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 00:30:54 by talsaiaa          #+#    #+#              #
#    Updated: 2023/05/27 20:43:52 by talsaiaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

SRCS	=	main.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c \
			parsing/cu_args_check.c parsing/cu_print_error.c \
			parsing/cu_saving_file.c parsing/cu_saving_textures.c \
			parsing/freedom.c parsing/cu_init.c parsing/cu_strtrimchar.c \
			parsing/cu_texture_utils.c

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	cd Libft && make

LIB		=	Libft/libft.a

GCC		=	gcc

FLAGS	=	-g -Wall -Wextra -Werror

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
	@$(GCC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	@tput setaf 2
	@printf 'Executable ready\n'
	@tput setaf 7

comp_start:
	@$(LIBFT)
	@tput setaf 2
	@printf 'LIBFT Compiled\n'
	@tput setaf 7

.c.o:
	@$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -rf $(OBJS)
	@cd Libft && make clean
	@tput setaf 2
	@printf '.o files are removed\n'
	@tput setaf 7

fclean: clean
	@rm -rf $(NAME)
	@cd Libft && make fclean
	@tput setaf 2
	@printf '.o and executable is removed\n'
	@tput setaf 7

re: fclean all

.PHONY: all comp_start clean fclean re
