#include "utils.h"

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
