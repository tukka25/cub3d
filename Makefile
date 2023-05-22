NAME = cud3d

SRCS =	cub3d.c              \
		parsing.c            \
		error_free_exit.c    \
		contents_parsing.c   \
		utils.c              \
		utils2.c             \
		drawing.c            \
		hooks.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g3 -Wall -Werror -Wextra -fsanitize=address

all:$(NAME)

$(NAME):$(OBJS)
	@make -C libft
	@make -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a ./mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)
	(cd libft && make clean)
	(cd mlx && make clean)
fclean: clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a

re:fclean all