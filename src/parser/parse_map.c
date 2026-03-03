/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:02:14 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/03 19:23:42 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	find_map_start(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_empty_line(lines[i]))
			i++;
		else if (get_config_id(lines[i]) >= 0)
			i++;
		else
			return (i);
	}
	return (-1);
}

static int	count_map_lines(char **lines, int start, t_err *error)
{
	int	count;
	int	i;

	count = 0;
	i = start;
	while (lines[i])
	{
		if (is_empty_line(lines[i]))
		{
			*error = ERR_MAP_EMPTY;
			return (0);
		}
		count++;
		i++;
	}
	return (count);
}

static void	free_map_copy(char **grid, int count)
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

static int	copy_map_lines(char **lines, int start, int count, t_game *game_dt)
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
			free_map_copy(game_dt->map.grid, i);
			game_dt->map.grid = NULL;
			return (0);
		}
		i++;
	}
	game_dt->map.grid[i] = NULL;
	game_dt->map.rows = count;
	return (1);
}

void	parse_map(char **lines, t_game *game_dt, t_err *error)
{
	int	start;
	int	count;

	if (!lines || !game_dt || !error)
		return ;
	start = find_map_start(lines);
	if (start < 0)
	{
		*error = ERR_MAP_EMPTY;
		return ;
	}
	count = count_map_lines(lines, start, error);
	if (*error != ERR_OK)
		return ;
	if (!copy_map_lines(lines, start, count, game_dt))
	{
		*error = ERR_MEM;
		return ;
	}
	if (!validate_loaded_map(game_dt, error))
		return ;
}
