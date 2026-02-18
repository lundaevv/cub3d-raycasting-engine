/*
parser public API + any parser‑specific types not needed elsewhere
*/

#ifndef PARSER_H
# define PARSER_H

# include "types.h"

typedef struct s_parse_state
{
	int	conf_count;
	int	in_map;
	int	floor_set;
	int	ceil_set;
}	t_parse_state;

void    parse(t_game *game_dt, t_err *error);

#endif
