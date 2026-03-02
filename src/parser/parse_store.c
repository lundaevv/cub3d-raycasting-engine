/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:08:49 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/02 19:29:46 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	set_texture_path(t_config *config, int id, char *value)
{
	if (id == 0)
		config->path_nw = value;
	else if (id == 1)
		config->path_sw = value;
	else if (id == 2)
		config->path_ww = value;
	else if (id == 3)
		config->path_ew = value;
}

static int	validate_texture_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	store_config_value(char *line, int id, t_game *game_dt, t_err *error)
{
	char	*value;

	value = dup_trimmed_str(get_config_value(line));
	if (!value || !value[0])
	{
		free(value);
		if (id < 4)
			*error = ERR_CONF_PATH;
		else
			*error = ERR_CONF_COLOR;
		return (0);
	}
	if (id < 4)
	{
		if (!validate_texture_path(value))
		{
			free(value);
			*error = ERR_CONF_PATH;
			return (0);
		}
		set_texture_path(&game_dt->config, id, value);
	}
	else
		free(value);
	return (1);
}
