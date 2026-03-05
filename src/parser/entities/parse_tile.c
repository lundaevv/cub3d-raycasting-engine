/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:50:19 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/05 19:47:47 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_wall(char c)
{
	return (c == '1');
}

int	is_walkable_tile(char c)
{
	return (c == '0' || c == 'D' || c == 'A'
	|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ' || c == 'D' || c == 'A');
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
