/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:12:16 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/08 07:32:55 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	init_map_recursive(int fd, t_game *game, int count)
{
	char *line;
	
	line = get_next_line(fd);
	if (!line)
	{
		game->map.rows = count;
		game->map.full = malloc(count * sizeof(char *));
		if (!game->map.full)
			error_msg("Memory allocation failed.", game);
		close(fd);
		return;
	}
	free(line);
	init_map_recursive(fd, game, count + 1);
}

static void	read_map_lines(int fd, t_game *game, int current_row)
{
	if (current_row == game->map.rows)
		return;
	game->map.full[current_row] = get_next_line(fd);
	if (!game->map.full[current_row])
		error_msg("Error reading map line.", game);
	if (current_row == 0)
		game->map.columns = ft_strlen(game->map.full[current_row]) - 1;
	read_map_lines(fd, game, current_row + 1);
}

void	init_map(const char* filename, t_game *game)
{
	int	fd;
	
	game->moves = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_msg("The map cannot be opened.", game);
	init_map_recursive(fd, game, 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_msg("The map cannot be opened.", game);
	read_map_lines(fd, game, 0);
	ft_check_map(filename, &fd, game);
	close(fd);
}
