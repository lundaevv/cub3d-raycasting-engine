/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:33:03 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 17:44:13 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
#define MINIMAP_H

#include "types.h"

/*
off_x, off_y: minimap top-left corner offset from window edge
tile: minimap tile size in pixels
rows, cols: number of rows and columns to render in minimap
*/

typedef struct s_minimap {
  int off_x;
  int off_y;
  int tile;
  int rows;
  int cols;
} t_minimap;

t_minimap get_minimap_cfg(void);
void draw_minimap(t_game game_dt);
void draw_minimap_tile(t_game game_dt, t_minimap mm, t_vec pos, char tile);
void draw_minimap_player(t_game game_dt, t_minimap mm);

#endif
