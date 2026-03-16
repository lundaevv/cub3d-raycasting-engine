/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:43 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/16 15:47:09 by vlundaev         ###   ########.fr       */
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

void	validate_arg(t_game *game_dt, t_err *error, char **argv)
{
	if (!has_cube_extension(argv[1]))
		*error = ERR_EXT;
	game_dt->map_path = argv[1];	
}
