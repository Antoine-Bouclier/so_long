/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:00:15 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 10:37:57 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_heart(t_game *game, t_enemy_list *monster)
{
	if (game->map.heart_collected > 1)
	{
		game->map.heart_collected--;
		free(monster->projectile);
		monster->projectile = NULL;
		ft_printf("You lost a heart! Remaining: %d\n",
			game->map.heart_collected);
		return ;
	}
	else
	{
		ft_printf("You lose!");
		close_window(game);
	}
}

static void	projectile_direction(t_enemy_list *monster)
{
	monster->projectile->next_pos.x = 0;
	monster->projectile->next_pos.y = 0;
	if (monster->projectile->direction == UP)
		monster->projectile->next_pos.y = -1;
	else if (monster->projectile->direction == RIGHT)
		monster->projectile->next_pos.x = 1;
	else if (monster->projectile->direction == DOWN)
		monster->projectile->next_pos.y = 1;
	else if (monster->projectile->direction == LEFT)
		monster->projectile->next_pos.x = -1;
}

static void	fire_projectile(t_game *game, t_enemy_list *monster)
{
	monster->projectile = malloc(sizeof(t_enemy));
	if (!monster->projectile)
		error_msg("Memory allocation failed for projectile", game);
	ft_memset(monster->projectile, 0, sizeof(t_enemy));
	get_direction(monster->projectile, game->player_pos,
		monster->monster->position);
	projectile_direction(monster);
	monster->projectile->position.x = (monster->monster->position.x
			+ monster->projectile->next_pos.x);
	monster->projectile->position.y = (monster->monster->position.y
			+ monster->projectile->next_pos.y);
	if (game->map.full[monster->projectile->position.y]
		[monster->projectile->position.x] == FLOOR)
		game->map.full[monster->projectile->position.y]
		[monster->projectile->position.x] = PROJECTILE;
	else if (game->map.full[monster->projectile->position.y]
		[monster->projectile->position.x] == PLAYER)
		handle_heart(game, monster);
	else if (game->map.full[monster->projectile->position.y]
		[monster->projectile->position.x] == COLLECTIBLE)
		game->map.full[monster->projectile->position.y]
		[monster->projectile->position.x] = PROJECTILE;
	else
		ft_free_projectile(monster);
}

static int	was_collectible(t_collectible *collectible, t_enemy_list *monster)
{
	t_collectible	*current;

	current = collectible;
	while (current)
	{
		if (current->position.x == monster->projectile->position.x
			&& current->position.y == monster->projectile->position.y)
			return (1);
		current = current->next;
	}
	return (0);
}

void	handle_projectile(t_game *game)
{
	t_enemy_list	*monster;
	int				collectible;
	int				heart;

	monster = game->enemy;
	while (monster)
	{
		if (!monster->projectile)
			fire_projectile(game, monster);
		else
		{
			collectible = was_collectible(game->collectibles, monster);
			heart = was_collectible(game->hearts, monster);
			update_projectiles(game, monster, collectible, heart);
		}
		monster = monster->next;
	}
}
