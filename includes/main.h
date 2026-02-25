/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:50 by vlundaev          #+#    #+#             */
/*   Updated: 2026/02/25 17:22:58 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

/* Allowed functions: */
# include <errno.h>    /* errno for perror/strerror */
# include <fcntl.h>    /* open, O_* flags */
# include <math.h>     /* whole math library */
# include <stdio.h>    /* printf */
# include <stdlib.h>   /* malloc, free, exit */
# include <string.h>   /* strerror */
# include <sys/time.h> /* gettimeofday */
# include <unistd.h>   /* read, write, close */

//#include "../mlx/includes/mlx.h"
# include "../libft/includes/libft.h"
# include "types.h"
# include "config.h"
# include "errors.h"
# include "utils.h"
# include "parser.h"
# include "render.h"

#endif
