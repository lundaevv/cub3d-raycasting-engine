/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:37 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 18:11:47 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "config.h"
# include "errors.h"
# include "types.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>

double	get_time_sec(void);
t_cell	get_cell_type(t_game game_dt, int x, int y);

void	init_game(t_game *game_dt, t_err *error, int argc, char **argv);
void	init_graphics(t_game *game_dt, t_err *error);
void	destroy(t_game *game_dt);
void	free_graphics_data(t_game *g);
void	validate_args(t_err *error, int argc, char **argv);

#endif
