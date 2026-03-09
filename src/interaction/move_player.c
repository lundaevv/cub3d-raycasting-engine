#include "interaction.h"
#include "types.h"

static int is_collided(t_game game_dt, t_vec coords) {
  if (coords.x <= 0)
    coords = (t_vec){0, coords.y};
  if (coords.y <= 0)
    coords = (t_vec){coords.x, 0};
  if (!(get_cell_type(game_dt, coords.x, coords.y) == c_empty))
    return (1);
  return 0;
}

void move_player(t_game *game_dt, double step) {
  const double cos_val = cos(game_dt->player.angle);
  const double sin_val = sin(game_dt->player.angle);
  const double offset = step * 10;
  t_vec new_pos;
  t_vec new_pos_collision;

  new_pos = game_dt->player.pos;
  if (game_dt->inp.w) {
    new_pos = (t_vec){new_pos.x + cos_val * step, new_pos.y + sin_val * step};
    new_pos_collision =
        (t_vec){new_pos.x + cos_val * offset, new_pos.y + sin_val * offset};
  }
  if (game_dt->inp.s) {
    new_pos = (t_vec){new_pos.x - cos_val * step, new_pos.y - sin_val * step};
    new_pos_collision =
        (t_vec){new_pos.x - cos_val * offset, new_pos.y - sin_val * offset};
  }
  if (is_collided(*game_dt, new_pos_collision))
    return;
  if (is_collided(*game_dt, new_pos))
    return;
  game_dt->player.pos.x = new_pos.x;
  game_dt->player.pos.y = new_pos.y;
}
