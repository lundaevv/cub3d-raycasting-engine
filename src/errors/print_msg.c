/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:31:49 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/02 13:38:00 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "libft.h"

int	print_msg(const char *str, const char *detail, int exit_no)
{
	if (!detail)
		ft_printf(str, STR_PROG_NAME);
	else
		ft_printf(str, STR_PROG_NAME, detail);
	return (exit_no);
}
