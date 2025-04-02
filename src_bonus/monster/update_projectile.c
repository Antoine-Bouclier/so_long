/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_projectile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:11:10 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 13:18:54 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	floor_or_projectile(t_game *game, t_position pos)
{
	t_enemy_list	*current;
	t_position		next_pos;

	current = game->enemy;
	while (current)
	{
		if (current->projectile)
		{
			next_pos.y = current->projectile->position.y
				+ current->projectile->next_pos.y;
			next_pos.x = current->projectile->position.x
				+ current->projectile->next_pos.x;
			if (pos.y == next_pos.y && pos.x == next_pos.x)
				return (1);
		}
		current = current->next;
	}
	return (0);
}

static void	new_position(t_game *game, t_enemy_list *monster, t_position pos)
{
	monster->projectile->position.x += monster->projectile->next_pos.x;
	monster->projectile->position.y += monster->projectile->next_pos.y;
	pos.x = monster->projectile->position.x;
	pos.y = monster->projectile->position.y;
	if (pos.x < 1 || pos.x >= game->map.columns
		|| pos.y < 1 || pos.y >= game->map.rows)
		ft_free_projectile(monster);
	if (game->map.full[pos.y][pos.x] == FLOOR || game->map.full[pos.y]
		[pos.x] == COLLECTIBLE || game->map.full[pos.y][pos.x] == HEART)
		game->map.full[pos.y][pos.x] = PROJECTILE;
	else if (game->map.full[pos.y][pos.x] == PROJECTILE)
		game->map.full[pos.y][pos.x] = PROJECTILE;
	else if (game->map.full[pos.y][pos.x] == PLAYER)
		handle_heart(game, monster);
	else
		ft_free_projectile(monster);
}

void	update_projectiles(t_game *game, t_enemy_list *monster,
	int collectible, int heart)
{
	t_position		pos;

	pos.x = monster->projectile->position.x;
	pos.y = monster->projectile->position.y;
	if (monster->projectile)
	{
		if (game->map.full[pos.y][pos.x] == PLAYER)
			handle_heart(game, monster);
		pos.x = monster->projectile->position.x;
		pos.y = monster->projectile->position.y;
		if (collectible == 1)
			game->map.full[pos.y][pos.x] = COLLECTIBLE;
		else if (heart == 1)
			game->map.full[pos.y][pos.x] = HEART;
		else if (game->map.full[pos.y + monster->projectile->next_pos.y]
			[pos.x + monster->projectile->next_pos.x] != PROJECTILE)
			game->map.full[pos.y][pos.x] = FLOOR;
		else if (game->map.full[pos.y + monster->projectile->next_pos.y]
			[pos.x + monster->projectile->next_pos.x] == PROJECTILE)
		{
			if (floor_or_projectile(game, monster->projectile->position) == 0)
				game->map.full[pos.y][pos.x] = FLOOR;
		}
		new_position(game, monster, pos);
	}
}
