/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:19:38 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/19 07:12:47 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Checks if a given line is completely surrounded by walls.
 *
 * This function iterates through each character of
 * the provided line and checks 
 * if all characters (except the newline or null
 * terminator) are walls (`WALL`). 
 * If any character is not a wall, an error message
 * is displayed, and the function 
 * terminates by freeing the line and closing the
 * file descriptor.
 *
 * @param line The line to be checked for walls.
 * @param fd The file descriptor of the map file.
 * @param game Pointer to the game structure used
 * for error handling.
 */
void	is_wall_line(char *line, int *fd, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != WALL)
		{
			free(line);
			close(*fd);
			error_msg("Your map must be surrounded by walls", game);
		}
		i++;
	}
}

/**
 * @brief Validates the essential elements of the game map.
 *
 * This function checks that the map contains at
 * least one collectible, one exit, 
 * and one player. It also ensures that the map
 * has no more than one exit and 
 * one player. If any of these conditions are not
 * met, an error message is displayed.
 *
 * @param game Pointer to the game structure that
 * contains information about the map's elements.
 */
static void	validate_map_elements(t_game *game)
{
	if (game->map.collectibles <= 0)
		error_msg("Your map must have at least 1 collectible", game);
	else if (game->map.exit > 1)
		error_msg("Your map must have only 1 exit", game);
	else if (game->map.exit < 1)
		error_msg("Your map must have atleast 1 exit", game);
	else if (game->map.player > 1)
		error_msg("Your map must have only 1 player", game);
	else if (game->map.player < 1)
		error_msg("Your map must have atleast 1 player", game);
}

/**
 * @brief Checks the validity of the game map.
 *
 * This function reads each line of the map file
 * and validates the map's structure. 
 * It ensures that the first and last rows are walls,
 * and the rest of the lines are valid.
 * After reading all lines, it checks if the map contains
 * valid numbers of collectibles, 
 * exits, and players. If any validation fails, an
 * error message is displayed.
 *
 * @param filename The path to the map file.
 * @param fd Pointer to the file descriptor, which is
 * set to the opened file descriptor.
 * @param game Pointer to the game structure used for
 * error handling and map data.
 */
void	ft_check_map(const char *filename, int *fd, t_game *game)
{
	char	*line;
	int		rows;

	rows = 0;
	game->map.collectibles = 0;
	game->map.exit = 0;
	game->map.player = 0;
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		error_msg("The map cannot be opened", game);
	while (1)
	{
		line = get_next_line(*fd);
		if (!line)
			break ;
		if (rows == 0 || rows == game->map.rows - 1)
			is_wall_line(line, fd, game);
		else
			is_valid_line(line, fd, game);
		free(line);
		rows++;
	}
	validate_map_elements(game);
}

/**
 * @brief Checks if the map fits within the screen size.
 *
 * This function compares the map's dimensions (in pixels)
 * with the screen size to 
 * ensure that the map can be properly displayed.
 * If the map is too large for the screen, 
 * an error message is displayed.
 *
 * @param game Pointer to the game structure that
 * contains the map dimensions.
 */
void	check_map_size(t_game *game)
{
	int	screen_width;
	int	screen_height;

	(void)mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	if ((game->map.columns * 32) > screen_width
		|| (game->map.rows * 32) + 64 > screen_height)
		error_msg("Map is larger than screen size", game);
}
