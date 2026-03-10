/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:41 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/10 12:01:19 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include <stdint.h>

// NOTE: Additional enum and struct for storing result of calculations from
// raycast.
typedef enum e_cell_side { NORTH_S, SOUTH_S, WEST_S, EAST_S } t_cell_side;

typedef struct s_raycast_data {
  double len;
  t_cell_side side;
  double tex_x;
} t_raycast_data;

typedef enum e_cell { c_unknown, c_empty, c_wall, c_door } t_cell;

// NOTE: Struct for storing curently pressed button
typedef struct s_input
{
	double			last_time;
	int				w;
	int				s;
	int				a;
	int				d;
}	t_input;

// TODO: Decide should it be a double or int?
typedef struct s_vec
{
	double			x;
	double			y;
}	t_vec;

typedef struct s_img
{
	void			*img;
	char			*a;
	int				bpp;
	int				ll;
	int				e;
	int				w;
	int				h;
}	t_img;

typedef struct s_map {
  char **grid; /* 2D map layout: arr of strings */
  int cols;
  int rows;
} t_map;

typedef struct s_player
{
	t_vec			pos;			/* Player position x,y */
	double			angle;
}	t_player;

// Struct for storing parsed config values, stored in t_game after parsing.
typedef struct s_config {
  char *path_nw;
  char *path_sw;
  char *path_ww;
  char *path_ew;
  char *path_door_closed;
  char *path_door_open;
  char *path_sprite_anim;
  int floor_rgb;
  int ceil_rgb;
} t_config;

// Enum for texture IDs, used to index into t_graphics.tex array.
typedef enum e_tex_id {
  TEX_NW,
  TEX_SW,
  TEX_WW,
  TEX_EW,
  TEX_DOOR_CLOSED,
  TEX_DOOR_OPEN,
  TEX_SPRITE_ANIM,
  TEX_COUNT
} t_tex_id;

// Struct for loaded textures and floor/ceiling colors, stored in t_game.
typedef struct s_graphics {
  t_img tex[TEX_COUNT];   /* loaded textures */
  unsigned int floor_rgb; /* floor color as 0xRRGGBB */
  unsigned int ceil_rgb;  /* ceiling color as 0xRRGGBB */
} t_graphics;

// Struct for MLX handles and screen size, stored in t_game.
typedef struct s_mlx {
  void *context; /* MLX context handle */
  void *win;     /* MLX window handle */
  t_img frame;   /* Image storing frame to render */
  int win_w;     /* Window width */
  int win_h;     /* Window height */
} t_mlx;

// Main game struct, passed to all functions. Stores all game state.
typedef struct s_game {
  t_mlx mlx;           /* MLX handles + screen size */
  t_graphics graphics; /* Loaded textures and colors */
  char *map_path;      /* path to input .cub (argv[1]) */
  t_config config;     /* parsed config/paths/colors */
  t_map map;           /* map grid and dimensions */
  t_player player;     /* player position and camera */
  t_input inp;         /* currently pressed buttons */
} t_game;

// Main game struct, passed to all functions. Stores all game state.
typedef struct s_game
{
	t_mlx			mlx;			/* MLX handles + screen size */
	t_graphics		graphics;		/* Loaded textures and colors */
	char			*map_path;		/* path to input .cub (argv[1]) */
	t_config		config;			/* parsed config/paths/colors */
	t_map			map;			/* map grid and dimensions */
	t_player		player;			/* player position and camera */
	t_input			inp;			/* currently pressed buttons */
}	t_game;

#endif