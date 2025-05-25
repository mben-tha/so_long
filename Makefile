# === Variables de compilation ===
NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11 -lm

# === Dossiers ===
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
GNL_DIR		= get_next_line

# === Fichiers sources ===
SRCS	= \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/create_map.c \
	$(SRC_DIR)/init_map.c \
	$(SRC_DIR)/display_map.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c \
	$(LIBFT_DIR)/ft_strjoin_free.c # ou src/utils/ft_strjoin_free.c

OBJS	= $(SRCS:.c=.o)
OBJSF	= $(subst $(SRC_DIR),$(OBJ_DIR),$(OBJS))

# === Règles ===

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -o $(NAME) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(SRC_DIR) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


