#include "../../includes/parser_internal.h"

char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	set_path(char **dst, const char *str, t_err *error)
{
	char	*tmp;

	if (*dst)
	{
		*error = ERR_CONF_DUP;
		return (0);
	}
	tmp = ft_strtrim(str, " \t");
	if (!tmp)
	{
		*error = ERR_MEM;
		return (0);
	}
	if (tmp[0] == '\0')
	{
		free(tmp);
		*error = ERR_PARSE;
		return (0);
	}
	*dst = tmp;
	return (1);
}

static int	parse_rgb_value(const char *str, int *index, int *value)
{
	while (str[*index] == ' ' || str[*index] == '\t')
		(*index)++;
	if (!ft_isdigit(str[*index]))
		return (0);
	*value = 0;
	while (ft_isdigit(str[*index]))
		*value = (*value * 10) + (str[(*index)++] - '0');
	if (*value > 255)
		return (0);
	while (str[*index] == ' ' || str[*index] == '\t')
		(*index)++;
	return (1);
}

static int	consume_comma(const char *str, int *index)
{
	if (str[*index] != ',')
		return (0);
	(*index)++;
	return (1);
}

int	parse_rgb(const char *str, int *out)
{
	int	rgb[3];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 3)
	{
		if (!parse_rgb_value(str, &i, &rgb[j]))
			return (0);
		if (j < 2 && !consume_comma(str, &i))
			return (0);
		j++;
	}
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0')
		return (0);
	*out = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (1);
}
