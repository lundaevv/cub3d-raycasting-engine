/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:32:06 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/05 12:40:53 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"
#include "mlx.h"

static void	free_graphics_data(t_game *g)
{
	int	i;

	if (!g->mlx.context)
		return ;
	if (g->mlx.frame.img)
		mlx_destroy_image(g->mlx.context, g->mlx.frame.img);
	i = 0;
	while (i < TEX_COUNT)
	{
		if (g->graphics.tex[i].img)
			mlx_destroy_image(g->mlx.context, g->graphics.tex[i].img);
		i++;
	}
	if (g->mlx.win)
		mlx_destroy_window(g->mlx.context, g->mlx.win);
	mlx_destroy_display(g->mlx.context);
	free(g->mlx.context);
}

static void	free_parser_data(t_game *game_dt)
{
	free(game_dt->config.path_nw);
	free(game_dt->config.path_sw);
	free(game_dt->config.path_ww);
	free(game_dt->config.path_ew);
	free(game_dt->config.path_door_closed);
	free(game_dt->config.path_door_open);
	free(game_dt->config.path_sprite_anim);
	free_lines(game_dt->map.grid);
}

static void	reset_parser_data(t_game *game_dt)
{
	game_dt->config.path_nw = NULL;
	game_dt->config.path_sw = NULL;
	game_dt->config.path_ww = NULL;
	game_dt->config.path_ew = NULL;
	game_dt->config.path_door_closed = NULL;
	game_dt->config.path_door_open = NULL;
	game_dt->config.path_sprite_anim = NULL;
	game_dt->config.floor_rgb = 0;
	game_dt->config.ceil_rgb = 0;
	game_dt->map.grid = NULL;
	game_dt->map.rows = 0;
	game_dt->map.cols = 0;
}

void	destroy(t_game *game_dt)
{
	if (!game_dt)
		return ;
	free_graphics_data(game_dt);
	free_parser_data(game_dt);
	reset_parser_data(game_dt);
}
