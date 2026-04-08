/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_platform_compat_linux.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:33:00 by vlundaev          #+#    #+#             */
/*   Updated: 2026/04/08 19:33:00 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_compat.h"
#include <stdlib.h>

#ifndef __APPLE__

void	mlx_get_screen_size_safe(void *context, int *sw, int *sh)
{
	mlx_get_screen_size(context, sw, sh);
}

void	mlx_destroy_context_safe(void *context)
{
	mlx_destroy_display(context);
	free(context);
}

void	exit_platform(int code)
{
	exit(code);
}

#endif
