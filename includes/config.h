/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:56 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/18 12:16:11 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "math.h"

// Tile sizes
# define TILE_SIZE 40
# define FOV M_PI_2
# define WORLD_HEIGHT 1
# define DOOR_SPRITE_CNT 7.0
# define SPRITES_PER_SEC 35.0

// Map textures
# define TEXTURE_EMPTY "textures/tiles/empty.xpm"
# define TEXTURE_WALL "textures/tiles/wall.xpm"
# define TEXTURE_COLLECTIBLE "textures/tiles/collectible.xpm"
# define TEXTURE_EXIT "textures/tiles/exit.xpm"

// Player textures
# define TEXTURE_PLAYER_IDLE "textures/player/idle.xpm"

// Linux (X11) keycodes
# define LINUX
# ifdef LINUX

#  define KEY_PRESS 2
#  define KEY_RELEASE 3
#  define DESTROY_NOTIFY 17
#  define KEY_PRESS_MASK 1L
#  define KEY_RELEASE_MASK 2L
#  define MOTION_NOTIFY 6
#  define POINTER_MOTION_MASK 64L

#  define K_ESC 65307

#  define K_W 119
#  define K_A 97
#  define K_S 115
#  define K_D 100
#  define K_M 109
#  define K_E 101

#  define K_UP 65362
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_RIGHT 65363

# else

// macOS (Cocoa, 42's MiniLibX) keycodes
#  define K_ESC 53
#  define K_W 13
#  define K_A 0
#  define K_S 1
#  define K_D 2
#  define K_UP 126
#  define K_DOWN 125
#  define K_LEFT 123
#  define K_RIGHT 124
# endif

#endif
