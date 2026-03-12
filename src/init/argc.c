/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:43 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 15:11:47 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static bool	has_cube_extension(const char *filename)
{
	size_t	len;
	int		diff;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	diff = ft_strncmp(filename + len - 4, ".cub", 4);
	if (!diff)
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
