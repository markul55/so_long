NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
OBJ_DIR = obj

SRCS = \
	$(SRC_DIR)/so_long.c \
	$(SRC_DIR)/key_binds.c \
	$(SRC_DIR)/movement.c \
	$(SRC_DIR)/put_image.c \
	$(SRC_DIR)/errors.c \
	$(SRC_DIR)/check_path.c \
	$(SRC_DIR)/map_generation.c \
	$(SRC_DIR)/map_print.c \
	$(SRC_DIR)/window_manager.c \
	$(SRC_DIR)/map_checker.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -lmlx -lXext -lX11
MLX_DIR = ./libs

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -L$(MLX_DIR) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean
	$(MAKE) -C $(LIBFT_DIR) re
	$(MAKE) all

.PHONY: all clean fclean re
