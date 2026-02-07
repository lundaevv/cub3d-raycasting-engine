/*
structs/enums/typedefs only
no function prototypes here
*/

#ifndef TYPES_H
#define TYPES_H

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
  int endian;
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
  t_vec dir; /* Direction vector x,y */
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
  void *window;  /* MLX window handle */
  t_img frame;   /* MLX image buffer handle */
  int window_w;  /* window width */
  int window_h;  /* window height */
} t_mlx;

typedef struct s_game {
  t_mlx mlx; /* MLX handles + screen size */
  t_graphics graphics;
  t_config config; /* parsed config/paths/colors */
  t_map map;       /* map grid and dimensions */
  t_player player; /* player position and camera */
} t_game;

#endif
