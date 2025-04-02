/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:35:03 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 13:18:43 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_monsters(t_game *game, int y, int x, char current_char)
{
	t_enemy_list	*new_monster;

	if (current_char == MONSTER)
	{
		new_monster = malloc(sizeof(t_enemy_list));
		if (!new_monster)
			error_msg("Memory allocation failed for new monsters", game);
		new_monster->monster = malloc(sizeof(t_enemy));
		if (new_monster->monster == NULL)
			error_msg("Memory allocation failed for monster", game);
		new_monster->monster->position.x = x;
		new_monster->monster->position.y = y;
		new_monster->monster->next_pos.x = x;
		new_monster->monster->next_pos.y = y;
		new_monster->monster->direction = 0;
		new_monster->projectile = NULL;
		new_monster->next = game->enemy;
		game->enemy = new_monster;
	}
}

void	get_direction(t_enemy *enemy, t_position player, t_position monster)
{
	t_position	pos;

	pos.x = ft_abs(player.x - monster.x);
	pos.y = ft_abs(player.y - monster.y);
	if (pos.x > pos.y)
	{
		if (player.x > monster.x)
			enemy->direction = RIGHT;
		else
			enemy->direction = LEFT;
	}
	else if (pos.y > pos.x)
	{
		if (player.y > monster.y)
			enemy->direction = DOWN;
		else
			enemy->direction = UP;
	}
	else
	{
		if (player.x > monster.x)
			enemy->direction = RIGHT;
		else
			enemy->direction = LEFT;
	}
}
