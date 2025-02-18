/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:10:20 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/18 14:33:18 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;

	x = 50;
	y = 50;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1980, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x <= 100)
	{
		my_mlx_pixel_put(&img, x, 100, create_trgb(255, 100, 150, 200));
		x++;
	}
	while (y <= 100)
	{
		my_mlx_pixel_put(&img, 100, y, get_opposite(create_trgb(255, 100, 150, 200)));
		y++;
	}
	x = 100;
	y = 100;
	while (x >= 50)
	{
		my_mlx_pixel_put(&img, x, 50, create_trgb(255, 100, 150, 200));
		x--;
	}
	while (y >= 50)
	{
		my_mlx_pixel_put(&img, 50, y, add_shade(0.5, create_trgb(255, 100, 150, 200)));
		y--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}