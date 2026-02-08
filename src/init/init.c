#include "./includes/main.h"

static int	has_cub_extension(const char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}

void	init(t_game *game_dt, int *error, int argc, char **argv)
{
	*game_dt = (t_game){0};
	*error = 0;

	if (arg)
}
