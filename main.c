#include "main.h"
/*
init → parse → render → destroy (called with errno)

init() should set up shared state (mlx, textures, config).
parse() should fill a shared t_game/t_config.
render() should only use that state.
destroy() should free everything, even if parse failed.
*
*/
int main(int argc, char **argv) {
  t_game game_dt;
  int error;

  init(&game_dt, &errno);
  if (!errno) {
    parse(&errno);
    if (!errno)
      render(&errno);
  }
  destroy();
  return (print_errno(&errno));
}
