/*
parser public API + any parser‑specific types not needed elsewhere
*/

#ifndef PARSER_H
# define PARSER_H

# include "types.h"

void    parse(t_game *game_dt, t_err *error);

#endif
