/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_boundary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:38:04 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/06 12:37:23 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	validate_map_terminator(char **lines, int i, t_err *error)
{
	while (lines[i])
	{
		if (!is_empty_line(lines[i]))
		{
			*error = ERR_MAP_GAP;
			return ;
		}
		i++;
	}
	*error = ERR_MAP_TRAIL;
}
