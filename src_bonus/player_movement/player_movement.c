/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:06:15 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 13:19:04 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Moves the player upwards on the map, if possible.
 *
 * This function attempts to move the player
 * one position upwards (towards the top) on the map. 
 * It first calculates the next position based on the
 * player's current position. 
 * If the next position is not a wall, the player is moved:
 * - If the next position is not the exit, the player
 * moves to the floor and the move is processed.
 * - If the next position is the exit, the player moves
 * to the exit and the win condition is triggered.
 *
 * @param game Pointer to the game structure containing
 * the map and player information.
 * @param current Pointer to the current position of the player.
 */
static void	move_top(t_game *game, t_position *current)
{
	t_position	next;

	next.y = game->player_pos.y - 1;
	next.x = game->player_pos.x;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] == MONSTER)
		{
			ft_printf("You lose!");
			close_window(game);
		}
		else if (game->map.full[next.y][next.x] == PROJECTILE)
			remove_projectile(game, next);
		else if (game->map.full[next.y][next.x] != EXIT)
			move_to_floor(game, current, &next);
		else
			move_to_exit(game, current, &next);
	}
}

/**
 * @brief Moves the player left on the map, if possible.
 *
 * This function attempts to move the player
 * one position to the left on the map. 
 * It calculates the next position based on the
 * player's current position. 
 * If the next position is not a wall, the player is moved:
 * - If the next position is not the exit, the player moves
 * to the floor and the move is processed.
 * - If the next position is the exit, the player moves to
 * the exit and the win condition is triggered.
 *
 * @param game Pointer to the game structure containing
 * the map and player information.
 * @param current Pointer to the current position of the player.
 */
static void	move_left(t_game *game, t_position *current)
{
	t_position	next;

	next.y = game->player_pos.y;
	next.x = game->player_pos.x - 1;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] == MONSTER)
		{
			ft_printf("You lose!");
			close_window(game);
		}
		else if (game->map.full[next.y][next.x] == PROJECTILE)
			remove_projectile(game, next);
		else if (game->map.full[next.y][next.x] != EXIT)
			move_to_floor(game, current, &next);
		else
			move_to_exit(game, current, &next);
	}
}

/**
 * @brief Moves the player right on the map, if possible.
 *
 * This function attempts to move the player
 * one position to the right on the map. 
 * It calculates the next position based on the
 * player's current position. 
 * If the next position is not a wall, the player is moved:
 * - If the next position is not the exit, the player moves
 * to the floor and the move is processed.
 * - If the next position is the exit, the player moves to
 * the exit and the win condition is triggered.
 *
 * @param game Pointer to the game structure containing
 * the map and player information.
 * @param current Pointer to the current position of the player.
 */
static void	move_right(t_game *game, t_position *current)
{
	t_position	next;

	next.y = game->player_pos.y;
	next.x = game->player_pos.x + 1;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] == MONSTER)
		{
			ft_printf("You lose!");
			close_window(game);
		}
		else if (game->map.full[next.y][next.x] == PROJECTILE)
			remove_projectile(game, next);
		else if (game->map.full[next.y][next.x] != EXIT)
			move_to_floor(game, current, &next);
		else
			move_to_exit(game, current, &next);
	}
}

/**
 * @brief Moves the player downwards on the map, if possible.
 *
 * This function attempts to move the player
 * one position to the downwards on the map. 
 * It calculates the next position based on the
 * player's current position. 
 * If the next position is not a wall, the player is moved:
 * - If the next position is not the exit, the player moves
 * to the floor and the move is processed.
 * - If the next position is the exit, the player moves to
 * the exit and the win condition is triggered.
 *
 * @param game Pointer to the game structure containing
 * the map and player information.
 * @param current Pointer to the current position of the player.
 */
static void	move_bottom(t_game *game, t_position *current)
{
	t_position	next;

	next.y = game->player_pos.y + 1;
	next.x = game->player_pos.x;
	if (game->map.full[next.y][next.x] != WALL)
	{
		if (game->map.full[next.y][next.x] == MONSTER)
		{
			ft_printf("You lose!");
			close_window(game);
		}
		else if (game->map.full[next.y][next.x] == PROJECTILE)
			remove_projectile(game, next);
		else if (game->map.full[next.y][next.x] != EXIT)
			move_to_floor(game, current, &next);
		else
			move_to_exit(game, current, &next);
	}
}

/**
 * @brief Handles key press events to move the player or close the game.
 *
 * This function is called when a key is pressed.
 * It checks the keycode and performs the corresponding action:
 * - W: Moves the player upwards.
 * - S: Moves the player downwards.
 * - A: Moves the player to the left.
 * - D: Moves the player to the right.
 * - ESC: Closes the game window and exits the game.
 *
 * The player's current position is used to calculate
 * the next position based on the key pressed.
 * If the move is valid, the player is moved to the
 * new position. If the player reaches the exit,
 * the game may end, and the player wins.
 *
 * @param keycode The keycode of the key that was pressed.
 * @param game Pointer to the game structure containing
 * the map and player information.
 * @return 0 on successful key press handling.
 */
int	key_press(int keycode, t_game *game)
{
	t_position	current;

	current.y = game->player_pos.y;
	current.x = game->player_pos.x;
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
