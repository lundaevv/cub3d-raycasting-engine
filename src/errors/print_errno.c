/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errno.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:52 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/05 13:53:18 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <stddef.h>

const char	*msg_for_err(t_err err)
{
	static const char	*msgs[] = {NULL, ERRMSG_ARGS, ERRMSG_EXT, ERRMSG_OPEN,
		ERRMSG_READ, ERRMSG_MEM, ERRMSG_CONF_DUP, ERRMSG_CONF_MISS,
		ERRMSG_DOOR_CONF_MISS, ERRMSG_SPR_CONF_MISS, ERRMSG_CONF_PATH,
		ERRMSG_CONF_COLOR, ERRMSG_MAP_EMPTY, ERRMSG_MAP_CHAR, ERRMSG_MAP_DOOR,
		ERRMSG_MAP_PLAYER, ERRMSG_MAP_GAP, ERRMSG_MAP_TRAIL, ERRMSG_MAP_OPEN,
		ERRMSG_PARSE, ERRMSG_MLX_INIT};

	if (err <= 0 || err >= (t_err)(sizeof(msgs) / sizeof(msgs[0])))
		return ("unknown error");
	return (msgs[err]);
}

int	print_errno(t_err err)
{
	if (err == ERR_OK)
		return (0);
	return (print_msg(ERR_FMT, msg_for_err(err), err));
}
