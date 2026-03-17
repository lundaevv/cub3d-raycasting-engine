/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:22:28 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/16 15:43:44 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_H

#include "../mlx/mlx.h"
#include "config.h"
#include "errors.h"
#include "interaction.h"
#include "minimap.h"
#include "types.h"
#include "utils.h"
#include <math.h>

void render(t_game *game_dt);
void draw_map(t_game game_dt);
void draw_door(t_game *game_dt, t_raycast_data ray_data, double wall_h,
               const int col_x);

void show_menu_ui(t_game *game_dt, t_err *err);

// Uttility functions for drawing pixels and blitting images
void putp(t_img *im, int x, int y, unsigned int c);
unsigned int getp(t_img *im, int x, int y);

t_raycast_data raycast(t_game game_dt, double angle);
double get_texture_x(t_game game_dt, t_raycast_data ray_data,
                     const double sin_val, const double cos_val);

#endif
