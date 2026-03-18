/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:31:04 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/18 12:26:08 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	is_valid_rgb_value(int n)
{
	return (n >= 0 && n <= 255);
}

static int	count_parts(char **parts)
{
	int	count;

	count = 0;
	while (parts[count])
		count++;
	return (count);
}

static bool	is_strict_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (false);
	while (str[i] && !ft_isspace(str[i]))
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	parse_rgb_values(char **parts, int *r, int *g, int *b)
{
	if (!is_strict_number(parts[0]) || !is_strict_number(parts[1])
		|| !is_strict_number(parts[2]))
		return (0);
	*r = ft_atoi(parts[0]);
	*g = ft_atoi(parts[1]);
	*b = ft_atoi(parts[2]);
	if (!is_valid_rgb_value(*r) || !is_valid_rgb_value(*g)
		|| !is_valid_rgb_value(*b))
		return (0);
	return (1);
}

/*
"r <<  16 | g << 8 | b"	packs RGB values into a single integer

It works as follows:
 - The red component (r) is shifted left by 16 bits,
		which means it occupies the highest byte of the resulting integer.
 - The green component (g) is shifted left by 8 bits,
		which means it occupies the middle byte of the resulting integer.
 - The blue component (b) is not shifted,
		so it occupies the lowest byte of the resulting integer.
*/
int	parse_rgb_color(char *value, int *out_color)
{
	char	**parts;
	int		r;
	int		g;
	int		b;

	parts = ft_split(value, ',');
	if (!parts || count_parts(parts) != 3)
	{
		free_strs(parts);
		return (0);
	}
	if (!parse_rgb_values(parts, &r, &g, &b))
	{
		free_strs(parts);
		return (0);
	}
	*out_color = (r << 16) | (g << 8) | b;
	free_strs(parts);
	return (1);
}
