#include "../../includes/main.h"

int	parse_config_line(t_game *game_dt, t_err *error, char *line,
		t_parse_state *parse_state);

static int	open_cub(t_game *game_dt, t_err *error)
{
	int	fd;

	fd = open(game_dt->map_path, O_RDONLY);
	if (fd < 0)
	{
		*error = ERR_OPEN;
		return (-1);
	}
	return (fd);
}

static char	*read_line_trim(int fd)
{
	char	*line;
	size_t	len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static void	handle_line(t_game *game_dt, t_err *error, char *line,
		t_parse_state *parse_state)
{
	if (*error)
		return ;
	if (!parse_state->in_map)
	{
		if (parse_config_line(game_dt, error, line, parse_state))
		{
			if (parse_state->conf_count == 6)
				parse_state->in_map = 1;
			return ;
		}
		parse_state->in_map = 1;
	}
	(void)line;
}

static void	parse_loop(t_game *game_dt, t_err *error,
		int fd, t_parse_state *parse_state)
{
	char	*line;

	line = read_line_trim(fd);
	while (line)
	{
		if (line[0] == '\0')
		{
			free(line);
			line = read_line_trim(fd);
			continue ;
		}
		handle_line(game_dt, error, line, parse_state);
		free(line);
		line = read_line_trim(fd);
	}
}

void	parse(t_game *game_dt, t_err *error)
{
	int		fd;
	t_parse_state	parse_state;

	parse_state.conf_count = 0;
	parse_state.in_map = 0;
	parse_state.floor_set = 0;
	parse_state.ceil_set = 0;
	fd = open_cub(game_dt, error);
	if (fd < 0)
		return ;
	parse_loop(game_dt, error, fd, &parse_state);
	close(fd);
}
