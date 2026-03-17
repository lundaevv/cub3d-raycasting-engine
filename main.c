/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:30:52 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/16 15:47:03 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
init_game → parse → init_graphics → render → destroy (called with errno)

init_game()		-	only zero the t_game, set ERR_OK, validate
argc/extension, store map_path. parse()			-	open/read .cub,
parse texture/color directives, collect raw map lines, validate the map,
normalize it, extract player spawn/direction, and fill game_dt->config,
                                                                                game_dt->map, and game_dt->player.
int_graphics	-	Only after parse succeeds:
                                                                                MLX init, window, images, texture
loading from the parsed paths. render()		-	use already-parsed state
only. No file parsing here. destroy()		-	free parser allocations
even if runtime never started.
*/

int main(int argc, char **argv) {
  t_game game_dt;
  t_err error;

  if (argc > 2)
    return print_errno(ERR_ARGS);
  init_game(&game_dt, &error);
  if (!error && argc == 1)
    show_menu_ui(&game_dt, &error);
  if (!error && argc != 1)
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
