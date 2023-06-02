/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:54:17 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/02 19:59:39 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_check_line(int y, t_game *game)
{
	int	x;

	if (y != 0 || y != game->map.nline)
		cu_check_edge(game->map.map_2d[y], game);
	x = 0;
	while (game->map.map_2d && game->map.map_2d[y][x])
	{
		cu_is_valid_character(y, game->map.map_2d[y][x], game);
		cu_is_space(game->map.map_2d[y][x], y, x, game);
		cu_is_player(game->map.map_2d[y][x], y, x, game);
		x++;
	}
	return ;
}

void	cu_check_map(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map_2d && game->map.map_2d[y])
	{
		cu_check_line(y, game);
		y++;
	}
	return ;
}
