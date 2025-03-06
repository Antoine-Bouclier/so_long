/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:50:55 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/06 15:27:34 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_img(t_game *game)
{
	game->img_width = 32;
	game->img_height = 32;
	game->player_img.img = "./assets/sprite/player.xpm";
	game->wall_img.img = "./assets/sprite/wall.xpm";
	game->collectible_img.img = "./assets/sprite/rupee.xpm";
	game->floor_img.img = "./assets/sprite/floor.xpm";
	game->exit_img.img = "./assets/sprite/exit.xpm";
	game->player_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, game->player_img.img, &game->img_width, &game->img_height);
	game->wall_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, game->wall_img.img, &game->img_width, &game->img_height);
	game->collectible_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, game->collectible_img.img, &game->img_width, &game->img_height);
	game->floor_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, game->floor_img.img, &game->img_width, &game->img_height);
	game->exit_img.xpm_ptr = mlx_xpm_file_to_image(game->mlx, game->exit_img.img, &game->img_width, &game->img_height);
	if (!game->player_img.xpm_ptr)
        ft_printf("Erreur : Impossible de charger l'image %s\n", game->player_img.img);
	if (!game->wall_img.xpm_ptr)
        ft_printf("Erreur : Impossible de charger l'image %s\n", game->wall_img.img);
	if (!game->collectible_img.xpm_ptr)
        ft_printf("Erreur : Impossible de charger l'image %s\n", game->collectible_img.img);
	if (!game->floor_img.xpm_ptr)
        ft_printf("Erreur : Impossible de charger l'image %s\n", game->floor_img.img);
	if (!game->exit_img.xpm_ptr)
        ft_printf("Erreur : Impossible de charger l'image %s\n", game->exit_img.img);
}
