#include "interaction.h"

int on_key_press(int key, void *param) {
  t_game *game_dt = (t_game *)param;

  // printf("Player pos: x-%f, y-%f\n", game_dt->player.pos.x,
  //        game_dt->player.pos.y);
  if (key == K_ESC)
    exit(0);
  if (key == K_W || key == K_UP)
    game_dt->inp.w = 1;
  if (key == K_S || key == K_DOWN)
    game_dt->inp.s = 1;
  if (key == K_A || key == K_LEFT)
    game_dt->inp.a = 1;
  if (key == K_D || key == K_RIGHT)
    game_dt->inp.d = 1;
  return (0);
}

int on_key_release(int key, void *param) {
  t_game *game_dt = (t_game *)param;

  if (key == K_W || key == K_UP)
    game_dt->inp.w = 0;
  if (key == K_S || key == K_DOWN)
    game_dt->inp.s = 0;
  if (key == K_A || key == K_LEFT)
    game_dt->inp.a = 0;
  if (key == K_D || key == K_RIGHT)
    game_dt->inp.d = 0;
  return (0);
}
