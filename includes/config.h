#ifndef CONFIG_H
# define CONFIG_H
/*
tile size
wall height
door?
textures
sprites' path
keycodes
*/

// Tile sizes
# define TILE_SIZE 40
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
#  define K_ESC    65307
#  define K_W      119
#  define K_A      97
#  define K_S      115
#  define K_D      100
#  define K_UP     65362
#  define K_DOWN   65364
#  define K_LEFT   65361
#  define K_RIGHT  65363
# else
// macOS (Cocoa, 42's MiniLibX) keycodes
#  define K_ESC    53
#  define K_W      13
#  define K_A      0
#  define K_S      1
#  define K_D      2
#  define K_UP     126
#  define K_DOWN   125
#  define K_LEFT   123
#  define K_RIGHT  124
# endif

#endif // CONFIG_H