/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:12:16 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 13:18:11 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Initializes the game map by counting rows
 * and allocating memory.
 *
 * This function reads the map file line by line
 * to determine the number of rows.
 * It then allocates memory for storing the map.
 * If memory allocation fails,
 * an error message is displayed.
 *
 * @param fd File descriptor of the map file.
 * @param game Pointer to the game structure
 * where the map will be stored.
 */
static void	init_map_iterative(int fd, t_game *game)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	game->map.rows = count;
	game->map.full = malloc(count * sizeof(char *));
	if (!game->map.full)
		error_msg("Memory allocation failed.", game);
	close(fd);
}

/**
 * @brief Recursively reads map lines from the
 * file and stores them in memory.
 *
 * This function reads each line of the map file
 * and stores it in the `game->map.full` array.
 * It determines the number of columns based on
 * the first line. If reading fails, 
 * it triggers an error message. The function
 * uses recursion to process each line.
 *
 * @param fd File descriptor of the map file.
 * @param game Pointer to the game structure
 * where the map will be stored.
 * @param current_row The current row being
 * read and stored.
 */
static void	read_map_lines(int fd, t_game *game, int current_row)
{
	if (current_row == game->map.rows)
		return ;
	game->map.full[current_row] = get_next_line(fd);
	if (!game->map.full[current_row])
		error_msg("Error reading map line.", game);
	if (current_row == 0)
		game->map.columns = ft_strlen(game->map.full[current_row]) - 1;
	read_map_lines(fd, game, current_row + 1);
}

/**
 * @brief Initializes the game map from a file.
 *
 * This function opens the map file, determines
 * its dimensions, allocates memory, 
 * and reads its contents into the game structure.
 * It also performs a validation 
 * check on the map. If any file operation fails,
 * an error message is displayed.
 *
 * @param filename Path to the map file.
 * @param game Pointer to the game structure where
 * the map will be stored.
 */
void	init_map(const char *filename, t_game *game)
{
	int	fd;

	game->moves = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_msg("The map cannot be opened.", game);
	init_map_iterative(fd, game);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_msg("The map cannot be opened.", game);
	read_map_lines(fd, game, 0);
	close(fd);
	ft_check_map(filename, &fd, game);
	close(fd);
}
