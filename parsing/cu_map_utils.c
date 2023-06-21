/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:56:32 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/21 18:43:01 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_check_space(int y, int x, t_game *game)
{
	if (y != 0)
		if (x <= ft_strlen(game->map.map_2d[y - 1])
			&& (game->map.map_2d[y - 1][x] == '0'
			|| cu_is_player(game->map.map_2d[y - 1][x])))
			cu_print_error("Invalid space", game);
	if (y != game->map.nline - 1)
		if (x <= ft_strlen(game->map.map_2d[y + 1])
			&& (game->map.map_2d[y + 1][x] == '0'
			|| cu_is_player(game->map.map_2d[y + 1][x])))
			cu_print_error("Invalid space", game);
	if (x != 0)
		if (game->map.map_2d[y][x - 1] == '0'
			|| cu_is_player(game->map.map_2d[y][x - 1]))
			cu_print_error("Invalid space", game);
	if (x != ft_strlen(game->map.map_2d[y]) - 1)
		if (game->map.map_2d[y][x + 1] == '0'
			|| cu_is_player(game->map.map_2d[y][x + 1]))
			cu_print_error("Invalide space", game);
	return ;
}

void	cu_check_edge(char *line, t_game *game)
{
	char	*tmp;

	tmp = cu_dup_and_trim(line);
	if (!tmp)
		cu_print_error("Invalid line", game);
	printf("tmp[0]: %c, tmp[last]: |%c|\n", tmp[0], tmp[ft_strlen(tmp) - 1]);
	if (tmp[0] != '1' || tmp[ft_strlen(tmp) - 1] != '1')
	{
		free(tmp);
		cu_print_error("Map must be surrounded by walls", game);
	}
	free(tmp);
	return ;
}

void	cu_is_valid_character(int y, int c, t_game *game)
{
	if (c != '1' && c != ' ' && c != '\n')
	{
		if (y != 0 || y != game->map.nline)
		{
			if (c != '0' && c != 'N' && c != 'S' && c != 'W' && c != 'E')
				cu_print_error("Invalid character", game);
		}
		if (y == 0 || y == game->map.nline)
			cu_print_error("Invalid character", game);
	}
	return ;
}

bool	cu_is_player(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

void	cu_is_space(int c, int y, int x, t_game *game)
{
	if (c == ' ')
		cu_check_space(y, x, game);
	return ;
}
