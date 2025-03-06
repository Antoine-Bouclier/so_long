/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:45:48 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/06 08:14:34 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	ft_check_parameters(t_game *game)
{
	if (game->map.collectibles <= 0)
		error_msg("Error! Your map must have at least 1 collectible", game);
	else if (game->map.exit != 1)
		error_msg("Error! Your map must have only 1 exit", game);
	else if (game->map.player != 1)
		error_msg("Error! Your map must have only 1 player", game);
}
