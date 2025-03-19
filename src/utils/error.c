/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/19 07:08:07 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Displays an error message and frees
 * all game resources before exiting.
 *
 * This function is called when an error occurs
 * in the game. It prints the provided error message 
 * to the console and frees any memory allocated for
 * the game to prevent memory leaks. 
 * After that, the program exits with a failure status.
 *
 * @param msg The error message to be displayed.
 * @param game Pointer to the game structure containing
 * the map and player information.
 */
void	error_msg(char *msg, t_game *game)
{
	if (game)
	{
		ft_free_all_memory(game);
	}
	ft_printf("Error! %s\n", msg);
	exit(EXIT_FAILURE);
}
