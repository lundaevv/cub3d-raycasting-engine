/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:47:11 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/03 19:23:47 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_grid_copy(char **grid, int count)
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

static char	*build_padded_row(char *src, int width)
{
	char	*row;
	int		i;

	row = malloc(sizeof(char) * (width + 1));
	if (!row)
		return (NULL);
	i = 0;
	while (src[i])
	{
		row[i] = src[i];
		i++;
	}
	while (i < width)
	{
		row[i] = ' ';
		i++;
	}
	row[i] = '\0';
	return (row);
}

int	normalize_map(t_game *game_dt)
{
	char	**new_grid;
	int		i;

	new_grid = malloc(sizeof(char *) * (game_dt->map.rows + 1));
	if (!new_grid)
		return (0);
	i = 0;
	while (i < game_dt->map.rows)
	{
		new_grid[i] = build_padded_row(game_dt->map.grid[i], game_dt->map.cols);
		if (!new_grid[i])
		{
			free_grid_copy(new_grid, i);
			return (0);
		}
		i++;
	}
	new_grid[i] = NULL;
	free_lines(game_dt->map.grid);
	game_dt->map.grid = new_grid;
	return (1);
}
