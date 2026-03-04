/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:38:04 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/04 19:25:03 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_map_tail(char **lines, int i, t_err *error)
{
	while (lines[i])
	{
		if (!is_empty_line(lines[i]))
		{
			*error = ERR_MAP_GAP;
			return (0);
		}
		i++;
	}
	*error = ERR_MAP_TRAIL;
	return (0);
}

int	count_map_lines(char **lines, int start, t_err *error)
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
	if (!lines[i])
		return (count);
	return (check_map_tail(lines, i, error));
}
