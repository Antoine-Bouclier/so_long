/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:40:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/04/08 13:25:05 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

# define IMG_HEIGHT		32
# define IMG_WIDTH		32

# define WALL			'1'
# define FLOOR			'0'
# define PLAYER			'P'
# define EXIT			'E'
# define COLLECTIBLE	'C'
# define MONSTER		'M'
# define PROJECTILE		'A'
# define ROCK			'R'
# define HEART			'H'

# define W				119
# define A				97
# define D				100
# define S				115
# define ESC			65307

# define UP				0
# define RIGHT			1
# define DOWN			2
# define LEFT			3

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_image
{
	void		*xpm_ptr;
	char		*img;
}				t_image;

typedef struct s_collectible
{
	t_position				position;
	struct s_collectible	*next;
}				t_collectible;

typedef struct s_enemy
{
	t_position		position;
	t_position		next_pos;
	int				direction;
}				t_enemy;

typedef struct s_enemy_list
{
	t_enemy				*monster;
	t_enemy				*projectile;
	struct s_enemy_list	*next;
}				t_enemy_list;

typedef struct s_map
{
	char	**full;
	int		rows;
	int		columns;
	int		collectibles;
	int		heart;
	int		heart_collected;
	int		exit;
	int		player;
	int		first_line;
}				t_map;

typedef struct s_img
{
	t_image			monster_with_axe[4];
	t_image			monster_without_axe[4];
	t_image			projectile[4];
	t_image			collectible;
	t_image			player_on_exit;
	t_image			wall;
	t_image			floor;
	t_image			player;
	t_image			exit;
	t_image			rock;
	t_image			heart_floor;
	t_image			heart_wall;
	t_image			double_projectile;
}				t_img;

typedef struct s_game
{
	int				width;
	int				height;
	int				img_width;
	int				img_height;
	unsigned int	moves;
	int				map_alloc;
	void			*mlx;
	void			*win;
	t_enemy_list	*enemy;
	t_collectible	*collectibles;
	t_collectible	*hearts;
	t_position		player_pos;
	t_position		exit_pos;
	t_img			images;
	t_map			map;
}					t_game;

/* Protoypes */

/* Core */
int		main(int argc, char **argv);

/* Graphics */
void	win_map(t_game *game);
void	set_img(t_game *game);
void	img_to_win_bonus(t_game *game, char current_char, int x, int y);
void	is_xpm_failed(char *img, t_game *game);

/* Map loader */

	/* Init map */
void	init_map(const char *filename, t_game *game);

/* Map validation */

	/* Add_collectible */
void	add_collectible(t_game *game, int y, int x, char current_char);
void	add_heart(t_game *game, int y, int x, char current_char);

	/* Check file */
void	ft_check_arg(int argc, char **argv, t_game *game);
void	ft_check_file(const char *filename, t_game *game);

	/* Check map */
void	ft_check_map(const char *filename, int *fd, t_game *game);
void	check_map_size(t_game *game);

	/* Flood fill */
int		validate_map(t_game *game);

	/* is valid line */
void	is_valid_line(char *line, int *fd, t_game *game);

/* Player movement */

	/* Movement actions */
void	move_to_floor(t_game *game, t_position *current, t_position *next);
void	move_to_exit(t_game *game, t_position *current, t_position *next);

	/* Player movement */
int		key_press(int keycode, t_game *game);

	/* Utils */
void	remove_projectile(t_game *game, t_position next);

/* Utils */

	/* Close game */
int		close_window(t_game *game);

	/* Error */
void	error_msg(char *msg, t_game *game);

	/* Free_memory */
void	ft_free_map(t_map *map);
void	ft_free_all_memory(t_game *game);
void	ft_free_projectile(t_enemy_list *monster);

	/* Mlx_destroy_img */
void	ft_destroy_img(t_game *game);

/* PROJECTILES */
void	get_direction(t_enemy *enemy, t_position player, t_position monster);
void	handle_projectile(t_game *game);
void	add_monsters(t_game *game, int y, int x, char current);
void	set_img_bonus(t_game *game);
void	sprite_path_bonus(t_game *game);
void	handle_heart(t_game *game, t_enemy_list *monster);
int		was_collectible(t_collectible *collectible, t_enemy_list *monster);
void	update_projectiles(t_game *game, t_enemy_list *monster,
			int collectible, int heart);

#endif