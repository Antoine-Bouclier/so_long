/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:40:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/27 15:37:31 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define IMG_HEIGHT		'32'
# define IMG_WIDTH		'32'

# define WALL			'1'
# define FLOOR			'0'
# define PLAYER			'P'
# define EXIT			'E'
# define COLLECTIBLE	'C'

# define W				'119'
# define A				'97'
# define D				'115'
# define S				'100'

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

/* Initialization */
void	ft_check_file(const char *filename, t_game *game);
void	ft_check_map(const char *filename, int *fd, t_game *game);

/* Error */
void	error_msg(char *msg, t_game *game);

/* Parsing */
void init_map(const char* filename, t_game *game);

#endif