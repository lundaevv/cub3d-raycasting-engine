/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:32:06 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/04 19:26:21 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

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
	free_parser_data(game_dt);
	reset_parser_data(game_dt);
}
