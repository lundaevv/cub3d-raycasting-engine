/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_compat_linux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:33:00 by vlundaev          #+#    #+#             */
/*   Updated: 2026/04/08 19:33:00 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_compat.h"

#ifndef __APPLE__

void	mlx_mouse_hide_safe(void *context, void *win)
{
	mlx_mouse_hide(context, win);
}

void	mlx_mouse_show_safe(void *context, void *win)
{
	mlx_mouse_show(context, win);
}

void	mlx_mouse_move_safe(void *context, void *win, int x, int y)
{
	mlx_mouse_move(context, win, x, y);
}

#endif
