/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:27:00 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 07:03:25 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Closes the game window and frees all allocated memory.
 *
 * This function is called when the user attempts
 * to close the window (e.g., by pressing the close button). 
 * It frees all memory allocated for the game and
 * its resources before exiting the program. 
 * This ensures a clean exit without memory leaks.
 *
 * @param game Pointer to the game structure containing
 * the map and player information.
 * @return 0 to indicate the function has completed successfully.
 */
int	close_window(t_game *game)
{
	ft_free_all_memory(game);
	exit(0);
	return (0);
}
