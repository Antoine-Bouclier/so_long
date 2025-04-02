/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:25:48 by abouclie          #+#    #+#             */
/*   Updated: 2025/04/01 12:38:39 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		error_msg("Memory allocation failed for the game.", game);
	else
	{
		ft_memset(game, 0, sizeof(t_game));
		game->map.heart_collected = 1;
		game->mlx = NULL;
		game->win = NULL;
	}
	ft_check_arg(argc, argv, game);
	ft_check_file(argv[1], game);
	init_map(argv[1], game);
	if (validate_map(game) == 0)
		error_msg("Collectible or exit is not accessible.", game);
	win_map(game);
}
