/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:42:45 by abouclie          #+#    #+#             */
/*   Updated: 2025/04/01 10:37:35 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	{
		if (y == game->exit_pos.y && x == game->exit_pos.x)
			mlx_put_image_to_window(game->mlx, game->win,
				game->images.player_on_exit.xpm_ptr, x * 32, y * 32);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->images.player.xpm_ptr, x * 32, y * 32);
	}
	else if (current_char == FLOOR)
		mlx_put_image_to_window(game->mlx, game->win,
			game->images.floor.xpm_ptr, x * 32, y * 32);
	else if (current_char == WALL)
		mlx_put_image_to_window(game->mlx, game->win,
			game->images.wall.xpm_ptr, x * 32, y * 32);
	else if (current_char == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win,
			game->images.collectible.xpm_ptr, x * 32, y * 32);
	else if (current_char == EXIT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->images.exit.xpm_ptr, x * 32, y * 32);
	else
		img_to_win_bonus(game, current_char, x, y);
}

static void	draw_first_line(t_game *game, t_position *pos, char current_char)
{
	int	i;

	i = 0;
	while (pos->x < game->map.columns)
	{
		if (i < game->map.heart_collected && pos->x >= 2)
		{
			mlx_put_image_to_window(game->mlx, game
				->win, game->images.heart_wall.xpm_ptr, pos
				->x * 32, pos->y * 32);
			i++;
		}
		else
			img_to_win(game, current_char, pos->x, pos->y);
		current_char = game->map.full[pos->y][pos->x];
		pos->x++;
	}
	pos->y++;
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
	t_position	pos;
	char		current_char;

	pos.y = 0;
	while (pos.y < game->map.rows)
	{
		pos.x = 0;
		current_char = game->map.full[pos.y][pos.x];
		if (pos.y == 0)
			draw_first_line(game, &pos, current_char);
		pos.x = 0;
		while (pos.x < game->map.columns)
		{
			current_char = game->map.full[pos.y][pos.x];
			img_to_win(game, current_char, pos.x, pos.y);
			pos.x++;
		}
		pos.y++;
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
	static int	frame_counter = 0;
	char		*move_count;
	char		*display_text;

	frame_counter++;
	if (frame_counter >= 100)
	{
		frame_counter = 0;
		handle_projectile(game);
	}
	draw_map(game);
	move_count = ft_itoa(game->moves);
	display_text = ft_strjoin("Moves: ", move_count);
	free(move_count);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xF4EDDE, display_text);
	mlx_string_put(game->mlx, game->win, 11, 20, 0xF4EDDE, display_text);
	mlx_string_put(game->mlx, game->win, 10, 21, 0xF4EDDE, display_text);
	mlx_string_put(game->mlx, game->win, 11, 21, 0xF4EDDE, display_text);
	free(display_text);
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
	if (!game->mlx)
		error_msg("mlx_init failed.", game);
	check_map_size(game);
	game->height = game->map.rows * 32;
	game->width = game->map.columns * 32;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	if (!game->win)
		error_msg("mlx_new_window failed.", game);
	set_img(game);
	mlx_loop_hook(game->mlx, (int (*)(void *))main_loop, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}
