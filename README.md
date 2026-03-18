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

This project is set up for Linux with X11 MiniLibX.

```sh
make
```

Notes:
- `libft/` must be present locally
- if `mlx/` is missing, the Makefile clones `minilibx-linux` automatically before building

Useful targets:

```sh
make
make clean
make fclean
make re
make mlxDel
make allClean
```

## Run

```sh
./cub3D maps/valid/valid_basic.cub
```

More sample maps are available under:
- `maps/valid/`
- `maps/invalid/`
- `maps/defaults/`

## Controls

- `W` / `S`: move forward and backward
- `A` / `D`: strafe left and right
- `Left` / `Right`: rotate
- `Up` / `Down`: move forward and backward
- `E`: interact with a door
- `M`: toggle mouse capture
- `Esc`: quit

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

The repository is organized around a playable Linux build with parser, rendering, minimap, and door support already integrated.
