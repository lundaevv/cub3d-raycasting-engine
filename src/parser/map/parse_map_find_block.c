/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_find_block.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:35:55 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/06 12:36:10 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	find_map_start_line(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_empty_line(lines[i]))
			i++;
		else if (get_config_id(lines[i]) >= 0)
			i++;
		else if (is_map_line(lines[i]))
			return (i);
		else
			return (-2);
	}
	return (-1);
}

int	validate_map_block_start(int start, t_err *error)
{
	if (start == -1)
	{
		*error = ERR_MAP_EMPTY;
		return (0);
	}
	if (start == -2)
	{
		*error = ERR_PARSE;
		return (0);
	}
	return (1);
}

int	count_map_block_rows(char **lines, int start)
{
	int	count;
	int	i;

	count = 0;
	i = start;
	while (lines[i] && !is_empty_line(lines[i]))
	{
		count++;
		i++;
	}
	return (count);
}
