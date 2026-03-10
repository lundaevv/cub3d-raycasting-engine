/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_sec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:11 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/10 12:02:14 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double get_time_sec(void) {
  struct timeval tv;

  gettimeofday(&tv, NULL);
  return ((double)tv.tv_sec + (double)tv.tv_usec / 1e6);
}
