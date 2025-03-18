/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:30:10 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/18 13:14:57 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Validates that the given line is surrounded by walls.
 *
 * This function checks that the first and last characters of a line are walls (`WALL`). 
 * If either of these conditions is not met, it closes the file descriptor and displays 
 * an error message, indicating that the map must be surrounded by walls.
 *
 * @param line The line of the map to be validated.
 * @param fd Pointer to the file descriptor used to open the map file.
 * @param game Pointer to the game structure, used to display error messages.
 */
static void	validate_line_walls(char *line, int *fd, t_game *game)
{
	if (line[0] != WALL || line[ft_strlen(line) - 2] != WALL)
	{
		close(*fd);
		error_msg("Your map must be surrounded by walls", game);
	}
}

/**
 * @brief Validates the characters in a given map line.
 *
 * This function checks each character in the line to ensure it is one of the allowed characters: 
 * `FLOOR`, `WALL`, `COLLECTIBLE`, `EXIT`, or `PLAYER`. If an invalid character is found, 
 * it closes the file descriptor and displays an error message. Additionally, it updates the count 
 * for collectibles, exits, and players based on the characters in the line.
 *
 * @param line The line of the map to be validated.
 * @param fd Pointer to the file descriptor used to open the map file.
 * @param game Pointer to the game structure, used to update the counts of map elements and display error messages.
 */
static void	validate_line_characters(char *line, int *fd, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != FLOOR && line[i] != WALL && line[i] != COLLECTIBLE
			&& line[i] != EXIT && line[i] != PLAYER && line[i] != '\n')
		{
			close(*fd);
			error_msg("Invalid character in map", game);
		}
		if (line[i] == COLLECTIBLE)
			game->map.collectibles++;
		else if (line[i] == EXIT)
			game->map.exit++;
		else if (line[i] == PLAYER)
			game->map.player++;
		i++;
	}
}

/**
 * @brief Validates the length of a given map line.
 *
 * This function checks if the length of the line matches the expected length 
 * based on the number of columns in the map. It ensures that all lines have the 
 * same length, and if any line does not match the expected length, it frees the 
 * line, closes the file descriptor, and displays an error message.
 *
 * @param line The line of the map to be validated.
 * @param fd Pointer to the file descriptor used to open the map file.
 * @param game Pointer to the game structure, used to display error messages.
 */
static void	validate_line_length(char *line, int *fd, t_game *game)
{
	int	i;

	i = ft_strlen(line) - 1;
	if (i != game->map.columns && (i != game->map.columns - 1
			|| line[i - 1] != '\n'))
	{
		free(line);
		close(*fd);
		error_msg("All lines must have the same length", game);
	}
}

/**
 * @brief Validates a given map line by checking walls, characters, and length.
 *
 * This function performs three checks on a line from the map: 
 * 1. It ensures that the line is surrounded by walls.
 * 2. It checks that all characters in the line are valid (floor, wall, collectible, exit, or player).
 * 3. It verifies that the length of the line matches the expected length.
 * 
 * If any of these validations fail, it closes the file descriptor and displays an error message.
 *
 * @param line The line of the map to be validated.
 * @param fd Pointer to the file descriptor used to open the map file.
 * @param game Pointer to the game structure, used to display error messages.
 */
void	is_valid_line(char *line, int *fd, t_game *game)
{
	validate_line_walls(line, fd, game);
	validate_line_characters(line, fd, game);
	validate_line_length(line, fd, game);
}
