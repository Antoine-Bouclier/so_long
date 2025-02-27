/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:19:38 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/27 14:57:26 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	is_valid_line(char *line, int *fd, t_game *game)
{
	int	i;

	i = 0;
	if (line[0] != '1' || line[ft_strlen(line)] != '1')
	{
		close(fd);
		error_msg("Your map must be surrounded by walls", game);
	}
	while (line[i] != '\0')
	{
		if (line[i] )
	}
}

void	is_wall_line(char *line, int fd, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] != '\n' || line[i] != '\0')
	{
		if (line[i] != '1')
		{
			close(fd);
			error_msg("Your map must be surrounded by walls", game);
		}
		i++;
	}
}

void	ft_check_map(const char *filename, int *fd, t_game *game)
{
	char	*line;
	int		first_line;

	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		close(fd);
		error_msg("The map cannot be opened", game);
	}
	line = get_next_line(fd);
	is_wall_line(line, fd, game);
	free(line);
	while (line = get_next_line(fd))
	{
		if (line[ft_strlen(line)] == '\n')
			is_wall_line(line, fd, game);
		else
			is_valid_line(line, fd, game);
	}
}
