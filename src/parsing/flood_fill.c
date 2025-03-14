/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:41:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/14 12:56:00 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->columns || y >= map->rows)
		return ;
	if (map->full[y][x] == WALL || map->full[y][x] == 'V')
		return ;
	if (map->full[y][x] == EXIT)
		map->exit = 1;
	if (map->full[y][x] == COLLECTIBLE)
		map->collectibles--;
	map->full[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static void	position_player(t_game *game)
{
	int		x;
	int		y;
	char	current_char;

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

static t_map	*copy_map(char **original_map, int height, int width)
{
	t_map	*new_map;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->full = malloc(sizeof(char *) * (height + 1));
	if (!new_map->full)
	{
		free(new_map);
		return (NULL);
	}
	new_map->rows = 0;
	new_map->columns = width;
	while (new_map->rows < height)
	{
		new_map->full[new_map->rows] = ft_strdup(original_map[new_map->rows]);
		if (!new_map->full[new_map->rows])
		{
			ft_free_map(new_map);
			return (NULL);
		}
		new_map->rows++;
	}
	new_map->full[height] = NULL;
	return (new_map);
}

int	validate_map(t_game *game)
{
	t_map	*map;
	int		result;

	result = 0;
	map = copy_map(game->map.full, game->map.rows, game->map.columns);
	if (!map)
		return (result);
	map->exit = 0;
	map->collectibles = game->map.collectibles;
	position_player(game);
	flood_fill(map, game->player.position.x, game->player.position.y);
	if (map->collectibles == 0 && map->exit == 1)
		result = 1;
	ft_free_map(map);
	free (map);
	return (result);
}
