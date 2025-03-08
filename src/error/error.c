/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/08 13:56:28 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		free(game->map.full[i]);
		i++;
	}
	free(game->map.full);
}

void	error_msg(char *msg, t_game *game)
{
	if (game->map_alloc == 1)
		ft_free_map(game);
	free(game);
	ft_printf("Error! %s\n", msg);
	exit(EXIT_FAILURE);
}

static void	ft_destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.img.xpm_ptr);
	mlx_destroy_image(game->mlx, game->exit.img.xpm_ptr);
	mlx_destroy_image(game->mlx, game->collectible_img.xpm_ptr);
	mlx_destroy_image(game->mlx, game->floor_img.xpm_ptr);
	mlx_destroy_image(game->mlx, game->wall_img.xpm_ptr);
}

void	ft_free_all_memory(t_game *game)
{
	ft_destroy_img(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}
