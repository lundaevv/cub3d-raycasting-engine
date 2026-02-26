/*
should be the only header most .c files include,
unless a module is intentionally isolated.
*/

/*
enum texture id
*/

#ifndef MAIN_H
#define MAIN_H
/* Allowed functions: */
#include <errno.h>    /* errno for perror/strerror */
#include <fcntl.h>    /* open, O_* flags */
#include <math.h>     /* whole math library */
#include <stdio.h>    /* printf */
#include <stdlib.h>   /* malloc, free, exit */
#include <string.h>   /* strerror */
#include <sys/time.h> /* gettimeofday */
#include <unistd.h>   /* read, write, close */

#include "../mlx/mlx.h"

#include "../libft/includes/libft.h"
#include "config.h"
#include "errors.h"
#include "parser.h"
#include "render.h"
#include "types.h"
#include "utils.h"

#endif
