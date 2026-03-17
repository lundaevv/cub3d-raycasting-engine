/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:23:27 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/16 16:14:42 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interaction.h"
#include "mlx.h"

static void	center_mouse(t_game *game_dt)
{
	game_dt->inp.mouse_lock = 1;
	mlx_mouse_move(game_dt->mlx.context, game_dt->mlx.win, game_dt->mlx.win_w
		/ 2, game_dt->mlx.win_h / 2);
}

static void	rotate_from_mouse(t_game *game_dt, int x)
{
	double	delta;

	delta = x - (game_dt->mlx.win_w / 2);
	if (delta >= -1 && delta <= 1)
		return ;
	game_dt->player.angle += delta * 0.002;
	if (game_dt->player.angle >= 2 * M_PI)
		game_dt->player.angle -= 2 * M_PI;
	if (game_dt->player.angle < 0)
		game_dt->player.angle += 2 * M_PI;
}

int	on_mouse_move(int x, int y, void *param)
{
	t_game	*game_dt;

	(void)y;
	game_dt = (t_game *)param;
	if (!game_dt->inp.mouse_on)
		return (0);
	if (!game_dt->inp.mouse_ready)
	{
		game_dt->inp.mouse_ready = 1;
		center_mouse(game_dt);
		return (0);
	}
	if (game_dt->inp.mouse_lock)
	{
		game_dt->inp.mouse_lock = 0;
		return (0);
	}
	rotate_from_mouse(game_dt, x);
	center_mouse(game_dt);
	return (0);
}
