#ifndef INTERACTION_H
#define INTERACTION_H

#include "config.h"
#include "types.h"
#include "utils.h"
#include <math.h>

void move_player(t_game *game_dt, double step);
void rotate_player(t_game *game_dt, double step);

int on_key_press(int key, void *param);
int on_key_release(int key, void *param);

#endif
