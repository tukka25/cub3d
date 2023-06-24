/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:56:32 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/24 20:52:21 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_check_space(int y, int x, t_cub *cub)
{
	if (y != 0)
		if (x <= ft_strlen(cub->game.map.map_2d[y - 1])
			&& (cub->game.map.map_2d[y - 1][x] == '0'
			|| cu_is_player(cub->game.map.map_2d[y - 1][x])))
			cu_print_error("Invalid space", cub);
	if (y != cub->game.map.nline - 1)
		if (x <= ft_strlen(cub->game.map.map_2d[y + 1])
			&& (cub->game.map.map_2d[y + 1][x] == '0'
			|| cu_is_player(cub->game.map.map_2d[y + 1][x])))
			cu_print_error("Invalid space", cub);
	if (x != 0)
		if (cub->game.map.map_2d[y][x - 1] == '0'
			|| cu_is_player(cub->game.map.map_2d[y][x - 1]))
			cu_print_error("Invalid space", cub);
	if (x != ft_strlen(cub->game.map.map_2d[y]) - 1)
		if (cub->game.map.map_2d[y][x + 1] == '0'
			|| cu_is_player(cub->game.map.map_2d[y][x + 1]))
			cu_print_error("Invalide space", cub);
	return ;
}

void	cu_check_edge(char *line, t_cub *cub)
{
	char	*tmp;

	tmp = cu_dup_and_trim(line);
	if (!tmp)
		cu_print_error("Invalid line", cub);
	if (tmp[0] != '1' || tmp[ft_strlen(tmp) - 1] != '1')
	{
		free(tmp);
		cu_print_error("Map must be surrounded by walls", cub);
	}
	free(tmp);
	return ;
}

void	cu_is_valid_character(int y, int c, t_cub *cub)
{
	if (c != '1' && c != ' ' && c != '\n')
	{
		if (y != 0 || y != cub->game.map.nline)
		{
			if (c != '0' && c != 'N' && c != 'S' && c != 'W' && c != 'E')
				cu_print_error("Invalid character", cub);
		}
		if (y == 0 || y == cub->game.map.nline)
			cu_print_error("Invalid character", cub);
	}
	return ;
}

bool	cu_is_player(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

void	cu_is_space(int c, int y, int x, t_cub *cub)
{
	if (c == ' ')
		cu_check_space(y, x, cub);
	return ;
}
