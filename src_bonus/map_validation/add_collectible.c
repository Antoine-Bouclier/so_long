/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_collectible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:11:57 by abouclie          #+#    #+#             */
/*   Updated: 2025/03/28 13:18:18 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_collectible(t_game *game, int y, int x, char current_char)
{
	t_collectible	*new_collectible;
	t_collectible	*current;

	if (current_char != COLLECTIBLE)
		return ;
	new_collectible = malloc(sizeof(t_collectible));
	if (!new_collectible)
		error_msg("Memory allocation failed for collectible", game);
	new_collectible->position.x = x;
	new_collectible->position.y = y;
	new_collectible->next = NULL;
	if (!game->collectibles)
		game->collectibles = new_collectible;
	else
	{
		current = game->collectibles;
		while (current->next)
			current = current->next;
		current->next = new_collectible;
	}
}

void	add_heart(t_game *game, int y, int x, char current_char)
{
	t_collectible	*new_heart;
	t_collectible	*current;

	if (current_char != HEART)
		return ;
	new_heart = malloc(sizeof(t_collectible));
	if (!new_heart)
		error_msg("Memory allocation failed for heart", game);
	new_heart->position.x = x;
	new_heart->position.y = y;
	new_heart->next = NULL;
	if (!game->hearts)
		game->hearts = new_heart;
	else
	{
		current = game->hearts;
		while (current->next)
			current = current->next;
		current->next = new_heart;
	}
}
