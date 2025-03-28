/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:57:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 07:15:29 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_to_win_monster(t_game *game, int x, int y)
{
	t_enemy_list	*current;

	current = game->enemy;
	while (current)
	{
		if (current->monster->position.x == x && current
			->monster->position.y == y)
		{
			get_direction(current->monster, game->player_pos,
				current->monster->position);
			if (!current->projectile)
				mlx_put_image_to_window(game->mlx, game->win,
					game->images.monster_with_axe[current->monster
					->direction].xpm_ptr, x * 32, y * 32);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->images.monster_without_axe[current
					->monster->direction].xpm_ptr, x * 32, y * 32);
			break ;
		}
		current = current->next;
	}
}

static void	img_to_win_projectile(t_game *game, int x, int y)
{
	t_enemy_list	*current;

	current = game->enemy;
	while (current)
	{
		if (current->projectile && current->projectile
			->position.x == x && current->projectile->position.y == y)
		{
			if (game->images.projectile[current->projectile->direction].xpm_ptr)
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->images.projectile[current->projectile
					->direction].xpm_ptr, x * 32, y * 32);
			}
			else
				error_msg("Error: Projectile image missing.", game);
			break ;
		}
		current = current->next;
	}
}

void	img_to_win_bonus(t_game *game, char current_char, int x, int y)
{
	if (current_char == MONSTER)
		img_to_win_monster(game, x, y);
	else if (current_char == PROJECTILE)
		img_to_win_projectile(game, x, y);
	else if (current_char == ROCK)
		mlx_put_image_to_window(game->mlx, game->win,
			game->images.rock.xpm_ptr, x * 32, y * 32);
	else if (current_char == HEART)
		mlx_put_image_to_window(game->mlx, game->win,
			game->images.heart_floor.xpm_ptr, x * 32, y * 32);
}
