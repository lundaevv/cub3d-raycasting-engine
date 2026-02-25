#include "includes/main.h"

int temp_init(t_game *game_dt) {
  t_mlx *mlx;

  *game_dt = (t_game){0};
  char **src =
      (char *[15]){"111111111111111", "100001000000001", "10P000000000001",
                   "100000001D111D1", "101100001001001", "100000011111001",
                   "100100001000001", "100100001000111", "10000000D000111",
                   "111111111111111"};
  game_dt->map.grid = malloc(sizeof(char *) * 15);
  for (int i = 0; i < 10; i++)
    game_dt->map.grid[i] = strdup(src[i]); // src is const char *[15]

  game_dt->map.rows = 10;
  game_dt->map.cols = 15;
  //
  mlx = &game_dt->mlx;
  mlx->context = mlx_init();
  mlx->win_w = game_dt->map.cols * TILE_SIZE;
  mlx->win_h = game_dt->map.rows * TILE_SIZE;
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

  game_dt->player.pos = (t_vec){(3 - 1) * TILE_SIZE + TILE_SIZE / 2,
                                (3 - 1) * TILE_SIZE + TILE_SIZE / 2};
  game_dt->player.angle = 0;
  game_dt->inp.last_time = get_time_sec();
  return 1;
}

t_cell get_cell_type(t_game game_dt, int x, int y) {
  const t_map *map = &game_dt.map;
  const int cur_row = y / TILE_SIZE;
  const int cur_col = x / TILE_SIZE;

  // printf("var = %d\n", cur_row);
  if (cur_row > map->rows || cur_col > map->cols)
    return c_unknown;
  if (map->grid[cur_row][cur_col] == '0')
    return c_empty;
  if (map->grid[cur_row][cur_col] == '1')
    return c_wall;
  if (map->grid[cur_row][cur_col] == 'D')
    return c_door;
  return c_unknown;
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

int draw_ray(t_game game_dt, double ray_angle) {
  const int ray_len = 20;
  int i;

  i = 0;
  while (i < ray_len) {
    putp(&game_dt.mlx.frame, game_dt.player.pos.x + cos(ray_angle) * i,
         game_dt.player.pos.y + sin(ray_angle) * i, 0x0000FFFF);
    i++;
  }
  return (0);
}

int render(t_game game_dt) {
  draw_2d_map(game_dt);
  draw_player(game_dt);
  draw_ray(game_dt, game_dt.player.angle);
  mlx_put_image_to_window(game_dt.mlx.context, game_dt.mlx.win,
                          game_dt.mlx.frame.img, 0, 0);
  return (0);
}

int clear_close_game(void *param) {
  t_game *game_dt = (t_game *)param;
  exit(0);
  return (0);
}

static int on_key_press(int key, void *param) {
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

static int on_key_release(int key, void *param) {
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
int update(void *param) {
  t_game *game_dt = (t_game *)param;

  double t = get_time_sec();
  double dt = t - game_dt->inp.last_time;
  game_dt->inp.last_time = t;

  if (dt > 0.05)
    dt = 0.05;

  double step = dt * 100; // 200 pixels per second
  printf("Player pos: x-%f, y-%f, angle-%f, time-%f, dt-%f, step-%f\n",
         game_dt->player.pos.x, game_dt->player.pos.y, game_dt->player.angle, t,
         dt, step);

  if (game_dt->inp.w) {
    game_dt->player.pos.x += cos(game_dt->player.angle) * step;
    game_dt->player.pos.y += sin(game_dt->player.angle) * step;
  }
  if (game_dt->inp.s) {
    game_dt->player.pos.x -= cos(game_dt->player.angle) * step;
    game_dt->player.pos.y -= sin(game_dt->player.angle) * step;
  }
  if (game_dt->inp.a) {
    game_dt->player.angle -= step * 0.02; // Rotate left
  }
  if (game_dt->inp.d) {
    game_dt->player.angle += step * 0.02; // Rotate right
  }

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
