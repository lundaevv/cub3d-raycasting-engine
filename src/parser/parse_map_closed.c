/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:11:36 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/03 19:47:10 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_open_tile(char c)
{
	return (c == '0' || c == 'D');
}

static int	touches_void(t_map *map, int row, int col)
{
	if (row == 0 || col == 0)
		return (1);
	if (row == map->rows - 1 || col == map->cols - 1)
		return (1);
	if (map->grid[row - 1][col] == ' ')
		return (1);
	if (map->grid[row + 1][col] == ' ')
		return (1);
	if (map->grid[row][col - 1] == ' ')
		return (1);
	if (map->grid[row][col + 1] == ' ')
		return (1);
	return (0);
}

int	is_map_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (is_open_tile(map->grid[i][j]) && touches_void(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
