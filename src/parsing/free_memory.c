/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:15:52 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/12 10:26:45 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void ft_destroy_img(t_game *game)
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
    }
}


void	ft_free_map(t_map *map)
{
	int i;

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
