/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:40:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/12 13:20:30 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define IMG_HEIGHT		32
# define IMG_WIDTH		32

# define WALL			'1'
# define FLOOR			'0'
# define PLAYER			'P'
# define EXIT			'E'
# define COLLECTIBLE	'C'

# define W				119
# define A				97
# define D				100
# define S				115
# define ESC			65307

typedef struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct	s_image
{
	void		*xpm_ptr;
	char		*img;
}				t_image;

typedef struct	s_entity
{
	t_image		img;
	t_position	position;
}				t_entity;

typedef struct	s_map
{
	char	**full;
	int		rows;
	int		columns;
	int		collectibles;
	int		exit;
	int		player;
}				t_map;

typedef struct	s_game
{
	int			width;
	int			height;
	int			img_width;
	int			img_height;
	int			moves;
	int			game_state;
	int			error;
	int			map_alloc;
	void		*mlx;
	void		*win;
	t_entity	player;
	t_entity	exit;
	t_image		wall_img;
	t_image		collectible_img;
	t_image		floor_img;
	t_map		map;
}				t_game;

/* Protoypes */

/* Core */
void	ft_check_arg(int argc, char **argv, t_game *game);
int		key_press(int keycode, t_game *game);
void	move_to_floor(t_game *game, t_position *current, t_position *next);
void	move_to_exit(t_game *game, t_position *current, t_position *next);
void	check_map_size(t_game *game);
int		close_window(t_game *game);

/* Parsing */

/* Initialization */
void	ft_check_file(const char *filename, t_game *game);
void	ft_check_map(const char *filename, int *fd, t_game *game);

/* Error */
void	error_msg(char *msg, t_game *game);

/* Free memory */
void	ft_free_all_memory(t_game *game);
void	ft_free_map(t_map *map);
void	gnl_cleanup(int fd);

/* Parsing */
void	init_map(const char* filename, t_game *game);
void	ft_check_map(const char *filename, int *fd, t_game *game);
void	set_img(t_game *game);
int		validate_map(t_game *game);

#endif