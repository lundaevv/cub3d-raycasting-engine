/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:04:14 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/06 11:16:50 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_max_map_width(char **grid)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	while (grid[i])
	{
		len = ft_strlen(grid[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	validate_map_chars(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (!is_map_char(grid[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_players(char **grid)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (is_player_char(grid[i][j]))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

bool	is_map_line(char *line)
{
	int	i;
	int	has_tile;

	if (!line)
		return (false);
	i = 0;
	has_tile = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_map_char(line[i]))
			return (false);
		if (line[i] != ' ')
			has_tile = true;
		i++;
	}
	return (has_tile);
}
