/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:40 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/16 12:46:56 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
TODO: init struct + init mlx_base
NOTHING ELSE!
*/
void	init_game(t_game *game_dt, t_err *error, int argc, char **argv)
{
	*game_dt = (t_game){0};
	*error = ERR_OK;
	validate_args(error, argc, argv);
	if (!*error)
		game_dt->map_path = argv[1];
}
