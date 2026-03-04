/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:12:34 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/04 19:23:40 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	validate_map_content(t_game *game_dt, t_err *error)
{
	game_dt->map.cols = get_max_map_width(game_dt->map.grid);
	if (!validate_map_chars(game_dt->map.grid))
	{
		*error = ERR_MAP_CHAR;
		return (0);
	}
	if (count_players(game_dt->map.grid) != 1)
	{
		*error = ERR_MAP_PLAYER;
		return (0);
	}
	if (!extract_player(game_dt))
	{
		*error = ERR_MAP_PLAYER;
		return (0);
	}
	return (1);
}

static int	validate_door_config(t_game *game_dt, t_err *error)
{
	if (count_doors(&game_dt->map) == 0)
		return (1);
	if (!game_dt->config.path_door_closed || !game_dt->config.path_door_open)
	{
		*error = ERR_DOOR_CONF_MISS;
		return (0);
	}
	return (1);
}

static int	validate_sprite_config(t_game *game_dt, t_err *error)
{
	if (count_sprites(&game_dt->map) == 0)
		return (1);
	if (!game_dt->config.path_sprite_anim)
	{
		*error = ERR_SPR_CONF_MISS;
		return (0);
	}
	return (1);
}

int	validate_loaded_map(t_game *game_dt, t_err *error)
{
	if (!validate_map_content(game_dt, error))
		return (0);
	if (!normalize_map(game_dt))
	{
		*error = ERR_MEM;
		return (0);
	}
	if (!validate_doors(&game_dt->map))
	{
		*error = ERR_MAP_DOOR;
		return (0);
	}
	if (!validate_door_config(game_dt, error))
		return (0);
	if (!validate_sprite_config(game_dt, error))
		return (0);
	if (!is_map_closed(&game_dt->map))
	{
		*error = ERR_MAP_OPEN;
		return (0);
	}
	return (1);
}
