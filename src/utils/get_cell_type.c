/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cell_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:30:05 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 15:30:06 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include <stdio.h>

t_cell get_cell_type(t_game game_dt, int x, int y) {
  const t_map *map = &game_dt.map;
  const int cur_row = y / TILE_SIZE;
  const int cur_col = x / TILE_SIZE;

  if (x < 0 || y < 0)
    return (c_unknown);
  if (cur_row > map->rows || cur_col > map->cols)
    return (c_unknown);
  if (map->grid == NULL || map->grid[cur_row] == NULL)
    return (c_empty);
  if (map->grid[cur_row][cur_col] == '0')
    return (c_empty);
  if (map->grid[cur_row][cur_col] == '1')
    return (c_wall);
  if (map->grid[cur_row][cur_col] == 'D')
    return (c_door);
  return (c_unknown);
}
