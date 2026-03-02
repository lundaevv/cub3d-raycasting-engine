/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:32:47 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/02 19:23:22 by vlundaev         ###   ########.fr       */
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

/* parse_config_utils.c */
int		get_config_id(char *line);
char	*get_config_value(char *line);

/* parse_store.c */
int		store_config_value(char *line, int id, t_game *game_dt, t_err *error);

/* parse_utils.c */
void	free_lines(char **lines);
int		is_empty_line(char *line);
int		skip_empty_lines(char **lines);
char	*dup_trimmed_str(char *str);

#endif
