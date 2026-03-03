# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 19:41:52 by vlundaev          #+#    #+#              #
#    Updated: 2026/03/03 19:50:36 by vlundaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -std=gnu11 -Iincludes -Ilibft/includes -Imlx
LIBFLAGS = -Lmlx -lmlx -lXext -lX11 -lm

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
MLXDIR = mlx
MLX = $(MLXDIR)/libmlx.a

SRC_INIT = \
	src/init/init.c \
	src/init/argc.c	\
	src/init/init_graphics.c

SRC_UTILS = \
	src/utils/get_time_sec.c \
	src/utils/destroy.c

SRC_ERRORS = \
	src/errors/print_msg.c \
	src/errors/print_errno.c

SRC_PARSER = \
	src/parser/parse.c \
	src/parser/parse_file.c \
	src/parser/parse_config.c \
	src/parser/parse_config_utils.c \
	src/parser/parse_store.c \
	src/parser/parse_color.c \
	src/parser/parse_utils.c \
	src/parser/parse_map.c \
	src/parser/parse_map_utils.c \
	src/parser/parse_map_validate.c \
	src/parser/parse_map_normalize.c \
	src/parser/parse_map_closed.c \
	src/parser/parse_player.c

SRC_RENDER = \
	src/render/render.c

SRC = main.c \
	$(SRC_INIT) \
	$(SRC_UTILS) \
	$(SRC_ERRORS) \
	$(SRC_PARSER) \
	$(SRC_RENDER)

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	@{ \
		if [ ! -f "$(MLX)" ]; then echo "libmlx.a missing -> recloning"; \
			rm -rf "$(MLXDIR)"; \
			git clone https://github.com/42paris/minilibx-linux.git "$(MLXDIR)"; \
		fi; \
		$(MAKE) -C "$(MLXDIR)"; \
	}

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFLAGS) $(MLX) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

mlxDel:
	rm -rf $(MLXDIR)

allClean: fclean mlxDel

re: fclean all
