/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:25:59 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/04 15:18:25 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_valid_door(t_map *map, int row, int col)
{
	int	horizontal;
	int	vertical;

	if (row == 0 || col == 0)
		return (0);
	if (row == map->rows - 1 || col == map->cols - 1)
		return (0);
	horizontal = is_wall(map->grid[row][col - 1])
		&& is_wall(map->grid[row][col + 1])
		&& is_walkable_tile(map->grid[row - 1][col])
		&& is_walkable_tile(map->grid[row + 1][col]);
	vertical = is_wall(map->grid[row - 1][col])
		&& is_wall(map->grid[row + 1][col])
		&& is_walkable_tile(map->grid[row][col - 1])
		&& is_walkable_tile(map->grid[row][col + 1]);
	if (horizontal || vertical)
		return (1);
	return (0);
}

int	count_doors(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == 'D')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	validate_doors(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == 'D' && !is_valid_door(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
