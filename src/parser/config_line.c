#include "../../includes/parser_internal.h"

static int	parse_color_key(t_game *game_dt, t_err *error, char *line,
		t_parse_state *parse_state)
{
	if (ft_strncmp(line, "F", 1) == 0 && (line[1] == ' ' || line[1] == '\t'))
	{
		if (parse_state->floor_set)
			return ((*error = ERR_CONF_DUP) == ERR_CONF_DUP);
		if (!parse_rgb(skip_spaces(line + 1), &game_dt->config.floor_rgb))
			return ((*error = ERR_CONF_COLOR) == ERR_CONF_COLOR);
		parse_state->floor_set = 1;
		parse_state->conf_count++;
		return (1);
	}
	if (ft_strncmp(line, "C", 1) == 0 && (line[1] == ' ' || line[1] == '\t'))
	{
		if (parse_state->ceil_set)
			return ((*error = ERR_CONF_DUP) == ERR_CONF_DUP);
		if (!parse_rgb(skip_spaces(line + 1), &game_dt->config.ceil_rgb))
			return ((*error = ERR_CONF_COLOR) == ERR_CONF_COLOR);
		parse_state->ceil_set = 1;
		parse_state->conf_count++;
		return (1);
	}
	return (0);
}

int	parse_config_line(t_game *game_dt, t_err *error, char *line,
		t_parse_state *parse_state)
{
	char	*trimmed_line;

	trimmed_line = skip_spaces(line);
	if (parse_color_key(game_dt, error, trimmed_line, parse_state))
		return (1);
	return (parse_path_key(game_dt, error, trimmed_line, parse_state));
}
