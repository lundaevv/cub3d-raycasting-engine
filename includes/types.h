/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:41 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/18 12:23:15 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdint.h>

typedef struct s_vec
{
	double			x;
	double			y;
}					t_vec;

typedef struct s_vec_int
{
	int				x;
	int				y;
}					t_vec_int;

// NOTE: Stores result of calculations from raycast
typedef enum e_cell_side
{
	NORTH_S,
	SOUTH_S,
	WEST_S,
	EAST_S
}					t_cell_side;
typedef enum e_cell
{
	c_unknown,
	c_empty,
	c_wall,
	c_door
}					t_cell;

typedef struct s_raycast_data
{
	double			len;
	t_cell_side		side;
	double			tex_x;
	t_cell			cell_type;
}					t_raycast_data;

// NOTE: Stores curently pressed button
typedef struct s_input
{
	double			last_time;
	int				w;
	int				s;
	int				a;
	int				d;
	int				left;
	int				right;
	int				e;
	int				mouse_ready;
	int				mouse_lock;
	int				mouse_on;
}					t_input;

typedef struct s_img
{
	void			*img;
	char			*a;
	int				bpp;
	int				ll;
	int				e;
	int				w;
	int				h;
}					t_img;

typedef struct s_map
{
	char			**grid;
	int				cols;
	int				rows;
}					t_map;

typedef struct s_player
{
	t_vec			pos;
	double			angle;
}					t_player;

// NOTE: Parsed config values, stored in t_game after parsing
typedef struct s_config
{
	char			*path_nw;
	char			*path_sw;
	char			*path_ww;
	char			*path_ew;
	char			*path_door_closed;
	int				floor_rgb;
	int				ceil_rgb;
}					t_config;

// NOTE: Enum for texture IDs, used to index into t_graphics.tex array
typedef enum e_tex_id
{
	TEX_NW,
	TEX_SW,
	TEX_WW,
	TEX_EW,
	TEX_DOOR_CLOSED,
	TEX_COUNT
}					t_tex_id;

// NOTE: Stores loaded textures and floor/ceiling colors, stored in t_game
typedef struct s_graphics
{
	t_img			tex[TEX_COUNT];
	unsigned int	floor_rgb;
	unsigned int	ceil_rgb;
}					t_graphics;

// NOTE: Stores MLX handles and screen size, stored in t_game
typedef struct s_mlx
{
	void			*context;
	void			*win;
	t_img			frame;
	t_img			minimap;
	int				win_w;
	int				win_h;
	double			time;
}					t_mlx;

typedef struct s_door
{
	t_vec_int		map_pos;
	struct s_door	*next;
}					t_door;

typedef struct s_door_list
{
	t_door			*head;
	t_door			*tail;
	short int		is_in_range;
	short int		is_inside;
}					t_door_list;

// NOTE: Main game struct, passed to all functions. Stores all game state
typedef struct s_game
{
	t_mlx			mlx;
	t_graphics		graphics;
	char			*map_path;
	t_config		config;
	t_map			map;
	t_player		player;
	t_door_list		door_li;
	t_input			inp;
	short int		is_menu;
}					t_game;

#endif
