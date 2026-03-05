/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:01:47 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/05 12:14:21 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	register_config(int seen[9], char *line,
	t_game *game_dt, t_err *error)
{
	int		id;

	id = get_config_id(line);
	if (id < 0)
		return (0);
	seen[id]++;
	if (seen[id] > 1)
	{
		*error = ERR_CONF_DUP;
		return (0);
	}
	if (!store_config_value(line, id, game_dt, error))
		return (0);
	return (1);
}

static void	init_seen(int seen[9])
{
	int	i;

	i = 0;
	while (i < 9)
	{
		seen[i] = 0;
		i++;
	}
}

static void	check_config_block(char **lines, int start,
	t_game *game_dt, t_err *error)
{
	int	i;
	int	seen[9];

	init_seen(seen);
	i = start;
	while (lines[i] && *error == ERR_OK)
	{
		if (is_empty_line(lines[i]))
			i++;
		else if (is_map_line(lines[i]))
			break ;
		else if (!register_config(seen, lines[i], game_dt, error))
		{
			if (*error == ERR_OK)
				*error = ERR_PARSE;
		}
		else
			i++;
	}
	if (*error == ERR_OK && (!seen[0] || !seen[1] || !seen[2] || !seen[3]
			|| !seen[7] || !seen[8]))
		*error = ERR_CONF_MISS;
}

void	parse_config(char **lines, t_game *game_dt, t_err *error)
{
	int	start;

	if (!lines || !game_dt || !error)
		return ;
	start = skip_empty_lines(lines);
	if (!lines[start])
	{
		*error = ERR_PARSE;
		return ;
	}
	check_config_block(lines, start, game_dt, error);
}
