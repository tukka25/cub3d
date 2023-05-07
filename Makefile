NAME = cud3d

SRCS = cub3d.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

all:$(NAME)

$(NAME):$(OBJS)
	@make -C libft
#@make -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJS)
	(cd libft && make clean)
#(cd mlx && make clean)
fclean: clean
	rm -rf $(NAME)
	rm -rf ../libft/libft.a

re:fclean all