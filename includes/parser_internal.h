/*
internal parser helpers (not exposed outside parser module)
*/

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# include "main.h"

char	*skip_spaces(char *str);
int		set_path(char **dst, const char *str, t_err *error);
int		parse_rgb(const char *str, int *out);
int		parse_path_key(t_game *game_dt, t_err *error,
			char *line, t_parse_state *parse_state);
int		parse_config_line(t_game *game_dt, t_err *error, char *line,
			t_parse_state *parse_state);

#endif
