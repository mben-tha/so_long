SRCS = main.c create_map.c display_map.c free_map.c parsing_map.c get_next_line.c \
	get_next_line_utils.c handle_key.c init_game.c move_player.c solve.c \
	ft_split.c utils.c 

OBJS = ${SRCS:.c=.o}

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = so_long
FLAGS = -Imlx -Lmlx -lmlx -lXext -lX11 -lm


all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C "mlx/"
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all