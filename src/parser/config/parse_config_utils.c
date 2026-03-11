/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:56:05 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/11 14:53:23 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_config_id(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!ft_strncmp(&line[i], "NO", 2) && ft_isspace(line[i + 2]))
		return (0);
	if (!ft_strncmp(&line[i], "SO", 2) && ft_isspace(line[i + 2]))
		return (1);
	if (!ft_strncmp(&line[i], "WE", 2) && ft_isspace(line[i + 2]))
		return (2);
	if (!ft_strncmp(&line[i], "EA", 2) && ft_isspace(line[i + 2]))
		return (3);
	if (line[i] == 'D' && ft_isspace(line[i + 1]))
		return (4);
	if (line[i] == 'F' && ft_isspace(line[i + 1]))
		return (5);
	if (line[i] == 'C' && ft_isspace(line[i + 1]))
		return (6);
	return (-1);
}

char	*get_config_value(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == 'F' || line[i] == 'C' || line[i] == 'D')
		i++;
	else
		i += 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i] || line[i] == '\n')
		return (NULL);
	return (&line[i]);
}
