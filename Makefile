# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 19:41:52 by vlundaev          #+#    #+#              #
#    Updated: 2026/03/11 18:22:13 by vlundaev         ###   ########.fr        #
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

OBJDIR = obj

SRC_INIT = \
	src/init/init.c \
	src/init/argc.c \
	src/init/init_graphics.c

SRC_UTILS = \
	src/utils/get_cell_type.c \
	src/utils/get_time_sec.c \
	src/utils/destroy.c \
	src/utils/destroy_graphics.c

SRC_ERRORS = \
	src/errors/print_msg.c \
	src/errors/print_errno.c

SRC_PARSER = \
	src/parser/parse.c \
	src/parser/parse_utils.c \
	src/parser/parse_file.c \
	src/parser/config/parse_config.c \
	src/parser/config/parse_config_utils.c \
	src/parser/config/parse_config_store.c \
	src/parser/config/parse_config_color.c \
	src/parser/map/parse_map.c \
	src/parser/map/parse_map_find_block.c \
	src/parser/map/parse_map_utils.c \
	src/parser/map/parse_map_validate.c \
	src/parser/map/parse_map_normalize.c \
	src/parser/map/parse_map_closed.c \
	src/parser/map/parse_map_boundary.c \
	src/parser/entities/parse_player.c \
	src/parser/entities/parse_door.c \
	src/parser/entities/parse_tile.c

SRC_INTERACTION = \
	src/interaction/on_key_actions.c \
	src/interaction/move_player.c \
	src/interaction/rotate_player.c \
	src/interaction/on_mouse_move.c

SRC_RENDER = \
	src/render/raycast.c \
	src/render/get_texture_x.c \
	src/render/draw_map.c \
	src/render/render_utils.c \
	src/render/minimap_map.c \
	src/render/minimap_draw.c \
	src/render/minimap_player.c \
	src/render/render.c

SRC = main.c \
	$(SRC_INIT) \
	$(SRC_UTILS) \
	$(SRC_ERRORS) \
	$(SRC_PARSER) \
	$(SRC_INTERACTION) \
	$(SRC_RENDER)

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

VALID_MAPS = $(wildcard maps/valid/*.cub)
INVALID_MAPS = $(wildcard maps/invalid/*.cub)
TEST_TIMEOUT = 1

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	@{ \
		if [ ! -f "$(MLX)" ]; then echo "libmlx.a missing -> recloning"; \
			rm -rf "$(MLXDIR)"; \
			git clone https://github.com/42paris/minilibx-linux.git "$(MLXDIR)"; \
			sed -i '/^CFLAGS[[:space:]]*=/a\CFLAGS+=-std=gnu11' $(MLXDIR)/Makefile.gen; \
			sed -i '/^CFLAGS[[:space:]]*=/a\CFLAGS+=-std=gnu11' $(MLXDIR)/test/Makefile.gen; \
			sed -i '/^CFLAGS[[:space:]]*=/a\CFLAGS+=-std=gnu11' $(MLXDIR)/Makefile.mk; \
			sed -i '/^CFLAGS[[:space:]]*=/a\CFLAGS+=-std=gnu11' $(MLXDIR)/test/Makefile.mk; \
		fi; \
		$(MAKE) -C "$(MLXDIR)"; \
	}

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFLAGS) $(MLX) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

mlxDel:
	rm -rf $(MLXDIR)

allClean: fclean mlxDel

re: fclean all

.PHONY: all clean fclean re mlxDel allClean