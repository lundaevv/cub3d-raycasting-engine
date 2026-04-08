# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 19:41:52 by vlundaev          #+#    #+#              #
#    Updated: 2026/03/18 11:54:24 by vlundaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

UNAME_S := $(shell uname -s)
MAKEFLAGS += --no-print-directory

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -std=gnu11 -Iincludes -Ilibft/includes -Imlx
RM = rm -f
RMDIR = rm -rf

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
MLXDIR = mlx
MLX_LOG = .mlx_build.log

ifeq ($(UNAME_S),Darwin)
MLX_REPO = https://github.com/alternateash/minilibx_macos_metal_backup.git
MLX = $(MLXDIR)/libmlx.dylib
LIBFLAGS = -Lmlx -lmlx -framework Metal -framework AppKit -framework OpenGL -lm \
	-Wl,-rpath,@loader_path -Wl,-rpath,@loader_path/$(MLXDIR)
MLX_COPY = cp $(MLX) ./libmlx.dylib
else
MLX_REPO = https://github.com/42paris/minilibx-linux.git
MLX = $(MLXDIR)/libmlx.a
LIBFLAGS = -Lmlx -lmlx -lXext -lX11 -lm
MLX_COPY = true
endif

OBJDIR = obj

SRC_INIT = \
	src/init/init.c \
	src/init/argc.c \
	src/init/init_graphics.c

SRC_UTILS = \
	src/utils/get_cell_type.c \
	src/utils/get_time_sec.c \
	src/utils/mlx_mouse_compat_apple.c \
	src/utils/mlx_mouse_compat_linux.c \
	src/utils/mlx_platform_compat_apple.c \
	src/utils/mlx_platform_compat_linux.c \
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
	src/interaction/on_mouse_move.c \
	src/interaction/door.c

SRC_RENDER = \
	src/render/raycast.c \
	src/render/get_texture_x.c \
	src/render/draw_door.c \
	src/render/draw_map.c \
	src/render/render_overlay.c \
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

all: $(NAME)

$(LIBFT):
	@printf "[LIBFT] building libft\n"
	@$(MAKE) -C $(LIBFTDIR)

$(MLX):
	@{ \
		if [ ! -f "$(MLX)" ]; then \
			printf "[MLX]   missing -> cloning\n"; \
			$(RMDIR) "$(MLXDIR)"; \
			git clone --quiet "$(MLX_REPO)" "$(MLXDIR)"; \
			if [ "$(UNAME_S)" = "Linux" ]; then \
				sed -i '/^CFLAGS[[:space:]]*=/a\CFLAGS+=-std=gnu11' $(MLXDIR)/Makefile.gen; \
				sed -i '/^CFLAGS[[:space:]]*=/a\CFLAGS+=-std=gnu11' $(MLXDIR)/test/Makefile.gen; \
				sed -i '/^CFLAGS[[:space:]]*=/a\CFLAGS+=-std=gnu11' $(MLXDIR)/Makefile.mk; \
				sed -i '/^CFLAGS[[:space:]]*=/a\CFLAGS+=-std=gnu11' $(MLXDIR)/test/Makefile.mk; \
			fi; \
		fi; \
		printf "[MLX]   building mlx\n"; \
		if ! $(MAKE) -C "$(MLXDIR)" >"$(MLX_LOG)" 2>&1; then \
			cat "$(MLX_LOG)"; \
			$(RM) "$(MLX_LOG)"; \
			exit 1; \
		fi; \
		$(RM) "$(MLX_LOG)"; \
	}

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "[CC]    %s\n" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@printf "[LD]    %s\n" "$(NAME)"
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFLAGS) $(MLX) $(LIBFT) -o $(NAME)
	@printf "[CP]    runtime mlx\n"
	@$(MLX_COPY)
	@printf "[OK]    build complete -> %s\n" "$(NAME)"

clean:
	@printf "[RM]    %s\n" "$(OBJDIR)"
	@$(RMDIR) $(OBJDIR)
	@printf "[LIBFT] clean\n"
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@printf "[RM]    %s\n" "$(NAME)"
	@$(RM) $(NAME)
	@printf "[RM]    %s\n" "libmlx.dylib"
	@$(RM) libmlx.dylib
	@printf "[LIBFT] fclean\n"
	@$(MAKE) -C $(LIBFTDIR) fclean

mlxDel:
	@printf "[RM]    %s\n" "$(MLXDIR)"
	@$(RMDIR) $(MLXDIR)

allClean: fclean mlxDel

re: fclean all

.PHONY: all clean fclean re mlxDel allClean
