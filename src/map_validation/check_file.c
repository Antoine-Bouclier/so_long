/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:29:12 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 07:04:05 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Checks the command line arguments for map validation.
 *
 * This function checks if the correct number of
 * arguments is provided and ensures that 
 * the map file has the correct `.ber` extension.
 * If any of these checks fail, 
 * an error message is displayed.
 *
 * @param argc The number of command line arguments.
 * @param argv Array of command line arguments.
 * @param game Pointer to the game structure used for error handling.
 */
void	ft_check_arg(int argc, char **argv, t_game *game)
{
	int	arg_len;

	game->map_alloc = 0;
	if (argc > 2)
		error_msg("Too many argument.", game);
	else if (argc < 2)
		error_msg("The map file is missing.", game);
	arg_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][arg_len - 4], ".ber", 4))
		error_msg("Wrong extension file. It should be .ber", game);
}

/**
 * @brief Checks if the specified file exists and can be opened.
 *
 * This function attempts to open the file in
 * read-only mode. If the file cannot 
 * be opened (i.e., the file does not exist or
 * there is an error), it closes the 
 * file descriptor and displays an error message.
 *
 * @param filename The path to the map file.
 * @param game Pointer to the game structure used for error handling.
 * @param fd Pointer to an integer that will hold the file descriptor
 * if the file is successfully opened.
 */
static void	file_exists(const char *filename, t_game *game, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		close(*fd);
		error_msg("The map cannot be opened.", game);
	}
}

/**
 * @brief Checks if the specified file is empty.
 *
 * This function reads the first byte of the file. If the
 * file is empty or cannot be read,
 * it closes the file descriptor and displays an error message
 * indicating that the file is empty.
 *
 * @param fd The file descriptor of the file to check.
 * @param game Pointer to the game structure used for error handling.
 */
static void	file_empty(int fd, t_game *game)
{
	int		b_read;
	char	buf[1];

	b_read = read(fd, buf, 1);
	if (b_read <= 0)
	{
		close(fd);
		error_msg("The file is empty.", game);
	}
	close(fd);
}

/**
 * @brief Checks the validity of the specified file.
 *
 * This function checks if the file exists and can be
 * opened, then checks if the file is empty.
 * If any of these checks fail, an error message is
 * displayed. The file descriptor is closed 
 * after the checks are completed.
 *
 * @param filename The path to the file to be checked.
 * @param game Pointer to the game structure used for error handling.
 */
void	ft_check_file(const char *filename, t_game *game)
{
	int	fd;

	file_exists(filename, game, &fd);
	file_empty(fd, game);
	close(fd);
}
