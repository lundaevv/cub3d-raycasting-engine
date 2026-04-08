/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:40 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/17 14:19:56 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minimap.h"
#include "utils.h"

static int	init_window(t_game *game_dt, int sw, int sh)
{
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

static int	init_mlx_core(t_game *game_dt)
{
	int	sw;
	int	sh;

	game_dt->mlx.context = mlx_init();
	if (!game_dt->mlx.context)
		return (0);
	mlx_get_screen_size_safe(game_dt->mlx.context, &sw, &sh);
	return (init_window(game_dt, sw, sh));
}

static int	init_img(t_game *game_dt, t_img *img, int w, int h)
{
	img->img = mlx_new_image(game_dt->mlx.context, w, h);
	if (!img->img)
		return (0);
	img->a = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->e);
	if (!img->a)
		return (0);
	img->w = w;
	img->h = h;
	return (1);
}

static int	init_frame_and_minimap(t_game *game_dt)
{
	t_minimap	mm;

	if (!init_img(game_dt, &game_dt->mlx.frame, game_dt->mlx.win_w,
			game_dt->mlx.win_h))
		return (0);
	mm = get_minimap_cfg();
	return (init_img(game_dt, &game_dt->mlx.minimap, mm.cols * mm.tile + 4,
			mm.rows * mm.tile + 4));
}

void	init_game(t_game *game_dt, t_err *error)
{
	*game_dt = (t_game){0};
	*error = ERR_OK;
	if (!init_mlx_core(game_dt) || !init_frame_and_minimap(game_dt))
	{
		*error = ERR_MLX_INIT;
		return ;
	}
}
