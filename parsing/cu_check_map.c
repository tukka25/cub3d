/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:54:17 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/08 12:40:15 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_save_player(int c, int y, int x, t_game *game)
{
	if (game->map.p_direction)
		cu_print_error("Duplicate player found", game);
	game->map.p_x = x;
	if ((y != 0 && x > ft_strlen(game->map.map_2d[y - 1]))
		|| (y != game->map.nline - 1
			&& x > ft_strlen(game->map.map_2d[y + 1])))
		cu_print_error("Invalid player position", game);
	game->map.p_y = y;
	game->map.p_direction = c;
}

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
		if (cu_is_player(game->map.map_2d[y][x]))
			cu_save_player(game->map.map_2d[y][x], y, x, game);
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
