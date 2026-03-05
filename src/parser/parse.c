/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:26 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/05 17:41:27 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse(t_game *game_dt, t_err *error)
{
	char	**lines;

	lines = parse_file(game_dt, error);
	if (!*error)
		parse_config(lines, game_dt, error);
	if (!*error)
		parse_map(lines, game_dt, error);
	free_lines(lines);
}
