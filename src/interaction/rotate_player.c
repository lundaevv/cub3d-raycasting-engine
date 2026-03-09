#include "interaction.h"

void rotate_player(t_game *game_dt, double step) {
  if (game_dt->inp.a && game_dt->inp.d)
    return;
  if (game_dt->inp.a)
    game_dt->player.angle -= step; // Rotate left
  else if (game_dt->inp.d)
    game_dt->player.angle += step; // Rotate right
  if (game_dt->player.angle > M_PI * 2)
    game_dt->player.angle = 0 + step;
  else if (game_dt->player.angle < 0)
    game_dt->player.angle = M_PI * 2 - step;
}
