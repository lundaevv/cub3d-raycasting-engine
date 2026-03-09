/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:56:05 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/05 12:21:30 by vlundaev         ###   ########.fr       */
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
	if (!ft_strncmp(&line[i], "DC", 2) && ft_isspace(line[i + 2]))
		return (4);
	if (!ft_strncmp(&line[i], "DO", 2) && ft_isspace(line[i + 2]))
		return (5);
	if (!ft_strncmp(&line[i], "SP", 2) && ft_isspace(line[i + 2]))
		return (6);
	if (line[i] == 'F' && ft_isspace(line[i + 1]))
		return (7);
	if (line[i] == 'C' && ft_isspace(line[i + 1]))
		return (8);
	return (-1);
}

char	*get_config_value(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == 'F' || line[i] == 'C')
		i++;
	else
		i += 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i] || line[i] == '\n')
		return (NULL);
	return (&line[i]);
}
