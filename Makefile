NAME        = fractol

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3 -I. -Iminilibx-linux

MLX_FLAGS   = -Lminilibx-linux -lmlx -L/usr/lib -lX11 -lXext -lm -lpthread

MLX_DIR     = minilibx-linux

SRCS        = main.c init.c parse.c hooks.c render.c \
              complex.c color.c utils.c fractal_math.c
OBJS        = $(SRCS:.c=.o)

MLX         = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	-@make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re