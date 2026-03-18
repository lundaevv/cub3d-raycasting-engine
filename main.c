/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:30:52 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/17 14:25:06 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_game	game_dt;
	t_err	error;

	if (argc != 2)
		return (print_errno(ERR_ARGS));
	init_game(&game_dt, &error);
	if (!error)
		validate_arg(&game_dt, &error, argv);
	if (!error)
		parse(&game_dt, &error);
	if (!error)
		init_graphics(&game_dt, &error);
	if (!error)
		render(&game_dt);
	destroy(&game_dt);
	return (print_errno(error));
}
