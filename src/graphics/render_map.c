/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:42:45 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/19 07:15:09 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Displays an image in the window based on the map character.
 *
 * This function places the appropriate image at coordinates
 * (x, y) in the window
 * based on the character representing a game element
 * (player, wall, floor, etc.).
 *
 * @param game Pointer to the game structure containing
 * graphical resources.
 * @param current_char Character representing the element
 * to be displayed.
 * @param x X-coordinate (column) where the image should
 * be displayed.
 * @param y Y-coordinate (row) where the image should be displayed.
 */
static void	img_to_win(t_game *game, char current_char, int x, int y)
{
	if (current_char == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img.xpm_ptr, x * 32, y * 32);
	else if (current_char == FLOOR)
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor_img.xpm_ptr, x * 32, y * 32);
	else if (current_char == WALL)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img.xpm_ptr, x * 32, y * 32);
	else if (current_char == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img.xpm_ptr, x * 32, y * 32);
	else if (current_char == EXIT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img.xpm_ptr, x * 32, y * 32);
}

/**
 * @brief Draws the game map by placing the appropriate
 * images in the window.
 *
 * This function iterates through the game map and calls
 * `img_to_win` to display
 * the corresponding image for each map character at its
 * respective position.
 *
 * @param game Pointer to the game structure containing
 * the map and graphical resources.
 */
static void	draw_map(t_game *game)
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
			img_to_win(game, current_char, x, y);
			x++;
		}
		y++;
	}
}

/**
 * @brief Main game loop function.
 *
 * This function is called continuously to update the
 * game window by redrawing the map.
 *
 * @param game Pointer to the game structure containing
 * the map and graphical resources.
 * @return Always returns 0.
 */
static int	main_loop(t_game *game)
{
	draw_map(game);
	return (0);
}

/**
 * @brief Initializes and displays the game window.
 *
 * This function sets up the game window, initializes
 * graphical resources, and 
 * registers event hooks for key presses and window closing.
 * It then enters the 
 * main event loop.
 *
 * @param game Pointer to the game structure containing
 * the map and graphical resources.
 */
void	win_map(t_game *game)
{
	game->mlx = mlx_init();
	check_map_size(game);
	game->height = game->map.rows * 32;
	game->width = game->map.columns * 32;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	set_img(game);
	mlx_loop_hook(game->mlx, (int (*)(void *))main_loop, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}
