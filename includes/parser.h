/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:47 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/04 19:39:02 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include "config.h"
# include "errors.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* PUBLIC PARSER INTERFACE */
/* parse.c */
void	parse(t_game *game_dt, t_err *error);

/* INTERNAL PARSER FUNCTIONS */
/* parse_file.c - parse_config.c - parse_map.c */
char	**parse_file(t_game *game_dt, t_err *error);
void	parse_config(char **lines, t_game *game_dt, t_err *error);
void	parse_map(char **lines, t_game *game_dt, t_err *error);

/* parse_config_utils.c */
int		get_config_id(char *line);
char	*get_config_value(char *line);

/* parse_config_store.c */
int		store_config_value(char *line, int id, t_game *game_dt, t_err *error);

/* parse_color.c */
int		parse_rgb_color(char *value, int *out_color);

/* parse_utils.c */
void	free_lines(char **lines);
int		is_empty_line(char *line);
int		skip_empty_lines(char **lines);
char	*dup_trimmed_str(char *str);
void	free_strs(char **strs);

/* parse_map_utils.c*/
int		get_max_map_width(char **grid);
int		validate_map_chars(char **grid);
int		count_players(char **grid);
int		is_map_line(char *line);

/* parse_map_validate.c */
int		validate_loaded_map(t_game *game_dt, t_err *error);

/* parse_map_tail.c */
int		count_map_lines(char **lines, int start, t_err *error);

/* parse_player.c */
int		extract_player(t_game *game_dt);

/* parse_map_normalize.c */
int		normalize_map(t_game *game_dt);

/* parse_map_closed.c */
int		is_map_closed(t_map *map);

/* parse_door.c */
int		validate_doors(t_map *map);
int		count_doors(t_map *map);

/* parse_tile.c */
int		is_wall(char c);
int		is_walkable_tile(char c);
int		is_map_char(char c);
int		is_player_char(char c);

/* parse_sprite.c */
int		count_sprites(t_map *map);

#endif
