#include "main.h"
#include "types.h"
#include <math.h>

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
  // mlx->win_w = game_dt->map.cols * TILE_SIZE;
  // mlx->win_h = (game_dt->map.rows + 1) * TILE_SIZE;
  mlx->win_w = 2400;
  mlx->win_h = 600;
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
  // game_dt->player.angle = 3 * M_PI_2; //Player looking up "N"
  game_dt->player.angle = 0; // Player looking left "W"
  game_dt->inp.last_time = get_time_sec();
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

int clear_close_game(void *param) {
  t_game *game_dt = (t_game *)param;
  exit(0);
  return (0);
}

void draw_column(t_game game_dt, double proj_plane, double dist, double col_x) {
  const unsigned int ceil_col = 0x00303A6D;
  const unsigned int floor_col = 0x00261F1A;
  const unsigned int wall_col = 0x002F5200;
  int top;
  int bottom;
  int y;
  double wall_h;

  wall_h = ((double)TILE_SIZE * (double)WORLD_HEIGHT * proj_plane) / dist;
  top = (game_dt.mlx.win_h - (int)wall_h) / 2;
  bottom = (game_dt.mlx.win_h + (int)wall_h) / 2;
  if (top < 0)
    top = 0;
  if (bottom >= game_dt.mlx.win_h)
    bottom = game_dt.mlx.win_h - 1;
  y = 0;
  while (y < top) {
    putp(&game_dt.mlx.frame, col_x, y, ceil_col);
    y++;
  }
  while (y <= bottom) {
    putp(&game_dt.mlx.frame, col_x, y, wall_col);
    y++;
  }
  while (y < game_dt.mlx.win_h) {
    putp(&game_dt.mlx.frame, col_x, y, floor_col);
    y++;
  }
}

void draw_map(t_game game_dt) {
  double fov;
  double proj_plane;
  int x;

  fov = FOV;
  if (fov <= 1e-6 || fov >= M_PI - 1e-6)
    fov = M_PI / 2.0;
  proj_plane = ((double)game_dt.mlx.win_w * 0.5) / tan(fov / 2);
  x = 0;
  while (x < game_dt.mlx.win_w) {
    t_raycast_data ray_data;
    double camera_x;
    double ray_offset;
    double ray_angle;
    double dist;

    camera_x = (2.0 * ((double)x + 0.5) / (double)game_dt.mlx.win_w) - 1.0;
    ray_offset = atan(camera_x * tan(fov / 2));
    ray_data = raycast(game_dt, game_dt.player.angle + ray_offset);
    /* Perpendicular distance to camera plane (fish-eye corrected). */
    dist = ray_data.len * cos(ray_offset);
    if (dist < 1.0)
      dist = 1.0;
    x++;
  }
}

int render(t_game game_dt) {
  // draw_2d_map(game_dt);
  // draw_player(game_dt);
  // draw_ray(game_dt, game_dt.player.angle, 20);
  draw_map(game_dt);
  mlx_put_image_to_window(game_dt.mlx.context, game_dt.mlx.win,
                          game_dt.mlx.frame.img, 0, 0);
  return (0);
}

int update(t_game *game_dt) {
  const double t = get_time_sec();
  double dt = t - game_dt->inp.last_time;
  double step = dt * 40; // 200 pixels per second

  game_dt->inp.last_time = t;
  if (dt > 0.05)
    dt = 0.05;
  move_player(game_dt, step);
  rotate_player(game_dt, step * 0.1);
  render(*game_dt);
  return (0);
}

int main(int argc, char **argv) {
  t_game game_dt;

  temp_init(&game_dt);

  mlx_hook(game_dt.mlx.win, KEY_PRESS, KEY_PRESS_MASK, on_key_press, &game_dt);
  mlx_hook(game_dt.mlx.win, KEY_RELEASE, KEY_RELEASE_MASK, on_key_release,
           &game_dt);
  mlx_hook(game_dt.mlx.win, DESTROY_NOTIFY, 0, clear_close_game, &game_dt);

  mlx_loop_hook(game_dt.mlx.context, update, &game_dt);
  mlx_loop(game_dt.mlx.context);
}
