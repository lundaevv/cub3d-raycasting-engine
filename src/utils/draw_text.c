#include "utils.h"

int text_width(const char *str, int scale) {
  int line_w;
  int max_w;

  if (!str || scale <= 0)
    return (0);
  line_w = 0;
  max_w = 0;
  while (*str) {
    if (*str == '\n') {
      if (line_w > max_w)
        max_w = line_w;
      line_w = 0;
    } else if (*str == '\t')
      line_w += 4 * 6 * scale;
    else
      line_w += 6 * scale;
    str++;
  }
  if (line_w > max_w)
    max_w = line_w;
  return (max_w);
}

int text_height(const char *str, int scale) {
  int lines;

  if (!str || scale <= 0)
    return (0);
  lines = 1;
  while (*str) {
    if (*str == '\n')
      lines++;
    str++;
  }
  return (lines * 8 * scale - scale);
}

void draw_text(t_img *img, const char *str, t_txt_dt txt_dt) {
  int start_x;

  if (!img || !str || txt_dt.scale <= 0)
    return;
  start_x = txt_dt.x;
  while (*str) {
    if (*str == '\n') {
      txt_dt.y += 8 * txt_dt.scale;
      txt_dt.x = start_x;
    } else if (*str == '\t')
      txt_dt.x += 4 * 6 * txt_dt.scale;
    else {
      draw_char(img, *str, &txt_dt);
      txt_dt.y += 6 * txt_dt.scale;
    }
    str++;
  }
}

void draw_text_centered(t_img *img, const char *str, t_txt_dt txt_dt) {
  const int w = text_width(str, txt_dt.scale);
  const t_txt_dt clone = (t_txt_dt){txt_dt.g_font, txt_dt.x - (w / 2), txt_dt.y,
                                    txt_dt.scale, txt_dt.color};

  draw_text(img, str, clone);
}
