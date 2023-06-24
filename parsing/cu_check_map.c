/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:54:17 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/24 21:14:08 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_is_valid_zero(int c, int y, int x, t_cub *cub)
{
	char	*tmp_pre;
	char	*tmp_next;

	tmp_pre = ft_strdup(cub->game.map.map_2d[y - 1]);
	tmp_next = ft_strdup(cub->game.map.map_2d[y + 1]);
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
			cu_print_error("Invalid map", cub);
		}
	}
	free(tmp_pre);
	free(tmp_next);
	return ;
}

void	cu_save_player(int c, int y, int x, t_cub *cub)
{
	char		*tmp_pre;
	char		*tmp_next;
	static int	err;

	tmp_pre = ft_strdup(cub->game.map.map_2d[y - 1]);
	tmp_next = ft_strdup(cub->game.map.map_2d[y + 1]);
	if (tmp_pre[ft_strlen(tmp_pre) - 1] == '\n')
		tmp_pre[ft_strlen(tmp_pre) - 1] = 0;
	if (tmp_next[ft_strlen(tmp_next) - 1] == '\n')
		tmp_next[ft_strlen(tmp_next) - 1] = 0;
	if (cub->game.map.p_direction)
		err = -1;
	cub->game.map.p_x = x;
	if (x + 1 > ft_strlen(tmp_pre) || x + 1 > ft_strlen(tmp_next))
		err = -2;
	if (err == -1 || err == -2)
	{
		free(tmp_pre);
		free(tmp_next);
		cu_print_error("Invalid player", cub);
	}
	cub->game.map.p_y = y;
	cub->game.map.p_direction = c;
	free(tmp_pre);
	free(tmp_next);
}

void	cu_check_line(int y, t_cub *cub)
{
	int	x;

	if (y != 0 || y != cub->game.map.nline - 1)
		cu_check_edge(cub->game.map.map_2d[y], cub);
	x = 0;
	while (cub->game.map.map_2d && cub->game.map.map_2d[y][x])
	{
		cu_is_valid_character(y, cub->game.map.map_2d[y][x], cub);
		if (y != 0 && y != cub->game.map.nline - 1)
			cu_is_valid_zero(cub->game.map.map_2d[y][x], y, x, cub);
		cu_is_space(cub->game.map.map_2d[y][x], y, x, cub);
		if (cu_is_player(cub->game.map.map_2d[y][x]))
			cu_save_player(cub->game.map.map_2d[y][x], y, x, cub);
		x++;
	}
	return ;
}

void	cu_check_map(t_cub *cub)
{
	int	y;

	y = 0;
	while (cub->game.map.map_2d && cub->game.map.map_2d[y])
	{
		cu_check_line(y, cub);
		y++;
	}
	return ;
}

void	cu_get_width(t_cub *cub)
{
	int	y;

	y = 0;
	while(cub->game.map.map_2d[y])
	{
		if (ft_strlen(cub->game.map.map_2d[y]) > cub->game.map.map_width)
			cub->game.map.map_width = ft_strlen(cub->game.map.map_2d[y]);
		y++;
	}
	return ;
}