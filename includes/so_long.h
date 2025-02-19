/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:40:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/19 14:36:13 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

typedef struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct	s_image
{
	void		*xpm_ptr;
	t_position	position;
}				t_image;

typedef struct	s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		collectibles;
	int		collected;
	int		exit;
	int		player;
}				t_map;

typedef struct	s_game
{
	int			width;
	int			height;
	int			moves;
	int			game_state;
	int			error;
	int			map_alloc;
	void		*mlx;
	void		*win;
	t_image		player_img;
	t_image		wall_img;
	t_image		collectible_img;
	t_image		exit_img;
	t_map		map;
}				t_game;

/* Protoypes */

/* Parsing */

/* Error */
void	error_msg(char *msg, t_game game);

#endif