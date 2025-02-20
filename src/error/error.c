/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/20 17:13:09 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	error_msg(char *msg, t_game *game)
{
	if (game->map_alloc == 1)
		ft_free_map(game);
	ft_printf("Error!\n%s\n", msg);
	exit(EXIT_FAILURE);
}
