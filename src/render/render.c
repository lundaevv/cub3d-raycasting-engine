/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:49:15 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/05 13:50:43 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THATS A PLACEHOLDER CODE FOR PARSER TESTING <3
#include "render.h"
#include "utils.h"
#include "config.h"
#include "mlx.h"
#include <stdlib.h>

static int	on_close(void *param)
{
	t_game	*game_dt;

	game_dt = (t_game *)param;
	destroy(game_dt);
	exit(0);
	return (0);
}

static int	on_key(int keycode, void *param)
{
	if (keycode == K_ESC)
		return (on_close(param));
	return (0);
}

int	render(t_game *game_dt, t_err *error)
{
	if (!game_dt || !error || *error != ERR_OK)
		return (0);
	mlx_put_image_to_window(game_dt->mlx.context, game_dt->mlx.win,
		game_dt->mlx.frame.img, 0, 0);
	mlx_hook(game_dt->mlx.win, KEY_PRESS, KEY_PRESS_MASK, on_key, game_dt);
	mlx_hook(game_dt->mlx.win, DESTROY_NOTIFY, 0, on_close, game_dt);
	mlx_loop(game_dt->mlx.context);
	return (1);
}
