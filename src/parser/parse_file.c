/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:02:02 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/06 12:29:46 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	count_file_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

static char	**alloc_lines(int count, t_err *error)
{
	char	**lines;

	lines = malloc(sizeof(char *) * (count + 1));
	if (!lines)
	{
		*error = ERR_MEM;
		return (NULL);
	}
	return (lines);
}

static int	fill_lines(int fd, char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		lines[i] = get_next_line(fd);
		if (!lines[i])
			return (0);
		i++;
	}
	lines[i] = NULL;
	return (1);
}

static int	read_file_lines(char *path, char **lines, int count, t_err *error)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		*error = ERR_OPEN;
		return (0);
	}
	if (!fill_lines(fd, lines, count))
	{
		close(fd);
		free_lines(lines);
		*error = ERR_READ;
		return (0);
	}
	close(fd);
	return (1);
}

char	**read_map_file_lines(t_game *game_dt, t_err *error)
{
	int		fd;
	int		line_count;
	char	**lines;

	fd = open(game_dt->map_path, O_RDONLY);
	if (fd < 0)
	{
		*error = ERR_OPEN;
		return (NULL);
	}
	line_count = count_file_lines(fd);
	close(fd);
	if (!line_count)
	{
		*error = ERR_FILE_EMPTY;
		return (NULL);
	}
	lines = alloc_lines(line_count, error);
	if (!lines)
		return (NULL);
	if (!read_file_lines(game_dt->map_path, lines, line_count, error))
		return (NULL);
	return (lines);
}
