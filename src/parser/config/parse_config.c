/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:01:47 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 15:12:22 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	register_config(int seen[7], char *line, t_game *game_dt,
		t_err *error)
{
	int	id;

	id = get_config_id(line);
	if (id < 0)
	{
		*error = ERR_CONF_ID;
		return (0);
	}
	seen[id]++;
	if (seen[id] > 1)
	{
		*error = ERR_CONF_DUP;
		return (0);
	}
	return (store_config_value(line, id, game_dt, error));
}

static void	init_seen(int seen[7])
{
	int	i;

	i = 0;
	while (i < 7)
	{
		seen[i] = 0;
		i++;
	}
}

static void	check_config_block(char **lines, int start, t_game *game_dt,
		t_err *error)
{
	int	i;
	int	seen[7];

	init_seen(seen);
	i = start;
	while (lines[i] && !*error)
	{
		if (is_empty_line(lines[i]))
			i++;
		else if (is_map_line(lines[i]))
			break ;
		else if (!register_config(seen, lines[i], game_dt, error))
			return ;
		else
			i++;
	}
	if (!*error && (!seen[0] || !seen[1] || !seen[2] || !seen[3] || !seen[5]
			|| !seen[6]))
		*error = ERR_CONF_MISS;
}

void	parse_graphics_config_block(char **lines, t_game *game_dt, t_err *error)
{
	int	start;

	start = skip_empty_lines(lines);
	if (!lines[start])
	{
		*error = ERR_FILE_BLANK;
		return ;
	}
	check_config_block(lines, start, game_dt, error);
}
