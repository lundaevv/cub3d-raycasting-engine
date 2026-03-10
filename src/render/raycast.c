#include "render.h"
#include "types.h"

static int is_colided(t_game game_dt, t_vec coord) {
  if (coord.x < 0 || coord.y < 0)
    return 1;
  if (!(get_cell_type(game_dt, coord.x, coord.y) == c_empty))
    return 1;
  return 0;
}

static double cast_ver(t_game game_dt, const double calc_sin,
                       const double calc_cos, const t_vec step) {
  t_vec coord;
  t_vec hit;
  double calc_tan;

  if (fabs(calc_cos) < 1e-9)
    return (INFINITY);
  calc_tan = calc_sin / calc_cos;
  coord.x = floor(game_dt.player.pos.x / TILE_SIZE) * TILE_SIZE;
  if (step.x > 0)
    coord.x += TILE_SIZE;
  coord.y = game_dt.player.pos.y + (coord.x - game_dt.player.pos.x) * calc_tan;
  hit = coord;
  if (step.x < 0)
    hit.x -= 0.0001;
  while (!is_colided(game_dt, hit)) {
    coord.x += TILE_SIZE * step.x;
    coord.y += TILE_SIZE * step.x * calc_tan;
    hit = coord;
    if (step.x < 0)
      hit.x -= 0.0001;
  }
  return (fabs((coord.x - game_dt.player.pos.x) / calc_cos));
}

static double cast_hor(t_game game_dt, const double calc_sin,
                       const double calc_cos, const t_vec step) {
  t_vec coord;
  t_vec hit;
  double calc_ctan;

  if (fabs(calc_sin) < 1e-9)
    return (INFINITY);
  calc_ctan = calc_cos / calc_sin;
  coord.y = floor(game_dt.player.pos.y / TILE_SIZE) * TILE_SIZE;
  if (step.y > 0)
    coord.y += TILE_SIZE;
  coord.x = game_dt.player.pos.x + (coord.y - game_dt.player.pos.y) * calc_ctan;
  hit = coord;
  if (step.y < 0)
    hit.y -= 0.0001;
  while (!is_colided(game_dt, hit)) {
    coord.y += TILE_SIZE * step.y;
    coord.x += TILE_SIZE * step.y * calc_ctan;
    hit = coord;
    if (step.y < 0)
      hit.y -= 0.0001;
  }
  return (fabs((coord.y - game_dt.player.pos.y) / calc_sin));
}

static t_cell_side which_side(char is_hor, t_vec step) {
  if (is_hor) {
    if (step.y < 0)
      return (NORTH_S);
    return (SOUTH_S);
  }
  if (step.x < 0)
    return (WEST_S);
  return (EAST_S);
}

t_raycast_data raycast(t_game game_dt, double angle) {
  const double calc_sin = sin(angle);
  const double calc_cos = cos(angle);
  t_vec len;
  t_vec step;
  t_raycast_data ray_data;

  step = (t_vec){1, 1};
  if (calc_sin < 0)
    step.y = -1;
  if (calc_cos < 0)
    step.x = -1;
  len.y = cast_ver(game_dt, calc_sin, calc_cos, step);
  len.x = cast_hor(game_dt, calc_sin, calc_cos, step);
  if (len.y < len.x)
    ray_data = (t_raycast_data){len.y, which_side(0, step), 0};
  else
    ray_data = (t_raycast_data){.len = len.x, .side = which_side(1, step), 0};
  ray_data.tex_x = get_texture_x(game_dt, ray_data, calc_sin, calc_cos);
  return (ray_data);
}
