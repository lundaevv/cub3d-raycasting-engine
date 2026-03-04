/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:53 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/04 19:11:51 by vlundaev         ###   ########.fr       */
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
# define ERRMSG_DOOR_CONF_MISS "missing door configs (DC/DO)"
# define ERRMSG_SPR_CONF_MISS "missing sprite config (SP)"
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

/*
	ERR_OK = 0,
	ERR_ARGS,			invalid arguments (argc, argv)
	ERR_EXT,			invalid file extension
	ERR_OPEN,			cannot open file (fopen)
	ERR_READ,			read failed (fread, getline)
	ERR_MEM,			out of memory (malloc)
	ERR_CONF_DUP,		duplicate config (e.g. multiple floor colors)
	ERR_CONF_MISS,		missing config (e.g. no ceiling color)
	ERR	DOOR_CONF_MISS,	door config missing (map has doors but no door textures)
	ERR_SPR_CONF_MISS,	spr conf missing (map has sprites but no sprite texture)
	ERR_CONF_PATH,		invalid texture path (file not found or not readable)
	ERR_CONF_COLOR,		invalid color (e.g. non-numeric, out of range)
	ERR_MAP_EMPTY,		map missing (no lines read)
	ERR_MAP_CHAR,		invalid map char (not in " 012NSEW")
	ERR_MAP_DOOR,		invalid door placement (not between walls)
	ERR_MAP_PLAYER,		invalid player count (not exactly 1)
	ERR_MAP_GAP,		empty line inside map
	ERR_MAP_TRAIL,		empty line after map (trailing empty lines)
	ERR_MAP_OPEN,		map not closed/surrounded by walls
	ERR_PARSE			generic parse error (e.g. unexpected line format)
*/
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
	ERR_SPR_CONF_MISS,
	ERR_CONF_PATH,
	ERR_CONF_COLOR,
	ERR_MAP_EMPTY,
	ERR_MAP_CHAR,
	ERR_MAP_DOOR,
	ERR_MAP_PLAYER,
	ERR_MAP_GAP,
	ERR_MAP_TRAIL,
	ERR_MAP_OPEN,
	ERR_PARSE
}	t_err;

int				print_msg(const char *str, const char *detail, int exit_no);
int				print_errno(t_err err);
const char		*msg_for_err(t_err err);

#endif