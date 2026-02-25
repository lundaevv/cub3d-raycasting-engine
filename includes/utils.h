/*
small, cross‑module helpers that both parser and render
can use without creating circular dependencies

if any...
*/

#ifndef UTILS_H
#define UTILS_H

#include "types.h"
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time_sec(void);

void    init(t_game *game_dt, t_err *error, int argc, char **argv);
void    destroy(t_game *game_dt);
void    validate_args(t_err *error, int argc, char **argv);


#endif
