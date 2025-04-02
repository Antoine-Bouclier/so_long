/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:15:52 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/19 12:37:33 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Frees and destroys the images used in the game.
 *
 * This function is responsible for cleaning up the images
 * used in the game by destroying them 
 * using `mlx_destroy_image` for each image pointer. It ensures
 * that resources are properly freed 
 * to prevent memory leaks when the game is closed or reset.
 *
 * It checks if the `mlx` object and each individual image
 * pointer are not NULL before attempting 
 * to destroy them.
 *
 * @param game Pointer to the game structure containing
 * the images to be destroyed.
 */
static void	ft_destroy_img(t_game *game)
{
	if (game->mlx)
	{
		if (game->player.img.xpm_ptr)
			mlx_destroy_image(game->mlx, game->player.img.xpm_ptr);
		if (game->exit.img.xpm_ptr)
			mlx_destroy_image(game->mlx, game->exit.img.xpm_ptr);
		if (game->collectible_img.xpm_ptr)
			mlx_destroy_image(game->mlx, game->collectible_img.xpm_ptr);
		if (game->floor_img.xpm_ptr)
			mlx_destroy_image(game->mlx, game->floor_img.xpm_ptr);
		if (game->wall_img.xpm_ptr)
			mlx_destroy_image(game->mlx, game->wall_img.xpm_ptr);
		if (game->player_on_exit.xpm_ptr)
			mlx_destroy_image(game->mlx, game->player_on_exit.xpm_ptr);
	}
}

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
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}
