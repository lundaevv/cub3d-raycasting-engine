# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 19:41:52 by vlundaev          #+#    #+#              #
#    Updated: 2026/03/06 15:42:48 by vlundaev         ###   ########.fr        #
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
	src/utils/destroy.c

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
	src/parser/entities/parse_tile.c \
	src/parser/entities/parse_sprite.c

SRC_INTERACTION = src/interaction/on_key_actions.c \
									src/interaction/move_player.c \
									src/interaction/rotate_player.c
SRC_RENDER = src/render/raycast.c \
						 src/render/get_texture_x.c \
						 src/render/draw_map.c \
						 src/render/render_utils.c \
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

test: test_parser

test_parser: $(NAME)
	@if [ -z "$(VALID_MAPS)$(INVALID_MAPS)" ]; then \
		echo "No maps found in maps/valid or maps/invalid"; \
		exit 1; \
	fi
	@if ! command -v timeout >/dev/null 2>&1; then \
		echo "timeout command not found; install coreutils or use a test runner with a different timeout mechanism"; \
		exit 1; \
	fi
	@echo "== Valid maps (expect parse/init to work; render loop stops by timeout) =="; \
	fail=0; \
	for map in $(VALID_MAPS); do \
		tmp=$$(mktemp); \
		timeout $(TEST_TIMEOUT)s ./$(NAME) "$$map" > "$$tmp" 2>&1 || rc=$$?; \
		rc=$${rc:-0}; \
		if [ $$rc -eq 0 ] || [ $$rc -eq 124 ]; then \
			echo "  [PASS] $$map"; \
		else \
			echo "  [FAIL] $$map (exit $$rc)"; \
			cat "$$tmp"; \
			fail=1; \
		fi; \
		rc=; \
		rm -f "$$tmp"; \
	done; \
	if [ $$fail -ne 0 ]; then \
		exit 1; \
	fi; \
	echo "== Invalid maps (expect non-zero) =="; \
	for map in $(INVALID_MAPS); do \
		tmp=$$(mktemp); \
		./$(NAME) "$$map" > "$$tmp" 2>&1 || rc=$$?; \
		rc=$${rc:-0}; \
		if [ $$rc -eq 0 ]; then \
			echo "  [FAIL] $$map (exit 0)"; \
			cat "$$tmp"; \
			fail=1; \
		else \
			echo "  [PASS] $$map"; \
		fi; \
		rc=; \
		rm -f "$$tmp"; \
	done; \
	echo "== CLI tests (expect non-zero) =="; \
	tmp=$$(mktemp); \
	./$(NAME) > "$$tmp" 2>&1; \
	rc=$$?; \
	if [ $$rc -eq 0 ]; then \
		echo "  [FAIL] no-argument mode (exit 0)"; \
		cat "$$tmp"; \
		fail=1; \
	else \
		echo "  [PASS] no-argument mode"; \
	fi; \
	./$(NAME) maps/valid/valid_basic.cub $(firstword $(INVALID_MAPS)) > "$$tmp" 2>&1; \
	rc=$$?; \
	if [ $$rc -eq 0 ]; then \
		echo "  [FAIL] too-many-arguments mode (exit 0)"; \
		cat "$$tmp"; \
		fail=1; \
	else \
		echo "  [PASS] too-many-arguments mode"; \
	fi; \
	./$(NAME) maps/valid/valid_basic.txt > "$$tmp" 2>&1; \
	rc=$$?; \
	if [ $$rc -eq 0 ]; then \
		echo "  [FAIL] bad extension mode (exit 0)"; \
		cat "$$tmp"; \
		fail=1; \
	else \
		echo "  [PASS] bad extension mode"; \
	fi; \
	./$(NAME) maps/this_file_does_not_exist.cub > "$$tmp" 2>&1; \
	rc=$$?; \
	if [ $$rc -eq 0 ]; then \
		echo "  [FAIL] missing-file mode (exit 0)"; \
		cat "$$tmp"; \
		fail=1; \
	else \
		echo "  [PASS] missing-file mode"; \
	fi; \
	rm -f "$$tmp"; \
	if [ $$fail -ne 0 ]; then \
		exit 1; \
	fi; \
	echo "== parser+init tests passed ==";

.PHONY: all clean fclean re mlxDel allClean test test_parser
