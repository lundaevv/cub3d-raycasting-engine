/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:47 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/03 19:12:52 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include "errors.h"
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include <stdlib.h>

void	parse(t_game *game_dt, t_err *error);

/* INTERNAL PARSER FUNCTIONS */

char	**parse_file(t_game *game_dt, t_err *error);
void	parse_config(char **lines, t_game *game_dt, t_err *error);
void	parse_map(char **lines, t_game *game_dt, t_err *error);

/* parse_config_utils.c */
int		get_config_id(char *line);
char	*get_config_value(char *line);

/* parse_store.c */
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
int		is_map_char(char c);
int		validate_map_chars(char **grid);
int		is_player_char(char c);
int		count_players(char **grid);

/* parse_map_validate.c */
int		validate_loaded_map(t_game *game_dt, t_err *error);

/* parse_player.c */
int		extract_player(t_game *game_dt);

/* parse_map_normalize.c */
int		normalize_map(t_game *game_dt);

/* parse_map_closed.c */
int		is_map_closed(t_map *map);

#endif
