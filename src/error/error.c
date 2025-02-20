/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/20 15:52:36 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	ft_free_map(t_game *game)
{
	
}

void	error_msg(char *msg, t_game *game)
{
	if (game->map_alloc == 1)
		ft_free_map(game);
	ft_printf("Error!\n%s\n", msg);
	exit(EXIT_FAILURE);
}
