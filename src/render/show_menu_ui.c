#include "errors.h"
#include "render.h"
#include "types.h"
#include "utils.h"
#include <math.h>

static int on_close(void *param) {
  t_game *game_dt;

  game_dt = (t_game *)param;
  destroy(game_dt);
  exit(0);
  return (0);
}

static int update(t_game *game_dt) {
  // const double t = get_time_sec();
  // int cur_menu;
  unsigned int col_selected = 0xfc0303; // #fc0303
  unsigned int col_def = 0xffffff;      // #ffffff

  t_glyph g_font[64];

  init_g_font(g_font);

  draw_text_centered(
      &game_dt->mlx.frame, "Cub3D",
      (t_txt_dt){g_font, game_dt->mlx.win_w / 2, 40, 10, 0x03fcdb});
  // const int prev_h = text_height("Cub3D", 10);
  // const int cur_h = text_height("Select map", 4);
  draw_text_centered(&game_dt->mlx.frame, "Select map",
                     (t_txt_dt){g_font, game_dt->mlx.win_w / 2,
                                game_dt->mlx.win_h / 2, 4, col_selected});
  draw_text_centered(
      &game_dt->mlx.frame, "Exit",
      (t_txt_dt){g_font, game_dt->mlx.win_w / 2,
                 game_dt->mlx.win_h / 2 + text_height("Exit", 4) + 20, 4,
                 col_def});

  mlx_put_image_to_window(game_dt->mlx.context, game_dt->mlx.win,
                          game_dt->mlx.frame.img, 0, 0);

  return (0);
}

void show_menu_ui(t_game *game_dt, t_err *err) {
  (void)err;
  t_glyph g_font[64];

  init_g_font(g_font);

  mlx_put_image_to_window(game_dt->mlx.context, game_dt->mlx.win,
                          game_dt->mlx.frame.img, 0, 0);
  mlx_hook(game_dt->mlx.win, DESTROY_NOTIFY, 0, on_close, game_dt);
  mlx_loop_hook(game_dt->mlx.context, update, game_dt);
  mlx_loop(game_dt->mlx.context);
}
