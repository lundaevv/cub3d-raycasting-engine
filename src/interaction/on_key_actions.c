/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:17:51 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 15:17:52 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "interaction.h"

static void toggle_mouse(t_game *game_dt) {
  game_dt->inp.mouse_on = !game_dt->inp.mouse_on;
  game_dt->inp.mouse_ready = 0;
  game_dt->inp.mouse_lock = 0;
  if (game_dt->inp.mouse_on)
    mlx_mouse_hide(game_dt->mlx.context, game_dt->mlx.win);
  else
    mlx_mouse_show(game_dt->mlx.context, game_dt->mlx.win);
}

int on_key_press(int key, void *param) {
  t_game *game_dt;

  game_dt = (t_game *)param;
  if (key == K_ESC) {
    destroy(game_dt);
    exit(0);
  }
  if (key == K_M)
    toggle_mouse(game_dt);
  if (key == K_W || key == K_UP)
    game_dt->inp.w = 1;
  if (key == K_S || key == K_DOWN)
    game_dt->inp.s = 1;
  if (key == K_A)
    game_dt->inp.a = 1;
  if (key == K_LEFT)
    game_dt->inp.left = 1;
  if (key == K_D)
    game_dt->inp.d = 1;
  if (key == K_RIGHT)
    game_dt->inp.right = 1;
  if (key == K_E)
    game_dt->inp.e = 1;
  return (0);
}

int on_key_release(int key, void *param) {
  t_game *game_dt;

  game_dt = (t_game *)param;
  if (key == K_W || key == K_UP)
    game_dt->inp.w = 0;
  if (key == K_S || key == K_DOWN)
    game_dt->inp.s = 0;
  if (key == K_A)
    game_dt->inp.a = 0;
  if (key == K_LEFT)
    game_dt->inp.left = 0;
  if (key == K_D)
    game_dt->inp.d = 0;
  if (key == K_RIGHT)
    game_dt->inp.right = 0;
  if (key == K_E)
    game_dt->inp.e = 0;
  return (0);
}
