/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:25:48 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/06 15:22:48 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void draw_map(t_game *game)
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
			if (current_char == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img.xpm_ptr, x * 32, y * 32);
			else if (current_char == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_img.xpm_ptr, x * 32, y * 32);
			else if (current_char == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img.xpm_ptr, x * 32, y * 32);
			else if (current_char == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible_img.xpm_ptr, x * 32, y * 32);
			else if (current_char == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img.xpm_ptr, x * 32, y * 32);
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
	game->height = game->map.rows * 32;
	game->width = game->map.columns * 32;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	set_img(game);
	mlx_loop_hook(game->mlx, main_loop, &game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_check_arg(argc, argv, game);
	ft_check_file(argv[1], game);
	init_map(argv[1], game);
	win_map(game);
}
