/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:37 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/02 14:50:24 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types.h"
# include "errors.h"

double	get_time_sec(void);

void	init_game(t_game *game_dt, t_err *error, int argc, char **argv);
void	init_graphics(t_game *game_dt, t_err *error);
void	destroy(t_game *game_dt);
void	validate_args(t_err *error, int argc, char **argv);

#endif
