/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:50:55 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/06 12:17:50 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_img(t_game *game)
{
	game->width = 32;
	game->height = 32;
	game->player_img.img = "../../assets/sprite/player.xpm";
	game->wall_img.img = "../../assets/sprite/wall.xpm";
	game->collectible_img.img = "../../assets/sprite/rupee.xpm";
	game->floor_img.img = "../../assets/sprite/floor.xpm";
	game->exit_img.img = "../../assets/sprite/exit.xpm";
	game->player_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, game->player_img.img, game->width, game->height);
	game->wall_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, game->wall_img.img, game->width, game->height);
	game->collectible_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, game->collectible_img.img, game->width, game->height);
	game->floor_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, game->floor_img.img, game->width, game->height);
	game->exit_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, game->exit_img.img, game->width, game->height);
}

