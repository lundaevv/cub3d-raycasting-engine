/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:40 by vlundaev          #+#    #+#             */
/*   Updated: 2026/02/25 17:54:48 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	init_base(t_game *game_dt, t_err *error, int argc, char **argv)
{
	*game_dt = (t_game){0};
	*error = ERR_OK;
	validate_args(error, argc, argv);
	if (*error == ERR_OK)
		game_dt->map_path = argv[1];
}
