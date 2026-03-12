/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:35:57 by akuchmam          #+#    #+#             */
/*   Updated: 2026/03/11 15:13:35 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdint.h>

void	putp(t_img *im, int x, int y, uint32_t c)
{
	if (!im || !im->a || x < 0 || y < 0 || x >= im->w || y >= im->h)
		return ;
	*(unsigned int *)(im->a + (y * im->ll + x * (im->bpp / 8))) = c;
}

unsigned int	getp(t_img *im, int x, int y)
{
	if (!im || !im->a || x < 0 || y < 0 || x >= im->w || y >= im->h)
		return (0);
	return (*(unsigned int *)(im->a + y * im->ll + x * (im->bpp / 8)));
}
