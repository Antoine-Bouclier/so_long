/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:19:38 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/22 15:55:15 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	ft_rectangular_map(char *line, int size)
{

}

void	ft_check_map(int fd, t_game *game)
{
	char	*line;
	int		i;
	int		size;

	size = 0;
	i = 1;
	while (i <= 3)
	{
		line = get_next_line(fd);
		size = ft_strlen(line);
		ft_printf("line %d: %ssize: %d\n", i, line, size);
		i++;
	}
}
