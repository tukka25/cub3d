/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:54:17 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/21 23:16:32 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_is_valid_zero(int c, int y, int x, t_game *game)
{
	char	*tmp_pre;
	char	*tmp_next;

	tmp_pre = ft_strdup(game->map.map_2d[y - 1]);
	tmp_next = ft_strdup(game->map.map_2d[y + 1]);
	if (tmp_pre[ft_strlen(tmp_pre) - 1] == '\n')
		tmp_pre[ft_strlen(tmp_pre) - 1] = 0;
	if (tmp_next[ft_strlen(tmp_next) - 1] == '\n')
		tmp_next[ft_strlen(tmp_next) - 1] = 0;
	if (c == '0')
	{
		if (x + 1 > ft_strlen(tmp_pre) || x + 1 > ft_strlen(tmp_next))
		{
			free(tmp_pre);
			free(tmp_next);
			cu_print_error("Invalid map", game);
		}
	}
	free(tmp_pre);
	free(tmp_next);
	return ;
}

void	cu_save_player(int c, int y, int x, t_game *game)
{
	char		*tmp_pre;
	char		*tmp_next;
	static int	err;

	tmp_pre = ft_strdup(game->map.map_2d[y - 1]);
	tmp_next = ft_strdup(game->map.map_2d[y + 1]);
	if (tmp_pre[ft_strlen(tmp_pre) - 1] == '\n')
		tmp_pre[ft_strlen(tmp_pre) - 1] = 0;
	if (tmp_next[ft_strlen(tmp_next) - 1] == '\n')
		tmp_next[ft_strlen(tmp_next) - 1] = 0;
	if (game->map.p_direction)
		err = -1;
	game->map.p_x = x;
	if (x + 1 > ft_strlen(tmp_pre) || x + 1 > ft_strlen(tmp_next))
		err = -2;
	if (err == -1 || err == -2)
	{
		free(tmp_pre);
		free(tmp_next);
		cu_print_error("Invalid player", game);
	}
	game->map.p_y = y;
	game->map.p_direction = c;
	free(tmp_pre);
	free(tmp_next);
}

void	cu_check_line(int y, t_game *game)
{
	int	x;

	if (y != 0 || y != game->map.nline - 1)
		cu_check_edge(game->map.map_2d[y], game);
	x = 0;
	while (game->map.map_2d && game->map.map_2d[y][x])
	{
		cu_is_valid_character(y, game->map.map_2d[y][x], game);
		if (y != 0 && y != game->map.nline - 1)
			cu_is_valid_zero(game->map.map_2d[y][x], y, x, game);
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
