#include "includes/main.h"

int temp_init(t_game *game_dt) {
  t_mlx *mlx;

  *game_dt = (t_game){0};
  game_dt->map.grid =
      (char *[15]){"111111111111111", "100000000000001", "100000000000001",
                   "100000000000001", "100000000000001", "100000000000001",
                   "100000000000001", "100000000000001", "100000000000001",
                   "100000000000001", "100000000000001", "100000000000001",
                   "100000000000001", "100000000000001", "111111111111111"};
  game_dt->map.rows = 10;
  game_dt->map.cols = 15;
  mlx = &game_dt->mlx;
  mlx->context = mlx_init();
  mlx->window = mlx_new_window(mlx->context, game_dt->map.cols * TILE_SIZE,
                               game_dt->map.rows * TILE_SIZE, "So Long");
  mlx->frame = (t_img){0};
  mlx->frame.img = mlx_new_image(mlx->context, 200, 100);
  mlx->frame.a = mlx_get_data_addr(mlx->frame.img, &mlx->frame.bpp,
                                   &mlx->frame.ll, &mlx->frame.endian);
  putp(&mlx->frame, 1, 1, 0x00FFFF00);
  mlx_put_image_to_window(mlx->context, mlx->window, mlx->frame.img, 0, 0);
  return 1;
}

int draw_map_grid(t_game game_dt) {
  t_map *map = &game_dt.map;
  int i;
  int j;

  i = 0;
  while (i < 100) {
    j = 0;
    while (j < 200) {
      putp(&game_dt.mlx.frame, j, i, 0x00FF0000);
      j++;
    }
    i++;
  }
  mlx_put_image_to_window(game_dt.mlx.context, game_dt.mlx.window,
                          game_dt.mlx.frame.img, 0, 0);
  return (1);
}

int main(int argc, char **argv) {
  t_game game_dt;

  temp_init(&game_dt);
  // draw_map_grid(game_dt);
  // rendering(game_dt);
  mlx_loop(game_dt.mlx.context);
}
