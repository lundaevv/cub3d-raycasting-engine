#include "../../includes/parser_internal.h"

static const char	*g_path_keys[4] = {"NO", "SO", "WE", "EA"};

int	parse_path_key(t_game *game_dt, t_err *error,
		char *line, t_parse_state *parse_state)
{
	char	**paths[4];
	int		index;

	paths[0] = &game_dt->config.path_nw;
	paths[1] = &game_dt->config.path_sw;
	paths[2] = &game_dt->config.path_ww;
	paths[3] = &game_dt->config.path_ew;
	index = 0;
	while (index < 4)
	{
		if (ft_strncmp(line, g_path_keys[index], 2) == 0
			&& (line[2] == ' ' || line[2] == '\t'))
		{
			if (!set_path(paths[index], skip_spaces(line + 2), error))
				return (1);
			parse_state->conf_count++;
			return (1);
		}
		index++;
	}
	return (0);
}
