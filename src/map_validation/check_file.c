/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:29:12 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/18 10:40:19 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_check_arg(int argc, char **argv, t_game *game)
{
	int	arg_len;

	game->map_alloc = 0;
	if (argc > 2)
		error_msg("Too many argument.", game);
	else if (argc < 2)
		error_msg("The map file is missing.", game);
	arg_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][arg_len - 4], ".ber", 4))
		error_msg("Wrong extension file. It should be .ber", game);
}

static void	file_exists(const char *filename, t_game *game, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		close(*fd);
		error_msg("The map cannot be opened.", game);
	}
}

static void	file_empty(int fd, t_game *game)
{
	int		b_read;
	char	buf[1];

	b_read = read(fd, buf, 1);
	if (b_read <= 0)
	{
		close(fd);
		error_msg("The file is empty.", game);
	}
	close(fd);
}

void	ft_check_file(const char *filename, t_game *game)
{
	int	fd;

	file_exists(filename, game, &fd);
	file_empty(fd, game);
	close(fd);
}
