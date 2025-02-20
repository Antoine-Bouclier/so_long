/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:29:12 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/20 08:59:56 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_check_arg(int argc, char **argv, t_game *game)
{
	int	arg_len;

	arg_len = ft_strlen(argv[1]);
	if (argc > 2)
		error_msg("Error! Too many argument.", game);
	else if (argc < 2)
		error_msg("Error! The map file is missing", game);
	if (!ft_strnstr(&argv[1][arg_len - 4], ".ber", 4))
		error_msg("Error! Wrong extension file. It should be .ber", game);
}