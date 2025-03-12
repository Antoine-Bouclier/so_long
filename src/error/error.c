/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/12 10:18:54 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void error_msg(char *msg, t_game *game)
{
	if (game)
	{
		ft_free_all_memory(game);
	}
	ft_printf("Error! %s\n", msg);
	exit(EXIT_FAILURE);
}

