/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:43 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/02 13:37:49 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	has_cube_extension(const char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}

void	validate_args(t_err *error, int argc, char **argv)
{
	if (argc != 2)
	{
		*error = ERR_ARGS;
		return ;
	}
	if (!has_cube_extension(argv[1]))
		*error = ERR_EXT;
}
