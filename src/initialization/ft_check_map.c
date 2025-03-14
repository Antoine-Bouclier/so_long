/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:19:38 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/14 13:01:13 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	is_valid_line(char *line, int *fd, t_game *game)
{
	int	i;

	i = 0;
	if (line[0] != WALL || line[ft_strlen(line) - 2] != WALL)
	{
		close(*fd);
		error_msg("Your map must be surrounded by walls", game);
	}
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
	if (i != game->map.columns && (i != game->map.columns - 1
			|| line[i - 1] != '\n'))
	{
		close(*fd);
		error_msg("All lines must have the same length", game);
	}
}

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
	while ((line = get_next_line(*fd)))
	{
		if (rows == 0 || rows == game->map.rows - 1)
			is_wall_line(line, fd, game);
		else
			is_valid_line(line, fd, game);
		free(line);
		rows++;
	}
	if (game->map.collectibles <= 0)
		error_msg("Error! Your map must have at least 1 collectible", game);
	else if (game->map.exit != 1)
		error_msg("Error! Your map must have only 1 exit", game);
	else if (game->map.player != 1)
		error_msg("Error! Your map must have only 1 player", game);
}
