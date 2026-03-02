/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:08:49 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/02 21:04:38 by vlundaev         ###   ########.fr       */
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

static int	store_texture(int id, char *value, t_game *game_dt, t_err *error)
{
	if (!validate_texture_path(value))
	{
		free(value);
		*error = ERR_CONF_PATH;
		return (0);
	}
	set_texture_path(&game_dt->config, id, value);
	return (1);
}

static int	store_color(int id, char *value, t_game *game_dt, t_err *error)
{
	int	color;

	if (!parse_rgb_color(value, &color))
	{
		*error = ERR_CONF_COLOR;
		return (0);
	}
	if (id == 4)
		game_dt->config.floor_rgb = color;
	else
		game_dt->config.ceil_rgb = color;
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
		return (store_texture(id, value, game_dt, error));
	if (!store_color(id, value, game_dt, error))
	{
		free(value);
		return (0);
	}
	free(value);
	return (1);
}
