/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:44 by vlundaev          #+#    #+#             */
/*   Updated: 2026/02/25 15:48:51 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "types.h"

int				render(t_game *game_dt, int *error);
int				pre_render(t_game game_dt);
int				draw_minimap(int **map, t_vec player_pos);
int				draw_map(int **map, t_vec player_pos, t_img *textures_arr);

int				show_menu_ui(void);
int				show_ingame_ui(void);

// Uttility functions for drawing pixels and blitting images
void			putp(t_img *im, int x, int y, unsigned int c);
unsigned int	getp(t_img *im, int x, int y);
void			blit_copy(t_img *dst, t_img *src, int dx, int dy);
void			blit_colorkey(t_img *dst, t_img *src, int dx, int dy);

#endif
