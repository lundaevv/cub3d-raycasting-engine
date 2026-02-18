#include "../../includes/main.h"

void	init(t_game *game_dt, int *error, int argc, char **argv)
{
	*game_dt = (t_game){0};
	*error = ERR_OK;
	validate_args(error, argc, argv);
	if (*error == ERR_OK)
		game_dt->map_path = argv[1];
}
