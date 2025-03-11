/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:06:15 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/11 14:22:06 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	exit_game(t_game *game)
{
	if (game->map.collectibles == 0)
	{
		ft_printf("You win!\n");
		ft_free_all_memory(game);
		exit(0);
	}
}

static void	move_top(t_game *game)
{
	t_position	current;
	t_position	next;

	current.y = game->player.position.y;
	current.x = game->player.position.x;
	next.y = game->player.position.y - 1;
	next.x = game->player.position.x;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] != EXIT)
		{
			move_floor(game, &current, &next);
		}
		else
		{
			move_exit(game, &current, &next);
		}
	}
}

static void	move_left(t_game *game)
{
	t_position	current;
	t_position	next;

	current.y = game->player.position.y;
	current.x = game->player.position.x;
	next.y = game->player.position.y;
	next.x = game->player.position.x - 1;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] != EXIT)
		{
			move_floor(game, &current, &next);
		}
		else
		{
			move_exit(game, &current, &next);
		}
	}
}

static void	move_right(t_game *game)
{
	t_position	current;
	t_position	next;

	current.y = game->player.position.y;
	current.x = game->player.position.x;
	next.y = game->player.position.y;
	next.x = game->player.position.x + 1;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] != EXIT)
		{
			move_floor(game, &current, &next);
		}
		else
		{
			move_exit(game, &current, &next);
		}
	}
}

static void	move_bottom(t_game *game)
{
	t_position	current;
	t_position	next;

	current.y = game->player.position.y;
	current.x = game->player.position.x;
	next.y = game->player.position.y + 1;
	next.x = game->player.position.x;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] != EXIT)
		{
			move_floor(game, &current, &next);
		}
		else
		{
			move_exit(game, &current, &next);
		}
	}
}

void	move_floor(t_game *game, t_position *current, t_position *next)
{
	if (game->map.full[next->y][next->x] == COLLECTIBLE)
		game->map.collectibles--;
	game->player.position.y = next->y;
	game->player.position.x = next->x;
	if (current->x == game->exit.position.x && current->y == game->exit.position.y)
		game->map.full[current->y][current->x] = EXIT;
	else
		game->map.full[current->y][current->x] = FLOOR;
	game->map.full[next->y][next->x] = PLAYER;
	game->moves++;
	ft_printf("moves: %d\n", game->moves);
}

void	move_exit(t_game *game, t_position *current, t_position *next)
{
	if (game->map.collectibles != 0)
	{
		game->player.position.y = next->y;
		game->player.position.x = next->x;
		game->map.full[current->y][current->x] = FLOOR;
		game->map.full[next->y][next->x] = PLAYER;
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
	else
		exit_game(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		move_top(game);
	else if (keycode == S)
		move_bottom(game);
	else if (keycode == A)
		move_left(game);
	else if (keycode == D)
		move_right(game);
	else if (keycode == ESC)
	{
		ft_free_all_memory(game);
		exit(0);
	}
	return (0);
}
