/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:06:15 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/12 11:29:33 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_top(t_game *game, t_position *current)
{
	t_position	next;

	next.y = game->player.position.y - 1;
	next.x = game->player.position.x;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] != EXIT)
			move_to_floor(game, current, &next);
		else
			move_to_exit(game, current, &next);
	}
}

static void	move_left(t_game *game, t_position *current)
{
	t_position	next;

	next.y = game->player.position.y;
	next.x = game->player.position.x - 1;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] != EXIT)
			move_to_floor(game, current, &next);
		else
			move_to_exit(game, current, &next);
	}
}

static void	move_right(t_game *game, t_position *current)
{
	t_position	next;

	next.y = game->player.position.y;
	next.x = game->player.position.x + 1;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] != EXIT)
			move_to_floor(game, current, &next);
		else
			move_to_exit(game, current, &next);
	}
}

static void	move_bottom(t_game *game, t_position *current)
{
	t_position	next;

	next.y = game->player.position.y + 1;
	next.x = game->player.position.x;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] != EXIT)
			move_to_floor(game, current, &next);
		else
			move_to_exit(game, current, &next);
	}
}

int	key_press(int keycode, t_game *game)
{
	t_position	current;

	current.y = game->player.position.y;
	current.x = game->player.position.x;
	if (keycode == W)
		move_top(game, &current);
	else if (keycode == S)
		move_bottom(game, &current);
	else if (keycode == A)
		move_left(game, &current);
	else if (keycode == D)
		move_right(game, &current);
	else if (keycode == ESC)
		close_window(game);
	return (0);
}
