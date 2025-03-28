/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:50:55 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 09:09:38 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sprite_path(t_game *game)
{
	game->images.player.img = "./assets/sprite/player_better.xpm";
	game->images.wall.img = "./assets/sprite/wall.xpm";
	game->images.collectible.img = "./assets/sprite/rupee.xpm";
	game->images.floor.img = "./assets/sprite/floor.xpm";
	game->images.exit.img = "./assets/sprite/exit.xpm";
	game->images.player_on_exit.img = "./assets/sprite/player_on_exit.xpm";
	sprite_path_bonus(game);
}

void	is_xpm_failed(char *img, t_game *game)
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
	game->images.player.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->images.player.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->images.player.xpm_ptr, game);
	game->images.wall.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->images.wall.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->images.wall.xpm_ptr, game);
	game->images.collectible.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->images.collectible.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->images.collectible.xpm_ptr, game);
	game->images.floor.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->images.floor.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->images.floor.xpm_ptr, game);
	game->images.exit.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->images.exit.img, &game->img_width, &game->img_height);
	is_xpm_failed(game->images.exit.xpm_ptr, game);
	game->images.player_on_exit.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->images.player_on_exit.img, &game->img_width,
			&game->img_height);
	is_xpm_failed(game->images.player_on_exit.xpm_ptr, game);
	set_img_bonus(game);
}
