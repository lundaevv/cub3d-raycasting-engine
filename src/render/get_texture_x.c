/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:20:38 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/18 12:28:10 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "render.h"
#include "types.h"

double	get_texture_x(t_game game_dt, t_raycast_data ray_data,
		const double sin_val, const double cos_val)
{
	const t_vec	coord = {game_dt.player.pos.x + cos_val * ray_data.len,
		game_dt.player.pos.y + sin_val * ray_data.len};
	const t_vec	min_coord = {floor(coord.x / TILE_SIZE) * TILE_SIZE,
		floor(coord.y / TILE_SIZE) * TILE_SIZE};
	const t_vec	max_coord = {ceil(coord.x / TILE_SIZE) * TILE_SIZE,
		ceil(coord.y / TILE_SIZE) * TILE_SIZE};
	double		res;

	res = 0;
	if (ray_data.side == EAST_S)
		res = coord.y - min_coord.y;
	else if (ray_data.side == SOUTH_S)
		res = max_coord.x - coord.x;
	else if (ray_data.side == WEST_S)
		res = max_coord.y - coord.y;
	else
		res = coord.x - min_coord.x;
	return (res / TILE_SIZE);
}
