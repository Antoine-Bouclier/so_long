/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:41:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:35 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	flood_fill(char **map, int x, int y, int *exit_found, int *collectible_count)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return;
	if (map[y][x] == 'E')
		*exit_found = 1;
	if (map[y][x] == 'C')
		(*collectible_count)--;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, exit_found, collectible_count);
	flood_fill(map, x - 1, y, exit_found, collectible_count);
	flood_fill(map, x, y + 1, exit_found, collectible_count);
	flood_fill(map, x, y - 1, exit_found, collectible_count);
}

static void	position_player(t_game *game)
{
	int x;
	int	y;
	char current_char;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			current_char = game->map.full[y][x];
			if (current_char == PLAYER)
			{
				game->player.position.x = x;
				game->player.position.y = y;
			}
			if (current_char == EXIT)
			{
				game->exit.position.x = x;
				game->exit.position.y = y;
			}
			x++;
		}
		y++;
	}
}

static char	**copy_map(char **original_map, int height)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < height) {
		map_copy[i] = ft_strdup(original_map[i]);
		if (!map_copy[i]) {
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[height] = NULL;
	return (map_copy);
}

int	validate_map(t_game *game)
{
	int		exit_found;
	int		collectible_found;
	char	**map;

	exit_found = 0;
	collectible_found = game->map.collectibles;
	map = copy_map(game->map.full, game->map.rows);
	position_player(game);
	flood_fill(map, game->player.position.x, game->player.position.y, &exit_found, &collectible_found);
	if (collectible_found == 0 && exit_found == 1)
		return (1);
	else
		return (0);
}