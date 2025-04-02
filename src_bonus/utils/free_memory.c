/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:15:52 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 13:19:25 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Frees the memory allocated for the map structure.
 *
 * This function deallocates the memory used by the map's
 * rows and the array storing the map data. 
 * It iterates through each row of the map, freeing the
 * memory allocated for each line, 
 * and then frees the array itself. After freeing the memory,
 * it sets the map's pointers to NULL 
 * and resets the row and column counts to 0, ensuring the
 * map structure is properly cleaned up.
 *
 * @param map Pointer to the map structure to be freed.
 */
void	ft_free_map(t_map *map)
{
	int	i;

	if (!map || !map->full)
		return ;
	i = 0;
	while (i < map->rows && map->full[i])
	{
		free(map->full[i]);
		i++;
	}
	free(map->full);
	map->full = NULL;
	map->rows = 0;
	map->columns = 0;
}

static void	ft_free_monster(t_enemy_list *enemy)
{
	t_enemy_list	*current;
	t_enemy_list	*next;

	current = enemy;
	while (current)
	{
		next = current->next;
		free(current->monster);
		free(current->projectile);
		free(current);
		current = next;
	}
}

static void	ft_free_collectible(t_collectible *collectible)
{
	t_collectible	*current;
	t_collectible	*next;

	current = collectible;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	ft_free_projectile(t_enemy_list *monster)
{
	free(monster->projectile);
	monster->projectile = NULL;
}

/**
 * @brief Frees all allocated memory and cleans up resources.
 *
 * This function is responsible for freeing all the resources
 * allocated during the game session.
 * It performs the following tasks:
 * - Destroys the images used in the game (player, exit,
 * collectible, floor, wall) by calling `ft_destroy_img`.
 * - Frees the map's memory by calling `ft_free_map`.
 * - Destroys the game window created by `mlx_new_window`
 * if it exists.
 * - Destroys the display connection used by the MLX
 * library and frees the memory associated with `mlx`.
 * - Finally, it frees the memory allocated for the
 * game structure itself.
 *
 * This function ensures that all memory is properly freed
 * before the game exits, preventing memory leaks.
 *
 * @param game Pointer to the game structure that contains
 * all the resources to be freed.
 */
void	ft_free_all_memory(t_game *game)
{
	if (!game)
		return ;
	ft_destroy_img(game);
	ft_free_map(&(game->map));
	ft_free_monster(game->enemy);
	ft_free_collectible(game->collectibles);
	ft_free_collectible(game->hearts);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}
