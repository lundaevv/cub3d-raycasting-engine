/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:20:21 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 17:48:27 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	on_close(void *param)
{
	t_game	*game_dt;

	game_dt = (t_game *)param;
	destroy(game_dt);
	exit(0);
	return (0);
}

// NOTE: draw_minimap
static int	update(t_game *game_dt)
{
	const double	t = get_time_sec();
	double			dt;
	double			step;

	dt = t - game_dt->inp.last_time;
	step = dt * 40;
	game_dt->inp.last_time = t;
	if (dt > 0.05)
		dt = 0.05;
	move_player(game_dt, step);
	rotate_player(game_dt, step * 0.1);
	draw_map(*game_dt);
	draw_minimap(*game_dt);
	mlx_put_image_to_window(game_dt->mlx.context, game_dt->mlx.win,
		game_dt->mlx.frame.img, 0, 0);
	return (0);
}

//	NOTE: on_mouse_move added to mlx_hook in render() 
//	and mouse_on flag set to 1 to enable mouse movement tracking. 
//	Mouse cursor is hidden with mlx_mouse_hide.
void	render(t_game *game_dt)
{
	game_dt->inp.mouse_on = 1;
	mlx_hook(game_dt->mlx.win, KEY_PRESS, KEY_PRESS_MASK, on_key_press,
		game_dt);
	mlx_hook(game_dt->mlx.win, KEY_RELEASE, KEY_RELEASE_MASK, on_key_release,
		game_dt);
	mlx_hook(game_dt->mlx.win, DESTROY_NOTIFY, 0, on_close, game_dt);
	mlx_hook(game_dt->mlx.win, MOTION_NOTIFY, POINTER_MOTION_MASK,
		on_mouse_move, game_dt);
	mlx_mouse_hide(game_dt->mlx.context, game_dt->mlx.win);
	mlx_loop_hook(game_dt->mlx.context, update, game_dt);
	mlx_loop(game_dt->mlx.context);
}
