/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:07:35 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 13:17:59 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_img_projectile(t_game *game)
{
	game->images.projectile[0].xpm_ptr = mlx_xpm_file_to_image(game->mlx, game
			->images.projectile[0].img, &game->img_width, &game->img_height);
	is_xpm_failed(game->images.projectile[0].xpm_ptr, game);
	game->images.projectile[2].xpm_ptr = mlx_xpm_file_to_image(game->mlx, game
			->images.projectile[2].img, &game->img_width, &game->img_height);
	is_xpm_failed(game->images.projectile[2].xpm_ptr, game);
	game->images.projectile[1].xpm_ptr = mlx_xpm_file_to_image(game->mlx, game
			->images.projectile[1].img, &game->img_width, &game->img_height);
	is_xpm_failed(game->images.projectile[1].xpm_ptr, game);
	game->images.projectile[3].xpm_ptr = mlx_xpm_file_to_image(game->mlx, game
			->images.projectile[3].img, &game->img_width, &game->img_height);
	is_xpm_failed(game->images.projectile[3].xpm_ptr, game);
	game->images.double_projectile.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->images.double_projectile.img, &game->img_width,
			&game->img_height);
	is_xpm_failed(game->images.double_projectile.xpm_ptr, game);
}

static void	set_img_monster_with_axe(t_game *game)
{
	game->images.monster_with_axe[DOWN].xpm_ptr = mlx_xpm_file_to_image(game
			->mlx, game->images.monster_with_axe[DOWN].img,
			&game->img_width, &game->img_height);
	is_xpm_failed(game->images.monster_with_axe[DOWN].xpm_ptr, game);
	game->images.monster_with_axe[UP].xpm_ptr = mlx_xpm_file_to_image(game
			->mlx, game->images.monster_with_axe[UP].img,
			&game->img_width, &game->img_height);
	is_xpm_failed(game->images.monster_with_axe[UP].xpm_ptr, game);
	game->images.monster_with_axe[RIGHT].xpm_ptr = mlx_xpm_file_to_image(game
			->mlx, game->images.monster_with_axe[RIGHT].img,
			&game->img_width, &game->img_height);
	is_xpm_failed(game->images.monster_with_axe[RIGHT].xpm_ptr, game);
	game->images.monster_with_axe[LEFT].xpm_ptr = mlx_xpm_file_to_image(game
			->mlx, game->images.monster_with_axe[LEFT].img,
			&game->img_width, &game->img_height);
	is_xpm_failed(game->images.monster_with_axe[LEFT].xpm_ptr, game);
}

static void	set_img_monster_without_axe(t_game *game)
{
	game->images.monster_without_axe[DOWN].xpm_ptr = mlx_xpm_file_to_image
		(game->mlx, game->images.monster_without_axe[DOWN].img,
			&game->img_width, &game->img_height);
	is_xpm_failed(game->images.monster_without_axe[DOWN].xpm_ptr, game);
	game->images.monster_without_axe[UP].xpm_ptr = mlx_xpm_file_to_image
		(game->mlx, game->images.monster_without_axe[UP].img,
			&game->img_width, &game->img_height);
	is_xpm_failed(game->images.monster_without_axe[UP].xpm_ptr, game);
	game->images.monster_without_axe[RIGHT].xpm_ptr = mlx_xpm_file_to_image
		(game->mlx, game->images.monster_without_axe[RIGHT].img,
			&game->img_width, &game->img_height);
	is_xpm_failed(game->images.monster_without_axe[RIGHT].xpm_ptr, game);
	game->images.monster_without_axe[LEFT].xpm_ptr = mlx_xpm_file_to_image
		(game->mlx, game->images.monster_without_axe[LEFT].img,
			&game->img_width, &game->img_height);
	is_xpm_failed(game->images.monster_without_axe[LEFT].xpm_ptr, game);
}

void	set_img_bonus(t_game *game)
{
	set_img_monster_with_axe(game);
	set_img_monster_without_axe(game);
	set_img_projectile(game);
	game->images.rock.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->images.rock.img, &game->img_width, &game->img_height);
	game->images.heart_floor.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->images.heart_floor.img, &game->img_width, &game->img_height);
	game->images.heart_wall.xpm_ptr = mlx_xpm_file_to_image(game->mlx,
			game->images.heart_wall.img, &game->img_width, &game->img_height);
}

void	sprite_path_bonus(t_game *game)
{
	game->images.monster_with_axe[0].img = "./assets/sprite/orc_back.xpm";
	game->images.monster_with_axe[1].img = "./assets/sprite/orc_right.xpm";
	game->images.monster_with_axe[2].img = "./assets/sprite/orc_face.xpm";
	game->images.monster_with_axe[3].img = "./assets/sprite/orc_left.xpm";
	game->images.monster_without_axe[0].img
		= "./assets/sprite/orc_back_without_axe.xpm";
	game->images.monster_without_axe[1].img
		= "./assets/sprite/orc_right_without_axe.xpm";
	game->images.monster_without_axe[2].img
		= "./assets/sprite/orc_face_without_axe.xpm";
	game->images.monster_without_axe[3].img
		= "./assets/sprite/orc_left_without_axe.xpm";
	game->images.projectile[0].img = "./assets/sprite/axe_up.xpm";
	game->images.projectile[1].img = "./assets/sprite/axe_right.xpm";
	game->images.projectile[2].img = "./assets/sprite/axe_down.xpm";
	game->images.projectile[3].img = "./assets/sprite/axe_left.xpm";
	game->images.rock.img = "./assets/sprite/rock.xpm";
	game->images.heart_floor.img = "./assets/sprite/heart.xpm";
	game->images.heart_wall.img = "./assets/sprite/heart_wall.xpm";
	game->images.double_projectile.img = "./assets/sprite/double_axe.xpm";
}
