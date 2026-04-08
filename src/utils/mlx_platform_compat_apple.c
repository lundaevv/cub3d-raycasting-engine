/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_platform_compat_apple.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:33:00 by vlundaev          #+#    #+#             */
/*   Updated: 2026/04/08 19:33:00 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_compat.h"
#include <unistd.h>

#ifdef __APPLE__

void	mlx_get_screen_size_safe(void *context, int *sw, int *sh)
{
	(void)context;
	*sw = 1280;
	*sh = 720;
}

void	mlx_destroy_context_safe(void *context)
{
	(void)context;
}

void	exit_platform(int code)
{
	_exit(code);
}

#endif
