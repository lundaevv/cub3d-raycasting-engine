#include "main.h"
#include "types.h"
#include <math.h>

void init_texture(t_game *game_dt) {
  t_cell_side i = EAST_S;
  game_dt->graphics.textures[i].img = mlx_xpm_file_to_image(
      game_dt->mlx.context, "textures/wall_E.xpm",
      &game_dt->graphics.textures[i].w, &game_dt->graphics.textures[i].h);
  game_dt->graphics.textures[i].a = mlx_get_data_addr(
      game_dt->graphics.textures[i].img, &game_dt->graphics.textures[i].bpp,
      &game_dt->graphics.textures[i].ll, &game_dt->graphics.textures[i].e);
  i = SOUTH_S;
  game_dt->graphics.textures[i].img = mlx_xpm_file_to_image(
      game_dt->mlx.context, "textures/wall_S.xpm",
      &game_dt->graphics.textures[i].w, &game_dt->graphics.textures[i].h);
  game_dt->graphics.textures[i].a = mlx_get_data_addr(
      game_dt->graphics.textures[i].img, &game_dt->graphics.textures[i].bpp,
      &game_dt->graphics.textures[i].ll, &game_dt->graphics.textures[i].e);
  i = WEST_S;
  game_dt->graphics.textures[i].img = mlx_xpm_file_to_image(
      game_dt->mlx.context, "textures/wall_W.xpm",
      &game_dt->graphics.textures[i].w, &game_dt->graphics.textures[i].h);
  game_dt->graphics.textures[i].a = mlx_get_data_addr(
      game_dt->graphics.textures[i].img, &game_dt->graphics.textures[i].bpp,
      &game_dt->graphics.textures[i].ll, &game_dt->graphics.textures[i].e);
  i = NORTH_S;
  game_dt->graphics.textures[i].img = mlx_xpm_file_to_image(
      game_dt->mlx.context, "textures/wall_N.xpm",
      &game_dt->graphics.textures[i].w, &game_dt->graphics.textures[i].h);
  game_dt->graphics.textures[i].a = mlx_get_data_addr(
      game_dt->graphics.textures[i].img, &game_dt->graphics.textures[i].bpp,
      &game_dt->graphics.textures[i].ll, &game_dt->graphics.textures[i].e);
}

int temp_init(t_game *game_dt) {
  t_mlx *mlx;

  *game_dt = (t_game){0};
  char **src =
      (char *[15]){"111111111111111", "100001000000001", "100000000000001",
                   "100000001D111D1", "101100001001001", "100000011111001",
                   "100100001000001", "100100001000111", "10000000D000111",
                   "111111111111111"};
  game_dt->map.grid = malloc(sizeof(char *) * 15);
  for (int i = 0; i < 10; i++)
    game_dt->map.grid[i] = strdup(src[i]); // src is const char *[15]

  game_dt->map.rows = 9;
  game_dt->map.cols = 15;
  //
  mlx = &game_dt->mlx;
  mlx->context = mlx_init();
  mlx->win_w = 1920;
  mlx->win_h = 1080;
  mlx->win = mlx_new_window(mlx->context, mlx->win_w, mlx->win_h, "So Long");
  mlx->frame =
      (t_img){.img = mlx_new_image(mlx->context, mlx->win_w, mlx->win_h),
              0,
              0,
              0,
              0,
              mlx->win_w,
              mlx->win_h};
  mlx->frame.a = mlx_get_data_addr(mlx->frame.img, &mlx->frame.bpp,
                                   &mlx->frame.ll, &mlx->frame.e);

  game_dt->player.pos = (t_vec){(3 - 1) * TILE_SIZE + (double)TILE_SIZE / 2,
                                (3 - 1) * TILE_SIZE + (double)TILE_SIZE / 2};
  game_dt->player.angle = 0; // Player looking right "E"
  game_dt->inp.last_time = get_time_sec();

  init_texture(game_dt);
  game_dt->graphics.ceil_col = 0x00303A6D;
  game_dt->graphics.floor_col = 0x00261F1A;
  return 1;
}

int draw_2d_map(t_game game_dt) {
  t_cell cell_type;
  int i;
  int j;

  i = 0;
  while (i < game_dt.mlx.win_h) {
    j = 0;
    while (j < game_dt.mlx.win_w) {
      cell_type = get_cell_type(game_dt, j, i);
      if (i % TILE_SIZE == 0 || j % TILE_SIZE == 0)
        putp(&game_dt.mlx.frame, j, i, 0x00FF0000);
      else if (cell_type == c_wall)
        putp(&game_dt.mlx.frame, j, i, 0x002F5200);
      else
        putp(&game_dt.mlx.frame, j, i, 0);
      j++;
    }
    i++;
  }
  return (0);
}

int draw_player(t_game game_dt) {
  const int offset = 1 * 2 + 1;
  int px = (int)game_dt.player.pos.x;
  int py = (int)game_dt.player.pos.y;
  int i;
  int j;

  i = 0; // rows
  while (i < offset) {
    j = 0;
    while (j < offset) {
      putp(&game_dt.mlx.frame, px + j - 1, py + i - 1, 0x0000FF00);
      j++;
    }
    i++;
  }
  return (0);
}

int draw_ray(t_game game_dt, double ray_angle, const double ray_len) {
  int i;

  i = 0;
  while (i < ray_len) {
    putp(&game_dt.mlx.frame, game_dt.player.pos.x + cos(ray_angle) * i,
         game_dt.player.pos.y + sin(ray_angle) * i, 0x0000FFFF);
    i++;
  }
  return (0);
}

int main(int argc, char **argv) {
  t_game game_dt;

  temp_init(&game_dt);
  render(game_dt);
}
