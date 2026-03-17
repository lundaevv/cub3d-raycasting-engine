#include "render.h"
#include "utils.h"

static void draw_block(t_img *img, int x, int y, t_txt_dt *txt_dt) {
  int dx;
  int dy;

  dy = 0;
  while (dy < txt_dt->scale) {
    dx = 0;
    while (dx < txt_dt->scale) {
      putp(img, x + dx, y + dy, txt_dt->color);
      dx++;
    }
    dy++;
  }
}

static const t_glyph *get_glyph(char c, t_txt_dt *txt_dt) {
  int i;
  int fallback;

  if (c >= 'a' && c <= 'z')
    c -= 32;
  i = 0;
  fallback = -1;
  while (txt_dt->g_font[i].c) {
    if (txt_dt->g_font[i].c == '?')
      fallback = i;
    if (txt_dt->g_font[i].c == c)
      return (&txt_dt->g_font[i]);
    i++;
  }
  if (fallback >= 0)
    return (&txt_dt->g_font[fallback]);
  return (0);
}

void draw_char(t_img *img, char c, t_txt_dt *txt_dt) {
  const t_glyph *g;
  int row;
  int col;

  if (!img || txt_dt->scale <= 0)
    return;
  g = get_glyph(c, txt_dt);
  if (!g)
    return;
  row = 0;
  while (row < 7) {
    col = 0;
    while (col < 5) {
      if ((g->rows[row] >> (4 - col)) & 1)
        draw_block(img, txt_dt->x + (col * txt_dt->scale),
                   txt_dt->y + (row * txt_dt->scale), txt_dt);
      col++;
    }
    row++;
  }
}
