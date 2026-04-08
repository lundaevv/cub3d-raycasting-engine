/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_compat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:10:00 by vlundaev          #+#    #+#             */
/*   Updated: 2026/04/08 19:10:00 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COMPAT_H
# define MLX_COMPAT_H

# include "../mlx/mlx.h"

# ifdef __APPLE__
#  define MLX_USE_MINIMAP_OVERLAY 1
# else
#  define MLX_USE_MINIMAP_OVERLAY 0
# endif

void	mlx_mouse_hide_safe(void *context, void *win);
void	mlx_mouse_show_safe(void *context, void *win);
void	mlx_mouse_move_safe(void *context, void *win, int x, int y);
void	mlx_get_screen_size_safe(void *context, int *sw, int *sh);
void	mlx_destroy_context_safe(void *context);
void	exit_platform(int code);

#endif
