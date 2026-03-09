#include "render.h"

static int on_close(void *param) {
  t_game *game_dt;

  game_dt = (t_game *)param;
  destroy(game_dt);
  exit(0);
  return (0);
}

static int update(t_game *game_dt) {
  const double t = get_time_sec();
  double dt = t - game_dt->inp.last_time;
  double step = dt * 40; // 200 pixels per second

  game_dt->inp.last_time = t;
  if (dt > 0.05)
    dt = 0.05;
  move_player(game_dt, step);
  rotate_player(game_dt, step * 0.1);
  draw_map(*game_dt);
  mlx_put_image_to_window(game_dt->mlx.context, game_dt->mlx.win,
                          game_dt->mlx.frame.img, 0, 0);
  return (0);
}

void render(t_game game_dt) {
  mlx_hook(game_dt.mlx.win, KEY_PRESS, KEY_PRESS_MASK, on_key_press, &game_dt);
  mlx_hook(game_dt.mlx.win, KEY_RELEASE, KEY_RELEASE_MASK, on_key_release,
           &game_dt);
  mlx_hook(game_dt.mlx.win, DESTROY_NOTIFY, 0, on_close, &game_dt);
  mlx_loop_hook(game_dt.mlx.context, update, &game_dt);
  mlx_loop(game_dt.mlx.context);
}
