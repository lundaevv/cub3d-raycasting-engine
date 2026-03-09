/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:48:34 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/06 12:40:09 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx.h"

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
	if (game_dt->mlx.win_h < 480)
		game_dt->mlx.win_h = 480;
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

static char	*get_tex_path(t_config *config, int id)
{
	if (id == TEX_NW)
		return (config->path_nw);
	if (id == TEX_SW)
		return (config->path_sw);
	if (id == TEX_WW)
		return (config->path_ww);
	if (id == TEX_EW)
		return (config->path_ew);
	if (id == TEX_DOOR_CLOSED)
		return (config->path_door_closed);
	if (id == TEX_DOOR_OPEN)
		return (config->path_door_open);
	if (id == TEX_SPRITE_ANIM)
		return (config->path_sprite_anim);
	return (NULL);
}

static int	load_all_textures(t_game *game)
{
	char	*path;
	int		i;

	i = 0;
	while (i < TEX_COUNT)
	{
		path = get_tex_path(&game->config, i);
		if (!path)
		{
			i++;
			continue ;
		}
		game->graphics.tex[i].img = mlx_xpm_file_to_image(game->mlx.context,
				path, &game->graphics.tex[i].w, &game->graphics.tex[i].h);
		if (!game->graphics.tex[i].img)
			return (0);
		game->graphics.tex[i].a = mlx_get_data_addr(game->graphics.tex[i].img,
				&game->graphics.tex[i].bpp, &game->graphics.tex[i].ll,
				&game->graphics.tex[i].e);
		if (!game->graphics.tex[i].a)
			return (0);
		i++;
	}
	return (1);
}

void	init_graphics(t_game *game_dt, t_err *error)
{
	if (!init_mlx_core(game_dt) || !init_frame(game_dt)
		|| !load_all_textures(game_dt))
	{
		*error = ERR_MLX_INIT;
		return ;
	}
	game_dt->graphics.floor_rgb = game_dt->config.floor_rgb;
	game_dt->graphics.ceil_rgb = game_dt->config.ceil_rgb;
}
