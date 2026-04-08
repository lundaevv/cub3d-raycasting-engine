/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_compat_apple.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:33:00 by vlundaev          #+#    #+#             */
/*   Updated: 2026/04/08 19:33:00 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_compat.h"

#ifdef __APPLE__

void	mlx_mouse_hide_safe(void *context, void *win)
{
	(void)context;
	(void)win;
	mlx_mouse_hide();
}

void	mlx_mouse_show_safe(void *context, void *win)
{
	(void)context;
	(void)win;
	mlx_mouse_show();
}

void	mlx_mouse_move_safe(void *context, void *win, int x, int y)
{
	(void)context;
	mlx_mouse_move(win, x, y);
}

#endif
