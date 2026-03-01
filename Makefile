NAME        = fractol

CC          = cc
CFLAGS = -Wall -Wextra -Werror -I.

# Uncomment the correct line for your system:
MLX_FLAGS   = -Lmlx -lmlx -framework OpenGL -framework AppKit
# MLX_FLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lX11 -lXext -lm

LIBFT_DIR   = libft
MLX_DIR     = mlx

SRCS        = main.c init.c parse.c hooks.c render.c \
              complex.c color.c utils.c
OBJS        = $(SRCS:.c=.o)

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re