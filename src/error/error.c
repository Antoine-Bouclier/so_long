/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/06 08:03:25 by abouclie         ###   ########.fr       */
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
