/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:06:15 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/08 14:03:12 by abouclie         ###   ########.fr       */
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
	int	pos_x;
	int	pos_y;

	pos_x = game->player.position.x;
	pos_y = game->player.position.y;
	if (game->map.full[pos_y - 1][pos_x] != WALL)
	{
		if (game->map.full[pos_y - 1][pos_x] != EXIT)
		{
			if (game->map.full[pos_y - 1][pos_x] == COLLECTIBLE)
				game->map.collectibles--;
			game->player.position.y--;
			if (pos_x == game->exit.position.x && pos_y == game->exit.position.y)
				game->map.full[pos_y][pos_x] = EXIT;
			else
				game->map.full[pos_y][pos_x] = FLOOR;
			game->map.full[pos_y - 1][pos_x] = PLAYER;
			game->moves++;
			ft_printf("moves: %d\n", game->moves);
		}
		else
		{
			if (game->map.collectibles != 0)
			{
				game->player.position.y--;
				game->map.full[pos_y][pos_x] = FLOOR;
				game->map.full[pos_y - 1][pos_x] = PLAYER;
				game->moves++;
				ft_printf("moves: %d\n", game->moves);
			}
			else
				exit_game(game);
		}
	}
}

static void	move_left(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player.position.x;
	pos_y = game->player.position.y;
	if (game->map.full[pos_y][pos_x - 1] != WALL)
	{
		if (game->map.full[pos_y][pos_x - 1] != EXIT)
		{
			if (game->map.full[pos_y][pos_x - 1] == COLLECTIBLE)
				game->map.collectibles--;
			game->player.position.x--;
			if (pos_x == game->exit.position.x && pos_y == game->exit.position.y)
				game->map.full[pos_y][pos_x] = EXIT;
			else
				game->map.full[pos_y][pos_x] = FLOOR;
			game->map.full[pos_y][pos_x - 1] = PLAYER;
			game->moves++;
			ft_printf("moves: %d\n", game->moves);
		}
		else
		{
			if (game->map.collectibles != 0)
			{
				game->player.position.x--;
				game->map.full[pos_y][pos_x] = FLOOR;
				game->map.full[pos_y][pos_x - 1] = PLAYER;
				game->moves++;
				ft_printf("moves: %d\n", game->moves);
			}
			else
				exit_game(game);
		}
	}
}

static void	move_right(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player.position.x;
	pos_y = game->player.position.y;
	if (game->map.full[pos_y][pos_x + 1] != WALL)
	{
		if (game->map.full[pos_y][pos_x + 1] != EXIT)
		{
			if (game->map.full[pos_y][pos_x + 1] == COLLECTIBLE)
				game->map.collectibles--;
			game->player.position.x++;
			if (pos_x == game->exit.position.x && pos_y == game->exit.position.y)
				game->map.full[pos_y][pos_x] = EXIT;
			else
				game->map.full[pos_y][pos_x] = FLOOR;
			game->map.full[pos_y][pos_x + 1] = PLAYER;
			game->moves++;
			ft_printf("moves: %d\n", game->moves);
		}
		else
		{
			if (game->map.collectibles != 0)
			{
				game->player.position.x++;
				game->map.full[pos_y][pos_x] = FLOOR;
				game->map.full[pos_y][pos_x + 1] = PLAYER;
				game->moves++;
				ft_printf("moves: %d\n", game->moves);
			}
			else
				exit_game(game);
		}
	}
}

static void	move_bottom(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player.position.x;
	pos_y = game->player.position.y;
	if (game->map.full[pos_y + 1][pos_x] != WALL)
	{
		if (game->map.full[pos_y + 1][pos_x] != EXIT)
		{
			if (game->map.full[pos_y + 1][pos_x] == COLLECTIBLE)
				game->map.collectibles--;
			game->player.position.y++;
			if (pos_x == game->exit.position.x && pos_y == game->exit.position.y)
				game->map.full[pos_y][pos_x] = EXIT;
			else
				game->map.full[pos_y][pos_x] = FLOOR;
			game->map.full[pos_y + 1][pos_x] = PLAYER;
			game->moves++;
			ft_printf("moves: %d\n", game->moves);
		}
		else
		{
			if (game->map.collectibles != 0)
			{
				game->player.position.y++;
				game->map.full[pos_y][pos_x] = FLOOR;
				game->map.full[pos_y + 1][pos_x] = PLAYER;
				game->moves++;
				ft_printf("moves: %d\n", game->moves);
			}
			else
				exit_game(game);
		}
	}
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
