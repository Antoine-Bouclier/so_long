/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:40:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/20 17:47:44 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include "../lib/libft.h"

# define WALL			'1'
# define FLOOR			'0'
# define PLAYER			'P'
# define EXIT			'E'
# define COLLECTIBLE	'C'

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
	char	**full;
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

/* Core */
void	ft_check_arg(int argc, char **argv, t_game *game);

/* free memory */
void	ft_free_map(t_game *game);

/* Parsing */

/* Error */
void	error_msg(char *msg, t_game *game);

#endif