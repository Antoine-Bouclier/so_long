/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:06:15 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/07 14:16:51 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_top(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player_img.position.x;
	pos_y = game->player_img.position.y;
	if (game->map.full[pos_y - 1][pos_x] != WALL)
	{
		if (game->map.full[pos_y - 1][pos_x] != EXIT)
		{
			if (game->map.full[pos_y - 1][pos_x] == COLLECTIBLE)
				game->map.collectibles--;
			game->player_img.position.y--;
			game->map.full[pos_y][pos_x] = FLOOR;
			game->map.full[pos_y - 1][pos_x] = PLAYER;
			game->moves++;
			ft_printf("moves: %d\n", game->moves);
		}
		else
		{
			if (game->map.collectibles == 0)
			{
				ft_printf("Well done!\n");
				exit(0);
			}
		}
	}
}

static void	move_left(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player_img.position.x;
	pos_y = game->player_img.position.y;
	if (game->map.full[pos_y][pos_x - 1] != WALL)
	{
		if (game->map.full[pos_y][pos_x - 1] != EXIT)
		{
			if (game->map.full[pos_y][pos_x - 1] == COLLECTIBLE)
				game->map.collectibles--;
			game->player_img.position.x--;
			game->map.full[pos_y][pos_x] = FLOOR;
			game->map.full[pos_y][pos_x - 1] = PLAYER;
			game->moves++;
			ft_printf("moves: %d\n", game->moves);
		}
		else
		{
			if (game->map.collectibles == 0)
			{
				ft_printf("Well done!\n");
				exit(0);
			}
		}
	}
}

static void	move_right(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player_img.position.x;
	pos_y = game->player_img.position.y;
	if (game->map.full[pos_y][pos_x + 1] != WALL)
	{
		if (game->map.full[pos_y][pos_x + 1] != EXIT)
		{
			if (game->map.full[pos_y][pos_x + 1] == COLLECTIBLE)
				game->map.collectibles--;
			game->player_img.position.x++;
			game->map.full[pos_y][pos_x] = FLOOR;
			game->map.full[pos_y][pos_x + 1] = PLAYER;
			game->moves++;
			ft_printf("moves: %d\n", game->moves);
		}
		else
		{
			if (game->map.collectibles == 0)
			{
				ft_printf("Well done!\n");
				exit(0);
			}
		}
	}
}

static void	move_bottom(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player_img.position.x;
	pos_y = game->player_img.position.y;
	if (game->map.full[pos_y + 1][pos_x] != WALL)
	{
		if (game->map.full[pos_y + 1][pos_x] != EXIT)
		{
			if (game->map.full[pos_y + 1][pos_x] == COLLECTIBLE)
				game->map.collectibles--;
			game->player_img.position.y++;
			game->map.full[pos_y][pos_x] = FLOOR;
			game->map.full[pos_y + 1][pos_x] = PLAYER;
			game->moves++;
			ft_printf("moves: %d\n", game->moves);
		}
		else
		{
			if (game->map.collectibles == 0)
			{
				ft_printf("Well done!\n");
				exit(0);
			}
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
		exit(0);
	return (0);
}
