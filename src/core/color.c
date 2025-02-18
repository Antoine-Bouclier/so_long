/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:07:06 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/18 14:33:06 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int	get_opposite(int	trgb)
{
	unsigned char	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	t = get_t(trgb);
	r = 255 - get_r(trgb);
	g = 255 - get_g(trgb);
	b = 255 - get_b(trgb);
	return (create_trgb(t, r, g, b));
}

int	add_shade(double shade, int trgb)
{
	unsigned char 	r;
	unsigned char	g;
	unsigned char 	b;

	if (shade <= 0)
		return trgb;
	if (shade >= 1)
		return create_trgb(get_t(trgb), 0, 0, 0);
	r = get_r(trgb) * (1 - shade);
	g = get_g(trgb) * (1 - shade);
	b = get_b(trgb) * (1 - shade);
	return (create_trgb(get_t(trgb), r, g, b));
}