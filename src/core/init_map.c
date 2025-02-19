/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:29:12 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/19 15:33:57 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_check_arg(int argc, char **argv, t_game game)
{
	if (argc > 2)
		error_msg("Error! Too many argument.", game);
	else if (argc < 2)
		error_msg("Error! The map file is missing", game);
	/* else if (file is not .xpm) */
}