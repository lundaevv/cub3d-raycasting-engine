#include "errors.h"
#include "render.h"
#include "types.h"
#include "utils.h"

static int on_close(void *param) {
  t_game *game_dt;

  game_dt = (t_game *)param;
  destroy(game_dt);
  exit(0);
  return (0);
}

void show_menu_ui(t_game *game_dt, t_err *err) {
  (void)err;
  t_glyph g_font[64];

  init_g_font(g_font);
  draw_text(&game_dt->mlx.frame, "HELLO, WORLD!",
            (t_txt_dt){g_font, 40, 40, 4, 0x00FFFFFF});
  draw_text(&game_dt->mlx.frame, "score: 150  hp: 99%",
            (t_txt_dt){g_font, 40, 100, 3, 0x0000FF00});
  // draw_text(&game_dt->mlx.frame, 40, 150, "symbols: +-=_/\\\\()[]<>*&@#%^",
  // 2,
  //           0x00FFD700);
  // draw_text(&game_dt->mlx.frame, 40, 210, "multi-line:\nline 2\nline 3", 3,
  //           0x00FF5555);
  draw_text_centered(&game_dt->mlx.frame, "CENTERED TEXT",
                     (t_txt_dt){g_font, 500, 500, 5, 0x0055AAFF});
  mlx_hook(game_dt->mlx.win, DESTROY_NOTIFY, 0, on_close, game_dt);
  mlx_hook(game_dt->mlx.win, MOTION_NOTIFY, POINTER_MOTION_MASK, on_mouse_move,
           game_dt);
  mlx_mouse_hide(game_dt->mlx.context, game_dt->mlx.win);
  // mlx_loop_hook(game_dt->mlx.context, update, game_dt);
  mlx_loop(game_dt->mlx.context);
}
