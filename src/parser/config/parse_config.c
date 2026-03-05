/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:01:47 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/05 18:34:48 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	register_config(int seen[9], char *line,
	t_game *game_dt, t_err *error)
{
	int		id;

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
	if (!*error && (!seen[0] || !seen[1] || !seen[2] || !seen[3]
			|| !seen[7] || !seen[8]))
		*error = ERR_CONF_MISS;
}

void	parse_config(char **lines, t_game *game_dt, t_err *error)
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
