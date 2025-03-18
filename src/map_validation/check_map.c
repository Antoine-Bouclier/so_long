/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:19:38 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/18 10:40:24 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

void	check_map_size(t_game *game)
{
	int	screen_width;
	int	screen_height;

	(void)mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	if ((game->map.columns * 32) > screen_width
		|| (game->map.rows * 32) + 64 > screen_height)
		error_msg("Map is larger than screen size", game);
}
