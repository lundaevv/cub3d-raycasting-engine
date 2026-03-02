/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:02:30 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/02 21:07:30 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

int	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	skip_empty_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] && is_empty_line(lines[i]))
		i++;
	return (i);
}

char	*dup_trimmed_str(char *str)
{
	if (!str)
		return (NULL);
	return (ft_strtrim(str, " \t\n\r\v\f"));
}

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
