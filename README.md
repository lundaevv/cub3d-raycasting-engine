# cub3D

A small Wolfenstein-style raycaster built for the 42 `cub3D` project.

The project currently includes:
- `.cub` parsing for textures, colors, player spawn, and doors
- map validation for invalid characters, duplicate or missing config fields, open maps, and bad door placement
- wall and door rendering with MiniLibX
- keyboard movement, mouse look toggle, and a minimap

## Team

- Vitalii - [github.com/lundaevv](https://github.com/lundaevv)
- Artem - [github.com/a-kuchmambetov](https://github.com/a-kuchmambetov)

## Build

This project builds on both Linux and macOS.

- Linux: uses `minilibx-linux`
- macOS: uses a Metal-based MiniLibX fork

```sh
make
```

Notes:
- `libft/` must be present locally
- if `mlx/` is missing, the Makefile clones the correct MiniLibX repo automatically for your platform
- on macOS the build also copies `libmlx.dylib` next to the executable

Useful targets:

```sh
make
make clean
make fclean
make re
make mlxDel
make allClean
```

## Norminette Notes

This project is kept compatible with `norminette`, so some implementation choices are intentionally shaped by 42 style constraints.

Common examples:
- functions should stay short, so logic is often split into small helpers instead of one long function
- files should not contain too many functions, so related logic may be distributed across multiple source files
- variable counts inside functions are limited, so temporary values are sometimes moved into helper functions
- preprocessor directives such as `#ifdef` should stay at global scope, so platform-specific behavior is wrapped in dedicated compatibility files instead of being embedded deep inside regular `.c` functions

Examples from this repository:
- MiniLibX platform differences are isolated in `src/utils/mlx_*_compat_*.c`
- minimap overlay logic is split across multiple render files instead of one large render function
- small rendering and parsing helpers are separated to keep function length and variable count within norm limits

## Run

Recommended demo map:

```sh
./cub3D maps/defaults/demo_gif_large.cub
```

Default sample map set:

```sh
./cub3D maps/defaults/default_basic.cub
```

More sample maps are available under:
- `maps/valid/`
- `maps/invalid/`
- `maps/defaults/`

The large demo map is useful for screenshots or GIF recording:
- sky-colored ceiling
- grass-colored floor
- spawn near a door
- enough surrounding space that the minimap does not immediately show outer borders

## Controls

- `W` / `S`: move forward and backward
- `A` / `D`: strafe left and right
- `Left` / `Right`: rotate
- `Up` / `Down`: move forward and backward
- `E`: interact with a door
- `M`: toggle mouse capture
- `Esc`: quit

Notes:
- mouse look is disabled by default on startup
- press `M` to enable mouse capture
- press `M` again to disable it

## Map Format

A valid `.cub` file contains:
- four wall textures: `NO`, `SO`, `WE`, `EA`
- floor and ceiling colors: `F`, `C`
- optional door texture: `D`
- a map block using `1`, `0`, `N`, `S`, `E`, `W`, space, and `D`

Example:

```text
NO textures/walls/wall_N.xpm
SO textures/walls/wall_S.xpm
WE textures/walls/wall_W.xpm
EA textures/walls/wall_E.xpm
D textures/doors/door.xpm
F 80,120,160
C 30,30,30

111111
1000D1
10N001
111111
```

Validation rules enforced by the parser include:
- exactly one player spawn
- required config fields must be present and not duplicated
- walkable tiles must not touch the map border or padded void
- doors must sit between walls on one axis and walkable tiles on the other axis

## Project Layout

- `src/parser/`: file loading, config parsing, map normalization, and validation
- `src/render/`: raycasting, wall and door drawing, minimap rendering
- `src/interaction/`: movement, rotation, mouse handling, door interaction
- `src/utils/`: cleanup, timing, and cell lookup helpers
- `includes/`: shared headers
- `textures/`: wall and door assets

## Current Status

The repository is organized around a playable build for both Linux and macOS, with parser, rendering, minimap, doors, mouse toggle, and demo maps already integrated.
