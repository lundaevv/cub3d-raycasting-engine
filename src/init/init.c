/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:40 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/16 15:32:05 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"

static int	init_mlx_core(t_game *game_dt)
{
	int	sw;
	int	sh;

	game_dt->mlx.context = mlx_init();
	if (!game_dt->mlx.context)
		return (0);
	mlx_get_screen_size(game_dt->mlx.context, &sw, &sh);
	game_dt->mlx.win_w = (sw * 3) / 4;
	game_dt->mlx.win_h = (sh * 3) / 4;
	if (game_dt->mlx.win_w < 640)
		game_dt->mlx.win_w = 640;
	if (game_dt->mlx.win_w > 1280)
		game_dt->mlx.win_w = 1280;
	if (game_dt->mlx.win_h < 480)
		game_dt->mlx.win_h = 480;
	if (game_dt->mlx.win_h > 720)
		game_dt->mlx.win_h = 720;
	game_dt->mlx.win = mlx_new_window(game_dt->mlx.context, game_dt->mlx.win_w,
			game_dt->mlx.win_h, "cub3D");
	return (game_dt->mlx.win != NULL);
}

static int	init_frame(t_game *game_dt)
{
	game_dt->mlx.frame.img = mlx_new_image(game_dt->mlx.context,
			game_dt->mlx.win_w, game_dt->mlx.win_h);
	if (!game_dt->mlx.frame.img)
		return (0);
	game_dt->mlx.frame.a = mlx_get_data_addr(game_dt->mlx.frame.img,
			&game_dt->mlx.frame.bpp, &game_dt->mlx.frame.ll,
			&game_dt->mlx.frame.e);
	if (!game_dt->mlx.frame.a)
		return (0);
	game_dt->mlx.frame.w = game_dt->mlx.win_w;
	game_dt->mlx.frame.h = game_dt->mlx.win_h;
	return (1);
}

void	init_game(t_game *game_dt, t_err *error)
{
	*game_dt = (t_game){0};
	*error = ERR_OK;

	if (!init_mlx_core(game_dt) || !init_frame(game_dt))
	{
		*error = ERR_MLX_INIT;
		return ;
	}
}
