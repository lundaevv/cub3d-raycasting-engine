/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:51:46 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 18:29:55 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "render.h"

static t_vec	get_player_pos(t_game game_dt, t_minimap mm)
{
	t_vec	pos;
	double	local_x;
	double	local_y;

	local_x = fmod(game_dt.player.pos.x, TILE_SIZE) / TILE_SIZE;
	local_y = fmod(game_dt.player.pos.y, TILE_SIZE) / TILE_SIZE;
	pos.x = mm.off_x + (mm.cols / 2) * mm.tile + local_x * mm.tile;
	pos.y = mm.off_y + (mm.rows / 2) * mm.tile + local_y * mm.tile;
	return (pos);
}

static int	in_minimap_bounds(t_minimap mm, int x, int y)
{
	if (x < mm.off_x || y < mm.off_y)
		return (0);
	if (x >= mm.off_x + mm.cols * mm.tile)
		return (0);
	if (y >= mm.off_y + mm.rows * mm.tile)
		return (0);
	return (1);
}

static void	draw_one_ray(t_game game_dt, t_vec pos, t_minimap mm, double angle)
{
	t_raycast_data	ray;
	double			scale;
	int				i;
	int				x;
	int				y;

	ray = raycast(game_dt, angle);
	scale = (double)mm.tile / (double)TILE_SIZE;
	i = 0;
	while (i < ray.len * scale)
	{
		x = (int)pos.x + cos(angle) * i;
		y = (int)pos.y + sin(angle) * i;
		if (!in_minimap_bounds(mm, x, y))
			break ;
		putp(&game_dt.mlx.frame, x, y, 0x00FFFF00);
		i++;
	}
}

static void	draw_ray_fan(t_game game_dt, t_vec pos, t_minimap mm)
{
	int		i;
	int		count;
	double	start;
	double	step;

	count = 1000;
	start = game_dt.player.angle - (FOV / 2.0);
	step = FOV / (count - 1);
	i = 0;
	while (i < count)
	{
		draw_one_ray(game_dt, pos, mm, start + i * step);
		i++;
	}
}

void	draw_minimap_player(t_game game_dt, t_minimap mm)
{
	t_vec	pos;
	int		x;
	int		y;

	pos = get_player_pos(game_dt, mm);
	draw_ray_fan(game_dt, pos, mm);
	y = -1;
	while (y <= 1)
	{
		x = -1;
		while (x <= 1)
		{
			if (in_minimap_bounds(mm, (int)pos.x + x, (int)pos.y + y))
				putp(&game_dt.mlx.frame, (int)pos.x + x, (int)pos.y + y,
					0x00FF0000);
			x++;
		}
		y++;
	}
}
