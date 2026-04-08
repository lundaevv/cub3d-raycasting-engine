/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:19:09 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 18:20:50 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "render.h"

static int	is_door_pos(t_game game_dt, t_vec map)
{
	t_door	*door;

	door = game_dt.door_li.head;
	while (door)
	{
		if (door->map_pos.x == (int)map.x && door->map_pos.y == (int)map.y)
			return (1);
		door = door->next;
	}
	return (0);
}

static void	draw_minimap_panel(t_game game_dt, t_minimap mm)
{
	int	x;
	int	y;
	int	w;
	int	h;

	w = mm.cols * mm.tile;
	h = mm.rows * mm.tile;
	y = mm.off_y - 2;
	while (y < mm.off_y + h + 2)
	{
		x = mm.off_x - 2;
		while (x < mm.off_x + w + 2)
		{
			if (x < mm.off_x || y < mm.off_y || x >= mm.off_x + w
				|| y >= mm.off_y + h)
				putp(&game_dt.mlx.frame, x, y, 0x00FFFFFF);
			else
				putp(&game_dt.mlx.frame, x, y, 0x000B0B0B);
			x++;
		}
		y++;
	}
}

static char	get_visible_tile(t_game game_dt, t_vec map)
{
	char	tile;

	tile = game_dt.map.grid[(int)map.y][(int)map.x];
	if (tile == '0' && is_door_pos(game_dt, map))
		return ('D');
	return (tile);
}

static void	draw_visible_tiles(t_game game_dt, t_minimap mm, t_vec start)
{
	t_vec	map;
	t_vec	view;

	view.y = 0;
	while (view.y < mm.rows)
	{
		view.x = 0;
		while (view.x < mm.cols)
		{
			map.x = start.x + view.x;
			map.y = start.y + view.y;
			if (map.x >= 0 && map.y >= 0 && map.x < game_dt.map.cols
				&& map.y < game_dt.map.rows)
				draw_minimap_tile(game_dt, mm, (t_vec){
					mm.off_x + view.x * mm.tile,
					mm.off_y + view.y * mm.tile}, get_visible_tile(game_dt,
						map));
			else
				draw_minimap_tile(game_dt, mm, (t_vec){
					mm.off_x + view.x * mm.tile,
					mm.off_y + view.y * mm.tile}, ' ');
			view.x++;
		}
		view.y++;
	}
}

void	draw_minimap(t_game game_dt)
{
	t_minimap	mm;
	t_vec		start;

	mm = get_minimap_cfg();
	draw_minimap_panel(game_dt, mm);
	start.x = (int)(game_dt.player.pos.x / TILE_SIZE) - mm.cols / 2;
	start.y = (int)(game_dt.player.pos.y / TILE_SIZE) - mm.rows / 2;
	draw_visible_tiles(game_dt, mm, start);
	draw_minimap_player(game_dt, mm);
	draw_minimap_doors(game_dt, mm, start);
}
