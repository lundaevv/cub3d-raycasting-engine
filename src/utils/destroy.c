/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:32:06 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/03 19:37:48 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

void	destroy(t_game *game_dt)
{
	if (!game_dt)
		return ;
	free(game_dt->config.path_nw);
	free(game_dt->config.path_sw);
	free(game_dt->config.path_ww);
	free(game_dt->config.path_ew);
	free_lines(game_dt->map.grid);
	game_dt->config.path_nw = NULL;
	game_dt->config.path_sw = NULL;
	game_dt->config.path_ww = NULL;
	game_dt->config.path_ew = NULL;
	game_dt->map.grid = NULL;
	game_dt->map.rows = 0;
	game_dt->map.cols = 0;
}
