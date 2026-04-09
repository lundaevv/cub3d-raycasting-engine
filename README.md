# Raycasting Rendering Engine

A real-time 3D rendering engine written in C using raycasting techniques, inspired by early FPS games like Wolfenstein 3D.

## 🧠 Overview

Cub3D is a real-time rendering engine that simulates a 3D environment using raycasting techniques.  
It focuses on graphics programming, mathematical transformations, and real-time rendering performance.

## 🎬 Demo

![Demo](./assets/demo.gif)

## 🎮 Features

- `.cub` parsing (textures, colors, player spawn, doors)
- Robust map validation (invalid characters, duplicates, open maps, door placement)
- Real-time textured wall and door rendering using raycasting
- Player movement, rotation, mouse look, and minimap

## 🛠 Tech Stack

- C
- MiniLibX
- Raycasting algorithm (DDA)
- Trigonometry and linear algebra

## 🏗 Architecture

- **Parser** — reads `.cub` files and validates map/config  
- **Raycasting Engine** — casts rays and computes wall distances
- **Rendering Pipeline** — converts 2D map data into a 3D projection using raycasting
- **Renderer** — draws walls, textures, and minimap  
- **Input System** — handles movement, rotation, and interaction
- **Game Loop** — handles frame updates and rendering cycle

## ⚙️ Build

This project builds on both Linux and macOS.

- Linux: uses `minilibx-linux`
- macOS: uses a Metal-based MiniLibX fork

```sh
make
```

Notes:

- `libft/` must be present locally
- if `mlx/` is missing, the Makefile clones the correct MiniLibX repo automatically
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

## ▶️ Run

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

## 🎮 Controls

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

## 🗺 Map Format

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

## 📁 Project Structure

- `src/parser/`: file loading, config parsing, map normalization, and validation
- `src/render/`: raycasting, wall and door drawing, minimap rendering
- `src/interaction/`: movement, rotation, mouse handling, door interaction
- `src/utils/`: cleanup, timing, and cell lookup helpers
- `includes/`: shared headers
- `textures/`: wall and door assets

## 📌 Status

Playable build for Linux and macOS with parser, rendering, minimap, doors, and input fully implemented.

## 🧑‍💻 Authors

- Vitali - [github.com/lundaevv](https://github.com/lundaevv)
- Artem - [github.com/a-kuchmambetov](https://github.com/a-kuchmambetov)
