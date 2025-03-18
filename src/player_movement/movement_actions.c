/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:35:05 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/11 14:43:17 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
