/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:21:59 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/17 14:22:00 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static unsigned int	getp_door_sprite(t_game *game_dt, double tex_x, int y,
		int frame)
{
	const t_img	*tex = &game_dt->graphics.tex[TEX_DOOR_CLOSED];
	const int	frame_w = tex->w / DOOR_SPRITE_CNT;
	const int	sprite_x = (int)(tex_x * frame_w) + frame * frame_w;

	return (getp((t_img *)tex, sprite_x, y));
}

void	draw_door(t_game *game_dt, t_raycast_data ray_data, double wall_h,
		const int col_x)
{
	static double	prev_time;
	static int		frame;
	int				draw_start;
	int				draw_end;
	double			tex_y;

	if (game_dt->mlx.time - prev_time > DOOR_SPRITE_CNT / SPRITES_PER_SEC)
	{
		frame = (frame + 1) % 7;
		prev_time = game_dt->mlx.time;
	}
	draw_start = (game_dt->mlx.win_h - (int)wall_h) / 2;
	draw_end = (game_dt->mlx.win_h + (int)wall_h) / 2;
	tex_y = 0;
	while (draw_start <= draw_end)
	{
		putp(&game_dt->mlx.frame, col_x, draw_start, getp_door_sprite(game_dt,
				ray_data.tex_x, tex_y, frame));
		tex_y += game_dt->graphics.tex[TEX_DOOR_CLOSED].h / wall_h;
		draw_start++;
	}
}
