/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:02:14 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/06 12:47:49 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_partial_map_grid(char **grid, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static int	build_map_grid(char **lines, int start, int count, t_game *game_dt)
{
	int	i;

	game_dt->map.grid = malloc(sizeof(char *) * (count + 1));
	if (!game_dt->map.grid)
		return (0);
	i = 0;
	while (i < count)
	{
		game_dt->map.grid[i] = ft_strtrim(lines[start + i], "\n");
		if (!game_dt->map.grid[i])
		{
			free_partial_map_grid(game_dt->map.grid, i);
			game_dt->map.grid = NULL;
			return (0);
		}
		i++;
	}
	game_dt->map.grid[i] = NULL;
	game_dt->map.rows = count;
	return (1);
}

void	parse_map_block(char **lines, t_game *game_dt, t_err *error)
{
	int	start;
	int	count;

	start = find_map_start_line(lines);
	if (!validate_map_block_start(start, error))
		return ;
	count = count_map_block_rows(lines, start);
	if (lines[start + count])
		validate_map_terminator(lines, start + count, error);
	if (*error != ERR_OK)
		return ;
	if (!build_map_grid(lines, start, count, game_dt))
	{
		*error = ERR_MEM;
		return ;
	}
	if (!validate_loaded_map(game_dt, error))
		return ;
	if (!extract_player_entity(game_dt))
	{
		*error = ERR_MAP_PLAYER;
		return ;
	}
}
