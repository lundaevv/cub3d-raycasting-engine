# Makefile
NAME    = cub3D

CC      = cc
# CFLAGS  = -Wall -Wextra -Werror -Imlx -g
CFLAGS  = -g -std=gnu11 -Iincludes
LIBFLAGS = -Lmlx -lmlx -lXext -lX11 -lm

LIBFTDIR = libft
LIBFT    = $(LIBFTDIR)/libft.a
MLXDIR   = mlx
MLX      = $(MLXDIR)/libmlx.a

SRC_UTILS = src/utils/get_time_sec.c \
						src/utils/get_cell_type.c
SRC_RENDER = src/render/raycast.c \
						 src/render/render_utils.c
SRC      = $(SRC_UTILS) \
					 $(SRC_RENDER)

OBJS     = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	@{ \
		if [ ! -f "$(MLX)" ]; then echo "libmlx.a missing → recloning"; \
			rm -rf "$(MLXDIR)"; \
			git clone https://github.com/42paris/minilibx-linux.git "$(MLXDIR)"; \
			sed -i '/^CFLAGS[[:space:]]*=/a\CFLAGS+=-std=gnu11' $(MLXDIR)/Makefile.gen; \
			sed -i '/^CFLAGS[[:space:]]*=/a\CFLAGS+=-std=gnu11' $(MLXDIR)/Makefile.mk; \
		fi; \
		$(MAKE) -C "$(MLXDIR)"; \
	}

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) main.c $(CFLAGS) $(LIBFLAGS) $(MLX) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

mlxDel:
	rm -rf mlx

allClean: fclean mlxDel

render: ${MLX} ${LIBFT} ${OBJS}
	$(CC) renderer_main.c $(OBJS) $(CFLAGS) $(LIBFLAGS) $(MLX) $(LIBFT) -o render_exe

re: fclean all

