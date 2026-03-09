/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:11:36 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/06 11:19:36 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	touches_void(t_map *map, int row, int col)
{
	if (row == 0 || col == 0)
		return (true);
	if (row == map->rows - 1 || col == map->cols - 1)
		return (true);
	if (map->grid[row - 1][col] == ' ')
		return (true);
	if (map->grid[row + 1][col] == ' ')
		return (true);
	if (map->grid[row][col - 1] == ' ')
		return (true);
	if (map->grid[row][col + 1] == ' ')
		return (true);
	return (false);
}

bool	is_map_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (is_walkable_tile(map->grid[i][j]) && touches_void(map, i, j))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
