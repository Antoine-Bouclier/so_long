/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:30:10 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/18 10:40:34 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	validate_line_walls(char *line, int *fd, t_game *game)
{
	if (line[0] != WALL || line[ft_strlen(line) - 2] != WALL)
	{
		close(*fd);
		error_msg("Your map must be surrounded by walls", game);
	}
}

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

void	is_valid_line(char *line, int *fd, t_game *game)
{
	validate_line_walls(line, fd, game);
	validate_line_characters(line, fd, game);
	validate_line_length(line, fd, game);
}
