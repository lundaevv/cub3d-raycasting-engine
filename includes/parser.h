/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:47 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/18 12:18:15 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "config.h"
# include "errors.h"
# include "libft.h"
# include "types.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/* PUBLIC PARSER INTERFACE */
/* parse.c */
void	parse(t_game *game_dt, t_err *error);

/* INTERNAL PARSER FUNCTIONS */
/* parse_file.c - parse_config.c - parse_map.c */
char	**read_map_file_lines(t_game *game_dt, t_err *error);
void	parse_graphics_config_block(char **lines, t_game *game_dt,
			t_err *error);
void	parse_map_block(char **lines, t_game *game_dt, t_err *error);

/* parse_config_utils.c */
int		get_config_id(char *line);
char	*get_config_value(char *line);

/* parse_config_store.c */
int		store_config_value(char *line, int id, t_game *game_dt, t_err *error);

/* parse_config_color.c */
int		parse_rgb_color(char *value, int *out_color);

/* parse_utils.c */
void	free_lines(char **lines);
bool	is_empty_line(char *line);
int		skip_empty_lines(char **lines);
char	*dup_trimmed_str(char *str);
void	free_strs(char **strs);

/* parse_map_find_block.c */
int		find_map_start_line(char **lines);
int		validate_map_block_start(int start, t_err *error);
int		count_map_block_rows(char **lines, int start);

/* parse_map_utils.c*/
int		get_max_map_width(char **grid);
int		validate_map_chars(char **grid);
int		count_players(char **grid);
bool	is_map_line(char *line);

/* parse_map_validate.c */
int		validate_loaded_map(t_game *game_dt, t_err *error);

/* parse_map_boundary.c */
void	validate_map_terminator(char **lines, int i, t_err *error);

/* parse_player.c */
int		extract_player_entity(t_game *game_dt);

/* parse_map_normalize.c */
int		normalize_map(t_game *game_dt);

/* parse_map_closed.c */
bool	is_map_closed(t_map *map);

/* parse_door.c */
int		validate_doors(t_map *map);
int		count_doors(t_map *map);

/* parse_tile.c */
bool	is_wall(char c);
bool	is_walkable_tile(char c);
bool	is_map_char(char c);
bool	is_player_char(char c);

#endif
