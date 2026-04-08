/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:20:21 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 18:31:08 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "render.h"

t_minimap	get_minimap_cfg(void)
{
	return ((t_minimap){20, 20, 12, 9, 16});
}

static unsigned int	get_tile_color(char tile)
{
	if (tile == '1')
		return (0x00A0A0A0);
	if (tile == 'D')
		return (0x0000FF00);
	if (tile == '0')
		return (0x00222222);
	return (0x000B0B0B);
}

void	draw_minimap_tile(t_game game_dt, t_minimap mm, t_vec pos, char tile)
{
	int				x;
	int				y;
	unsigned int	color;

	color = get_tile_color(tile);
	y = 0;
	while (y < mm.tile)
	{
		x = 0;
		while (x < mm.tile)
		{
			putp(&game_dt.mlx.frame, (int)pos.x + x, (int)pos.y + y, color);
			x++;
		}
		y++;
	}
}

static void	draw_door_marker(t_game game_dt, t_minimap mm, t_vec view)
{
	t_vec	pos;
	int		x;
	int		y;

	pos.x = mm.off_x + view.x * mm.tile + mm.tile / 2;
	pos.y = mm.off_y + view.y * mm.tile + mm.tile / 2;
	y = -1;
	while (y <= 1)
	{
		x = -1;
		while (x <= 1)
		{
			putp(&game_dt.mlx.frame, (int)pos.x + x, (int)pos.y + y,
				0x0000FF00);
			x++;
		}
		y++;
	}
}

void	draw_minimap_doors(t_game game_dt, t_minimap mm, t_vec start)
{
	t_door	*door;
	t_vec	view;

	door = game_dt.door_li.head;
	while (door)
	{
		view.x = door->map_pos.x - start.x;
		view.y = door->map_pos.y - start.y;
		if (view.x >= 0 && view.y >= 0 && view.x < mm.cols && view.y < mm.rows)
			draw_door_marker(game_dt, mm, view);
		door = door->next;
	}
}
