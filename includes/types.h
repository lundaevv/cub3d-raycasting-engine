/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:41 by vlundaev          #+#    #+#             */
/*   Updated: 2026/02/25 17:21:42 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_cell
{
	c_unknown,
	c_empty,
	c_wall,
	c_door
}	t_cell;

// NOTE: Struct for storing curently pressed button
typedef struct s_input
{
	double					last_time;
	int						w;
	int						s;
	int						a;
	int						d;
}	t_input;

// TODO: Decide should it be a double or int?
typedef struct s_vec
{
	double					x;
	double					y;
}	t_vec;

typedef struct s_img
{
	void					*img;
	char					*a;
	int						bpp;
	int						ll;
	int						e;
	int						w;
	int						h;
}	t_img;

typedef struct s_map
{
	char					**grid;			/* 2D map layout: arr of strings */
	int						cols;
	int						rows;
}	t_map;

typedef struct s_player
{
	t_vec					pos;			/* Player position x,y */
	double					angle;
}	t_player;

typedef struct s_config
{
	char					*path_nw;		/* texture path: North wall */
	char					*path_sw;		/* texture path: South wall */
	char					*path_ww;		/* texture path: West wall */
	char					*path_ew;		/* texture path: East wall */
	int						floor_rgb;		/* floor color as 0xRRGGBB */
	int						ceil_rgb;		/* ceiling color as 0xRRGGBB */
}	t_config;

typedef struct s_graphics
{
	// array of sprites
	// array of textures
	// floor and ceiling colors
}	t_graphics;

typedef struct s_mlx
{
	void					*context;		/* MLX context handle */
	void					*win;			/* MLX window handle */
	t_img					frame;			/* Image storing frame to render */
	int						win_w;			/* Window width */
	int						win_h;			/* Window height */
}	t_mlx;

typedef struct s_game
{
	t_mlx					mlx;			/* MLX handles + screen size */
	t_graphics				graphics;
	char					*map_path;		/* path to input .cub (argv[1]) */
	t_config				config;			/* parsed config/paths/colors */
	t_map					map;			/* map grid and dimensions */
	t_player				player;			/* player position and camera */
	t_input					inp;			/* currently pressed buttons */
}	t_game;

#endif