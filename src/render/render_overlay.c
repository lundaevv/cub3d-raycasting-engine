/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_overlay.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:30:00 by vlundaev          #+#    #+#             */
/*   Updated: 2026/04/08 19:30:00 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	copy_overlay_row(t_game *game_dt, t_minimap mm, int y, int dst_y)
{
	int	x;
	int	dst_x;

	dst_x = 0;
	x = mm.off_x - 2;
	while (dst_x < game_dt->mlx.minimap.w)
	{
		putp(&game_dt->mlx.minimap, dst_x, dst_y,
			getp(&game_dt->mlx.frame, x, y));
		dst_x++;
		x++;
	}
}

void	draw_minimap_overlay(t_game *game_dt)
{
	t_minimap	mm;
	int			y;
	int			dst_y;

	if (!MLX_USE_MINIMAP_OVERLAY)
		return ;
	mm = get_minimap_cfg();
	dst_y = 0;
	y = mm.off_y - 2;
	while (dst_y < game_dt->mlx.minimap.h)
	{
		copy_overlay_row(game_dt, mm, y, dst_y);
		dst_y++;
		y++;
	}
	mlx_put_image_to_window(game_dt->mlx.context, game_dt->mlx.win,
		game_dt->mlx.minimap.img, mm.off_x - 2, mm.off_y - 2);
}
