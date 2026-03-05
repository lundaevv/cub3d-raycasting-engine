/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:43 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/05 14:26:18 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

static bool	has_cube_extension(const char *filename)
{
	size_t	len;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	if (ft_strncmp(filename + len - 4, ".cub", 4) == 0)
		return (true);
	return (false);
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
