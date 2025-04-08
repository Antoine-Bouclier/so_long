/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:00:11 by abouclie          #+#    #+#             */
/*   Updated: 2025/04/08 13:41:45 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	remove_projectile(t_game *game, t_position next)
{
	t_enemy_list	*monster;

	monster = game->enemy;
	while (monster)
	{
		if (monster->projectile && monster->projectile->position.x
			== next.x && monster->projectile->position.y == next.y)
		{
			game->map.full[next.y][next.x] = FLOOR;
			handle_heart(game, monster);
		}
		monster = monster->next;
	}
}
