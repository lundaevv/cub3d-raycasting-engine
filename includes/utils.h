/*
small, cross‑module helpers that both parser and render
can use without creating circular dependencies

if any...
*/

#ifndef UTILS_H
#define UTILS_H

#include "config.h"
#include "types.h"
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time_sec(void);
t_cell get_cell_type(t_game game_dt, int x, int y);

#endif
