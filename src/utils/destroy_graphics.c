/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:09:57 by vlundaev          #+#    #+#             */
/*   Updated: 2026/04/08 17:25:02 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "parser.h"
#include "utils.h"

static void	destroy_frame(t_game *g)
{
	if (g->mlx.frame.img)
	{
		mlx_destroy_image(g->mlx.context, g->mlx.frame.img);
		g->mlx.frame.img = NULL;
		g->mlx.frame.a = NULL;
	}
	if (g->mlx.minimap.img)
	{
		mlx_destroy_image(g->mlx.context, g->mlx.minimap.img);
		g->mlx.minimap.img = NULL;
		g->mlx.minimap.a = NULL;
	}
}

static void	destroy_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (g->graphics.tex[i].img)
		{
			mlx_destroy_image(g->mlx.context, g->graphics.tex[i].img);
			g->graphics.tex[i].img = NULL;
			g->graphics.tex[i].a = NULL;
		}
		i++;
	}
}

static void	destroy_window_and_display(t_game *g)
{
	if (g->mlx.win)
	{
		mlx_destroy_window(g->mlx.context, g->mlx.win);
		g->mlx.win = NULL;
	}
	mlx_destroy_context_safe(g->mlx.context);
	g->mlx.context = NULL;
}

void	free_graphics_data(t_game *g)
{
	if (!g->mlx.context)
		return ;
	destroy_frame(g);
	destroy_textures(g);
	destroy_window_and_display(g);
}
