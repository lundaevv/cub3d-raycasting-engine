/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:53 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/17 14:25:32 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define STR_PROG_NAME "cub3d"
# define ERR_FMT "Error\n%s: %s\n"

# define ERRMSG_ARGS "invalid arguments"
# define ERRMSG_EXT "invalid extension"
# define ERRMSG_OPEN "cannot open file"
# define ERRMSG_READ "read failed"
# define ERRMSG_MEM "out of memory"
# define ERRMSG_CONF_DUP "duplicate config"
# define ERRMSG_CONF_MISS "missing config"
# define ERRMSG_DOOR_CONF_MISS "missing door config"
# define ERRMSG_CONF_PATH "invalid texture path"
# define ERRMSG_CONF_COLOR "invalid color"
# define ERRMSG_MAP_EMPTY "map missing"
# define ERRMSG_MAP_CHAR "invalid map char"
# define ERRMSG_MAP_DOOR "invalid door placement"
# define ERRMSG_MAP_PLAYER "invalid player count"
# define ERRMSG_MAP_GAP "empty line inside map"
# define ERRMSG_MAP_TRAIL "empty line after map"
# define ERRMSG_MAP_OPEN "map not closed"
# define ERRMSG_PARSE "parse error"
# define ERRMSG_MLX_INIT "mlx init failed :("
# define ERRMSG_NULL_PTR "null pointer passed to function"
# define ERRMSG_FILE_BLANK "no usable lines read from file"
# define ERRMSG_FILE_EMPTY "file is empty"
# define ERRMSG_CONF_ID "invalid config identifier"

typedef enum e_err
{
	ERR_OK = 0,
	ERR_ARGS,
	ERR_EXT,
	ERR_OPEN,
	ERR_READ,
	ERR_MEM,
	ERR_CONF_DUP,
	ERR_CONF_MISS,
	ERR_DOOR_CONF_MISS,
	ERR_CONF_PATH,
	ERR_CONF_COLOR,
	ERR_MAP_EMPTY,
	ERR_MAP_CHAR,
	ERR_MAP_DOOR,
	ERR_MAP_PLAYER,
	ERR_MAP_GAP,
	ERR_MAP_TRAIL,
	ERR_MAP_OPEN,
	ERR_PARSE,
	ERR_MLX_INIT,
	ERR_NULL_PTR,
	ERR_FILE_BLANK,
	ERR_FILE_EMPTY,
	ERR_CONF_ID
}			t_err;

int			print_msg(const char *str, const char *detail, int exit_no);
int			print_errno(t_err err);
const char	*msg_for_err(t_err err);

#endif