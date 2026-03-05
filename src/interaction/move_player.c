#include "interaction.h"

void move_player(t_game *game_dt, double step) {
  if (game_dt->inp.w) {
    game_dt->player.pos.x += cos(game_dt->player.angle) * step;
    game_dt->player.pos.y += sin(game_dt->player.angle) * step;
  }
  if (game_dt->inp.s) {
    game_dt->player.pos.x -= cos(game_dt->player.angle) * step;
    game_dt->player.pos.y -= sin(game_dt->player.angle) * step;
  }
}
