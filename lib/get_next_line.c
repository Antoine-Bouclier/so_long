/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:06 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/20 08:54:49 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_nextl(char *nextl)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (nextl[i] && nextl[i] != '\n')
		i++;
	if (nextl[i] == '\n')
		i++;
	while (nextl[i + j])
	{
		nextl[j] = nextl[i + j];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		nextl[j] = '\0';
		j++;
	}
}

static ssize_t	check_line(char *line)
{
	ssize_t	i;

	i = 0;
	if (ft_strlen(line + i) == 0)
		return (-1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

static char	*fill_line(char *line, char *nextl, int fd)
{
	char	*tmp;
	ssize_t	b_read;

	b_read = 1;
	while (b_read && check_line(line) == -1)
	{
		b_read = read(fd, nextl, BUFFER_SIZE);
		if (b_read == 0)
			break ;
		nextl[b_read] = '\0';
		if (b_read < 0)
		{
			ft_bzero(nextl, BUFFER_SIZE);
			return (free(line), NULL);
		}
		tmp = line;
		line = ft_strjoin(line, nextl, b_read);
		free(tmp);
		if (!line)
			return (NULL);
	}
	if (b_read == 0 && !line[0])
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	nextl[BUFFER_SIZE + 1] = "\0";
	char		*line;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(nextl);
	if (!line)
		return (free(line), NULL);
	line = fill_line(line, nextl, fd);
	if (line == NULL)
		return (NULL);
	set_nextl(nextl);
	result = ft_strccpy(line);
	return (free(line), result);
}

