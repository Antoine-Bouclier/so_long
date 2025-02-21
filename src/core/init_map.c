/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:29:12 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/21 11:11:47 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdio.h>

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

void	file_exists(const char *filename, t_game *game)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		error_msg("The map cannot be opened.", game);
	}
}