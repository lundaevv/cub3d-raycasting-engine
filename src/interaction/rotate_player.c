/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:17:26 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/17 14:17:55 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interaction.h"

void	rotate_player(t_game *game_dt, double step)
{
	if (game_dt->inp.left && game_dt->inp.right)
		return ;
	if (game_dt->inp.left)
		game_dt->player.angle -= step;
	else if (game_dt->inp.right)
		game_dt->player.angle += step;
	if (game_dt->player.angle > M_PI * 2)
		game_dt->player.angle = 0 + step;
	else if (game_dt->player.angle < 0)
		game_dt->player.angle = M_PI * 2 - step;
}
