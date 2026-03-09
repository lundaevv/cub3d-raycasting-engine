#ifndef RENDER_H
#define RENDER_H

#include "../mlx/mlx.h"
#include "config.h"
#include "interaction.h"
#include "types.h"
#include "utils.h"
#include <math.h>

void render(t_game game_dt);
int pre_render(t_game game_dt);
int draw_minimap(int **map, t_vec player_pos);
void draw_map(t_game game_dt);

int show_menu_ui();
int show_ingame_ui();

// Uttility functions for drawing pixels and blitting images
void putp(t_img *im, int x, int y, unsigned int c);
unsigned int getp(t_img *im, int x, int y);
void blit_copy(t_img *dst, t_img *src, int dx, int dy);
void blit_colorkey(t_img *dst, t_img *src, int dx, int dy);

t_raycast_data raycast(t_game game_dt, double angle);
double get_texture_x(t_game game_dt, t_raycast_data ray_data,
                     const double sin_val, const double cos_val);

#endif
