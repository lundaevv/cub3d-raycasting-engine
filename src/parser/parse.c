/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:26 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/02 14:46:57 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse(t_game *game_dt, t_err *error)
{
	char	**lines;

	if (!game_dt || !error)
		return ;
	lines = parse_file(game_dt, error);
	if (*error != ERR_OK)
		return ;
	parse_config(lines, game_dt, error);
	free_lines(lines);
}
