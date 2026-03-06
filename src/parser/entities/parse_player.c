/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:48 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/06 12:48:26 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static double	get_player_angle(char c)
{
	if (c == 'N')
		return (3 * PI / 2);
	if (c == 'S')
		return (PI / 2);
	if (c == 'W')
		return (PI);
	return (0.0);
}

static void	store_player_from_cell(t_game *game_dt, int row, int col, char c)
{
	game_dt->player.pos.x = col;
	game_dt->player.pos.y = row;
	game_dt->player.angle = get_player_angle(c);
	game_dt->map.grid[row][col] = '0';
}

int	extract_player_entity(t_game *game_dt)
{
	int	i;
	int	j;

	i = 0;
	while (game_dt->map.grid[i])
	{
		j = 0;
		while (game_dt->map.grid[i][j])
		{
			if (is_player_char(game_dt->map.grid[i][j]))
			{
				store_player_from_cell(game_dt, i, j, game_dt->map.grid[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
