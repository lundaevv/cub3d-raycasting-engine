/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 10:35:57 by akuchmam          #+#    #+#             */
/*   Updated: 2025-08-25 10:35:57 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdint.h>

void putp(t_img *im, int x, int y, uint32_t c) {
  if (!im || !im->a || x < 0 || y < 0 || x >= im->w || y >= im->h)
    return;
  *(unsigned int *)(im->a + (y * im->ll + x * (im->bpp / 8))) = c;
}

unsigned int getp(t_img *im, int x, int y) {
  if (!im || !im->a || x < 0 || y < 0 || x >= im->w || y >= im->h)
    return (0);
  return (*(unsigned int *)(im->a + y * im->ll + x * (im->bpp / 8)));
}

void blit_copy(t_img *dst, t_img *src, int dx, int dy) {
  int y;
  int yy;
  int x;
  int xx;

  y = 0;
  while (y < src->h) {
    yy = dy + y;
    if (yy < 0 || yy >= dst->h)
      continue;
    x = 0;
    while (x < src->w) {
      xx = dx + x;
      if (xx < 0 || xx >= dst->w)
        continue;
      putp(dst, xx, yy, getp(src, x, y));
      x++;
    }
    y++;
  }
}

void blit_colorkey(t_img *dst, t_img *src, int dx, int dy) {
  const unsigned int key = getp(src, 0, 0);
  unsigned int c;
  int y_x[2];
  int yy_xx[2];

  y_x[0] = 0;
  while (y_x[0] < src->h) {
    yy_xx[0] = dy + y_x[0];
    if (yy_xx[0] < 0 || yy_xx[0] >= dst->h)
      continue;
    y_x[1] = 0;
    while (y_x[1] < src->w) {
      yy_xx[1] = dx + y_x[1];
      if (yy_xx[1] < 0 || yy_xx[1] >= dst->w)
        continue;
      c = getp(src, y_x[1], y_x[0]);
      if (c != key)
        putp(dst, yy_xx[1], yy_xx[0], c);
      y_x[1]++;
    }
    y_x[0]++;
  }
}
