/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:27:00 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/12 11:57:29 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window(t_game *game)
{
	ft_free_all_memory(game);
	exit(0);
	return (0);
}

void	check_map_size(t_game *game)
{
	int screen_width;
	int screen_height;

	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	if ((game->map.columns * 32) > screen_width || (game->map.rows * 32) > screen_height)
		error_msg("Map is larger than screen size", game);
}
