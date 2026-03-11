/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:22:23 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 15:22:24 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACTION_H
# define INTERACTION_H

# include "config.h"
# include "types.h"
# include "utils.h"
# include <math.h>

void	move_player(t_game *game_dt, double step);
void	rotate_player(t_game *game_dt, double step);

int		on_key_press(int key, void *param);
int		on_key_release(int key, void *param);
int		on_mouse_move(int x, int y, void *param);

#endif
