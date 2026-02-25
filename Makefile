# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 15:30:59 by vlundaev          #+#    #+#              #
#    Updated: 2026/02/25 15:31:00 by vlundaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile
NAME    = cub3D

CC      = cc
# CFLAGS  = -Wall -Wextra -Werror -Imlx -g
CFLAGS  = -g -std=gnu11
LIBFLAGS = -Lmlx -lmlx -lXext -lX11 -lm

LIBFTDIR = libft
LIBFT    = $(LIBFTDIR)/libft.a
MLXDIR   = mlx
MLX      = $(MLXDIR)/libmlx.a

SRC_UTILS = src/utils/get_time_sec.c
SRC      = $(SRC_UTILS) \
					 src/render/render_utils.c

OBJS     = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	@{ \
		if [ ! -f "$(MLX)" ]; then echo "libmlx.a missing → recloning"; \
			rm -rf "$(MLXDIR)"; \
			git clone https://github.com/42paris/minilibx-linux.git "$(MLXDIR)"; \
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
