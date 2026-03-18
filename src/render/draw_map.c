/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:21:43 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/17 14:19:39 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "render.h"

static void	draw_wall_column(t_game game_dt, t_raycast_data ray_data,
		double wall_h, const int col_x)
{
	t_img	*tex;
	int		draw_start;
	int		draw_end;
	double	tex_y;

	if (ray_data.side == EAST_S)
		tex = &game_dt.graphics.tex[TEX_EW];
	else if (ray_data.side == SOUTH_S)
		tex = &game_dt.graphics.tex[TEX_SW];
	else if (ray_data.side == WEST_S)
		tex = &game_dt.graphics.tex[TEX_WW];
	else
		tex = &game_dt.graphics.tex[TEX_NW];
	draw_start = (game_dt.mlx.win_h - (int)wall_h) / 2;
	draw_end = (game_dt.mlx.win_h + (int)wall_h) / 2;
	tex_y = 0;
	while (draw_start <= draw_end)
	{
		putp(&game_dt.mlx.frame, col_x, draw_start, getp(tex, ray_data.tex_x
				* tex->w, tex_y));
		tex_y += tex->h / wall_h;
		draw_start++;
	}
}

static void	draw_bg_column(t_game game_dt, int col_x, int top, int bottom)
{
	int	y;

	y = 0;
	while (y < top)
	{
		putp(&game_dt.mlx.frame, col_x, y, game_dt.graphics.ceil_rgb);
		y++;
	}
	y = bottom + 1;
	while (y < game_dt.mlx.win_h)
	{
		putp(&game_dt.mlx.frame, col_x, y, game_dt.graphics.floor_rgb);
		y++;
	}
}

static void	draw_column(t_game game_dt, double proj_plane,
		t_raycast_data ray_data, const int col_x)
{
	int		top;
	int		bottom;
	double	wall_h;

	wall_h = ((double)TILE_SIZE * (double)WORLD_HEIGHT * proj_plane)
		/ ray_data.len;
	top = (game_dt.mlx.win_h - (int)wall_h) / 2;
	bottom = (game_dt.mlx.win_h + (int)wall_h) / 2;
	if (top < 0)
		top = 0;
	if (bottom >= game_dt.mlx.win_h)
		bottom = game_dt.mlx.win_h - 1;
	draw_bg_column(game_dt, col_x, top, bottom);
	if (ray_data.cell_type == c_door)
		draw_door(&game_dt, ray_data, wall_h, col_x);
	else
		draw_wall_column(game_dt, ray_data, wall_h, col_x);
}

static t_raycast_data	get_column_ray(t_game game_dt, double fov, int x)
{
	t_raycast_data	ray_data;
	double			camera_x;
	double			ray_offset;

	camera_x = (2.0 * ((double)x + 0.5) / (double)game_dt.mlx.win_w) - 1.0;
	ray_offset = atan(camera_x * tan(fov / 2));
	ray_data = raycast(game_dt, game_dt.player.angle + ray_offset);
	ray_data.len = ray_data.len * cos(ray_offset);
	if (ray_data.len < 1.0)
		ray_data.len = 1.0;
	return (ray_data);
}

void	draw_map(t_game game_dt)
{
	double	fov;
	double	proj_plane;
	int		x;

	fov = FOV;
	if (fov <= 1e-6 || fov >= M_PI - 1e-6)
		fov = M_PI / 2.0;
	proj_plane = ((double)game_dt.mlx.win_w * 0.5) / tan(fov / 2);
	x = 0;
	while (x < game_dt.mlx.win_w)
	{
		draw_column(game_dt, proj_plane, get_column_ray(game_dt, fov, x), x);
		x++;
	}
}
