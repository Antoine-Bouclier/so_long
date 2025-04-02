/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:35:05 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/19 07:10:56 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Moves the player to a new position
 * on the map and updates the game state.
 *
 * This function handles the logic of moving the
 * player to a new position on the map. 
 * It checks if the new position contains a collectible,
 * and if so, decreases the collectible count. 
 * The player's current position is updated to the floor,
 * and the new position is updated to the player’s position. 
 * If the player was previously on the exit, the exit is
 * restored at the old position. 
 * It also increments the move count and prints it to the console.
 *
 * @param game Pointer to the game structure containing
 * the map and player information.
 * @param current Pointer to the current position of the player.
 * @param next Pointer to the next position the player is moving to.
 */
void	move_to_floor(t_game *game, t_position *current, t_position *next)
{
	if (game->map.full[next->y][next->x] == COLLECTIBLE)
		game->map.collectibles--;
	game->player.position.y = next->y;
	game->player.position.x = next->x;
	if (current->x == game->exit.position.x
		&& current->y == game->exit.position.y)
		game->map.full[current->y][current->x] = EXIT;
	else
		game->map.full[current->y][current->x] = FLOOR;
	game->map.full[next->y][next->x] = PLAYER;
	game->moves++;
	ft_printf("moves: %d\n", game->moves);
}

/**
 * @brief Moves the player to the exit if all
 * collectibles are collected.
 *
 * This function handles the logic of moving the player
 * to the exit. If there are still collectibles 
 * remaining in the map, the player moves to the next
 * position and the move counter is incremented. 
 * The player's old position is set to floor, and the new
 * position is updated with the player's position.
 * If all collectibles have been collected, the player
 * reaches the exit, and a "You win!" message is displayed. 
 * The game ends by freeing all memory and exiting the program.
 *
 * @param game Pointer to the game structure containing
 * the map and player information.
 * @param current Pointer to the current position of the player.
 * @param next Pointer to the next position the player is moving to.
 */
void	move_to_exit(t_game *game, t_position *current, t_position *next)
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
	{
		ft_printf("You win!\n");
		ft_free_all_memory(game);
		exit(0);
	}
}
