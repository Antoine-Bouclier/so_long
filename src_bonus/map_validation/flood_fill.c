/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:41:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 13:18:33 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Recursively performs a flood fill to
 * validate the map's connectivity.
 *
 * This function recursively checks all adjacent cells
 * starting from a given point (x, y).
 * It marks visited cells with the character 'V' to 
 * avoid revisiting them. During the
 * traversal, it checks for specific elements on the map:
 * - If it encounters an exit (`EXIT`), it sets the exit
 * flag to 1.
 * - If it encounters a collectible (`COLLECTIBLE`),
 * it decreases the collectible count.
 * 
 * The function ensures that the path from the player's
 * starting position is connected 
 * to all other relevant map elements (exit and collectibles)
 * while avoiding walls (`WALL`).
 *
 * @param map Pointer to the map structure that holds
 * the map data.
 * @param x The x-coordinate of the current position
 * to start the flood fill from.
 * @param y The y-coordinate of the current position
 * to start the flood fill from.
 */
static void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->columns || y >= map->rows)
		return ;
	if (map->full[y][x] == WALL || map->full[y][x] == 'V'
		|| map->full[y][x] == MONSTER || map->full[y][x] == ROCK)
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

static void	add_pos(t_game *game, char current_char, t_position pos)
{
	if (current_char == PLAYER)
	{
		game->player_pos.x = pos.x;
		game->player_pos.y = pos.y;
	}
	if (current_char == EXIT)
	{
		game->exit_pos.x = pos.x;
		game->exit_pos.y = pos.y;
	}
}

/**
 * @brief Finds the positions of the player and
 * exit on the map.
 *
 * This function iterates through the entire map
 * to locate the positions of the player 
 * and the exit. When the player and exit are found,
 * their coordinates are stored 
 * in the `game` structure at the appropriate fields.
 *
 * @param game Pointer to the game structure that
 * contains the map and player/exit information.
 */
static void	position(t_game *game)
{
	t_position	pos;
	char		current_char;

	pos.y = 0;
	while (pos.y < game->map.rows)
	{
		pos.x = 0;
		while (pos.x < game->map.columns)
		{
			current_char = game->map.full[pos.y][pos.x];
			add_pos(game, current_char, pos);
			add_collectible(game, pos.y, pos.x, current_char);
			add_heart(game, pos.y, pos.x, current_char);
			add_monsters(game, pos.y, pos.x, current_char);
			pos.x++;
		}
		pos.y++;
	}
}

/**
 * @brief Creates a copy of the given map.
 *
 * This function allocates memory for a new map
 * and copies the content of the original map 
 * into it. It also initializes the new map's rows
 * and columns based on the provided height 
 * and width. If any memory allocation fails, the
 * function frees any allocated memory and 
 * returns `NULL`.
 *
 * @param original_map The original map to be copied.
 * @param height The number of rows in the original map.
 * @param width The number of columns in the original map.
 * 
 * @return A pointer to the newly created map, or
 * `NULL` if memory allocation fails.
 */
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

/**
 * @brief Validates the game map for correct
 * structure and connectivity.
 *
 * This function creates a copy of the map and uses a
 * flood-fill algorithm to check if 
 * all collectibles are reachable from the player's
 * starting position and if the exit is reachable. 
 * It sets the result to 1 if all collectibles are
 * collected and the exit is reached, otherwise it returns 0.
 * 
 * The function also frees the memory allocated for
 * the copied map before returning.
 *
 * @param game Pointer to the game structure that
 * contains the map and player information.
 * 
 * @return 1 if the map is valid (all collectibles
 * are collected and the exit is reached), 
 *         0 if the map is invalid (otherwise).
 */
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
	position(game);
	flood_fill(map, game->player_pos.x, game->player_pos.y);
	if (map->collectibles == 0 && map->exit == 1)
		result = 1;
	ft_free_map(map);
	free (map);
	return (result);
}
