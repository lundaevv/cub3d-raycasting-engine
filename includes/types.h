/*
structs/enums/typedefs only
no function prototypes here
*/

#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

// NOTE: Additional enum and struct for storing result of calculations from
// raycast.
typedef enum e_cell_side { NORTH_S, SOUTH_S, WEST_S, EAST_S } t_cell_side;

typedef struct s_raycast_data {
  double len;
  t_cell_side side;
  // double tex_x;
} t_raycast_data;

typedef enum e_cell { c_unknown, c_empty, c_wall, c_door } t_cell;

// NOTE: Struct for storing curently pressed button
typedef struct s_input {
  double last_time;
  int w;
  int s;
  int a;
  int d;
} t_input;

// TODO: Decide should it be a double or int?
typedef struct s_vec {
  double x;
  double y;
} t_vec;

typedef struct s_img {
  void *img;
  char *a;
  int bpp;
  int ll;
  int e;
  int w;
  int h;
} t_img;

typedef struct s_map {
  char **grid; /* 2D map layout: array of strings */
  int cols;
  int rows;
} t_map;

typedef struct s_player {
  t_vec pos; /* Player position x,y */
  double angle;
} t_player;

typedef struct s_config {
  char *path_nw; /* texture path: North wall */
  char *path_sw; /* texture path: South wall */
  char *path_ww; /* texture path: West wall */
  char *path_ew; /* texture path: East wall */
                 // int		floor_rgb;		/* floor color packed as
  // 0xRRGGBB */ int		ceil_rgb;		/* ceiling color packed
  // as 0xRRGGBB */
} t_config;

typedef struct s_graphics {
  // array of sprites
  // array of textures
  // floor and ceiling colors
} t_graphics;

typedef struct s_mlx {
  void *context; /* MLX context handle */
  void *win;     /* MLX window handle */
  t_img frame;   // Image which storing 1 game frame to be rendered
  int win_w;     /* Window width */
  int win_h;     /* Window height */
} t_mlx;

typedef struct s_game {
  t_mlx mlx; /* MLX handles + screen size */
  t_graphics graphics;
  t_config config; /* parsed config/paths/colors */
  t_map map;       /* map grid and dimensions */
  t_player player; /* player position and camera */
  t_input inp;     /* currently pressed buttons */
} t_game;

#endif
