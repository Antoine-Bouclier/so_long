/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:50:55 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/19 12:43:27 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	sprite_path(t_game *game)
{
	game->player.img.img = "./assets/sprite/player_better.xpm";
	game->wall_img.img = "./assets/sprite/wall.xpm";
	game->collectible_img.img = "./assets/sprite/rupee.xpm";
	game->floor_img.img = "./assets/sprite/floor.xpm";
	game->exit.img.img = "./assets/sprite/exit.xpm";
	game->player_on_exit.img = "./assets/sprite/player_on_exit.xpm";
}

static void	is_xpm_failed(char *img, t_game *game)
{
	if (!img)
		error_msg("xpm file failed.", game);
}

/**
 * @brief Loads and sets up the game images.
 *
 * This function initializes the image file paths
 * for various game elements
 * (player, walls, collectibles, floor, and exit) and
 * loads them into memory
 * using the MiniLibX function `mlx_xpm_file_to_image`.
 *
 * @param game Pointer to the game structure containing
 * graphical resources.
 */
void	set_img(t_game *game)
{
	game->img_width = IMG_WIDTH;
	game->img_height = IMG_HEIGHT;
	sprite_path(game);
	game->player.img.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->player.img.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->player.img.xpm_ptr, game);
	game->wall_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->wall_img.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->wall_img.xpm_ptr, game);
	game->collectible_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->collectible_img.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->collectible_img.xpm_ptr, game);
	game->floor_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->floor_img.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->floor_img.xpm_ptr, game);
	game->exit.img.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->exit.img.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->exit.img.xpm_ptr, game);
	game->player_on_exit.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->player_on_exit.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->player_on_exit.xpm_ptr, game);
}
