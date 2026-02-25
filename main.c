/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:30:52 by vlundaev          #+#    #+#             */
/*   Updated: 2026/02/25 17:50:50 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

/*
init → parse → render → destroy (called with errno)

init() should set up shared state (mlx, textures, config).
parse() should fill a shared t_game/t_config.
render() should only use that state.
destroy() should free everything, even if parse failed.
*/

int	main(int argc, char **argv)
{
	t_game	game_dt;
	t_err	error;

	init_base(&game_dt, &error, argc, argv);
	if (!error)
		parse(&game_dt, &error);
	if (!error)
		init_runtime(&game_dt, &error);
	if (!error)
		render(&game_dt, &error);
	destroy(&game_dt);
	return (print_errno(error));
}
