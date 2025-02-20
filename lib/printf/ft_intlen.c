/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:49:03 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/20 11:01:03 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_intlen(long n, int bsize)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= bsize)
	{
		n = n / bsize;
		i++;
	}
	if (n < bsize)
		i++;
	return (i);
}
