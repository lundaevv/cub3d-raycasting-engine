/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:48:34 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/16 15:29:32 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"

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
	if (!load_all_textures(game_dt))
	{
		*error = ERR_MLX_INIT;
		return ;
	}
	game_dt->graphics.floor_rgb = game_dt->config.floor_rgb;
	game_dt->graphics.ceil_rgb = game_dt->config.ceil_rgb;
}
