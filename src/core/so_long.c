/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:25:48 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/14 12:33:54 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

static int	main_loop(t_game *game)
{
	draw_map(game);
	return (0);
}

static void	win_map(t_game *game)
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

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game)
	{
		ft_memset(game, 0, sizeof(t_game));
		game->mlx = NULL;
		game->win = NULL;
	}
	ft_check_arg(argc, argv, game);
	ft_check_file(argv[1], game);
	init_map(argv[1], game);
	if (validate_map(game) == 0)
		error_msg("Collectible or exit is not accessible.", game);
	win_map(game);
}
