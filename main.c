#include "./includes/main.h"

/*
init → parse → render → destroy (called with errno)

init() should set up shared state (mlx, textures, config).
parse() should fill a shared t_game/t_config.
render() should only use that state.
destroy() should free everything, even if parse failed.
*/ 
int	main(int argc, char **argv)
{
	t_game	game_dt;
	int	error;

	error = 0;
	init(&game_dt, &error, argc, argv);
	if (!error)
	{
		parse(&error);
		if (!error)
			render(&error);
	}
	destroy();
	return (print_errno(&error));
}
