/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:26:00 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 10:53:54 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_destroy_img_monster(t_game *game)
{
	if (game->images.monster_with_axe[0].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.monster_with_axe[0].xpm_ptr);
	if (game->images.monster_with_axe[1].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.monster_with_axe[1].xpm_ptr);
	if (game->images.monster_with_axe[2].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.monster_with_axe[2].xpm_ptr);
	if (game->images.monster_with_axe[3].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.monster_with_axe[3].xpm_ptr);
	if (game->images.monster_without_axe[0].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.monster_without_axe[0]
			.xpm_ptr);
	if (game->images.monster_without_axe[1].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.monster_without_axe[1]
			.xpm_ptr);
	if (game->images.monster_without_axe[2].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.monster_without_axe[2]
			.xpm_ptr);
	if (game->images.monster_without_axe[3].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.monster_without_axe[3]
			.xpm_ptr);
}

static void	ft_destroy_img_bonus(t_game *game)
{
	if (game->images.projectile[0].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.projectile[0].xpm_ptr);
	if (game->images.projectile[1].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.projectile[1].xpm_ptr);
	if (game->images.projectile[2].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.projectile[2].xpm_ptr);
	if (game->images.projectile[3].xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.projectile[3].xpm_ptr);
	if (game->images.rock.xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.rock.xpm_ptr);
	if (game->images.heart_floor.xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.heart_floor.xpm_ptr);
	if (game->images.heart_wall.xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.heart_wall.xpm_ptr);
	if (game->images.double_projectile.xpm_ptr)
		mlx_destroy_image(game->mlx, game->images.double_projectile.xpm_ptr);
	ft_destroy_img_monster(game);
}

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
void	ft_destroy_img(t_game *game)
{
	if (game->mlx)
	{
		if (game->images.player.xpm_ptr)
			mlx_destroy_image(game->mlx, game->images.player.xpm_ptr);
		if (game->images.exit.xpm_ptr)
			mlx_destroy_image(game->mlx, game->images.exit.xpm_ptr);
		if (game->images.collectible.xpm_ptr)
			mlx_destroy_image(game->mlx, game->images.collectible.xpm_ptr);
		if (game->images.floor.xpm_ptr)
			mlx_destroy_image(game->mlx, game->images.floor.xpm_ptr);
		if (game->images.wall.xpm_ptr)
			mlx_destroy_image(game->mlx, game->images.wall.xpm_ptr);
		if (game->images.player_on_exit.xpm_ptr)
			mlx_destroy_image(game->mlx, game->images.player_on_exit.xpm_ptr);
		ft_destroy_img_bonus(game);
	}
}
