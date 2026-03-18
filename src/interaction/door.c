/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:20:16 by vlundaev          #+#    #+#             */
/*   Updated: 2026/03/17 14:21:38 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interaction.h"

static int	new_door(t_door_list *door_li, t_vec_int map_pos)
{
	t_door	*new_door;

	new_door = malloc(sizeof(t_door));
	if (!new_door)
		return (ERR_MEM);
	new_door->map_pos = (t_vec_int){map_pos.x, map_pos.y};
	new_door->next = NULL;
	if (door_li->head == NULL)
	{
		door_li->head = new_door;
		door_li->tail = new_door;
		return (ERR_OK);
	}
	door_li->tail->next = new_door;
	door_li->tail = new_door;
	return (ERR_OK);
}

static int	is_in_list(t_door_list *door_li, t_vec_int map_pos)
{
	t_door	*cur;

	cur = door_li->head;
	while (cur)
	{
		if (cur->map_pos.x == map_pos.x && cur->map_pos.y == map_pos.y)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	check_door_in_range(t_game *game_dt)
{
	const double	cos_val = cos(game_dt->player.angle);
	const double	sin_val = sin(game_dt->player.angle);
	const t_vec_int	door_pos = (t_vec_int){(game_dt->player.pos.x + cos_val
			* floor(TILE_SIZE * 1.1)) / TILE_SIZE, (game_dt->player.pos.y
			+ sin_val * floor(TILE_SIZE * 1.1)) / TILE_SIZE};
	const t_vec_int	p_pos = (t_vec_int){game_dt->player.pos.x / TILE_SIZE,
		game_dt->player.pos.y / TILE_SIZE};

	game_dt->door_li.is_inside = 0;
	game_dt->door_li.is_in_range = 0;
	if (door_pos.x < 0 || door_pos.y < 0)
		return ;
	if (game_dt->map.grid[door_pos.y][door_pos.x] != 'D'
		&& !is_in_list(&game_dt->door_li, door_pos))
		return ;
	if (!is_in_list(&game_dt->door_li, door_pos))
		new_door(&game_dt->door_li, door_pos);
	if (door_pos.x == p_pos.x && door_pos.y == p_pos.y)
		game_dt->door_li.is_inside = 1;
	game_dt->door_li.is_in_range = 1;
}

void	interact_door(t_game *game_dt)
{
	static double	prev_time;
	const double	cos_val = cos(game_dt->player.angle);
	const double	sin_val = sin(game_dt->player.angle);
	const t_vec_int	door_pos = (t_vec_int){(game_dt->player.pos.x + cos_val
			* floor(TILE_SIZE * 1.1)) / TILE_SIZE, (game_dt->player.pos.y
			+ sin_val * floor(TILE_SIZE * 1.1)) / TILE_SIZE};

	if (game_dt->door_li.is_inside)
		return ;
	if (!game_dt->inp.e || !game_dt->door_li.is_in_range)
		return ;
	if (game_dt->mlx.time - prev_time < 0.15)
		return ;
	prev_time = game_dt->mlx.time;
	if (game_dt->map.grid[door_pos.y][door_pos.x] == 'D')
	{
		game_dt->map.grid[door_pos.y][door_pos.x] = '0';
	}
	else
		game_dt->map.grid[door_pos.y][door_pos.x] = 'D';
}
