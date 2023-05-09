/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:35:38 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/09 18:22:57 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	bb(t_cub *cub, char flag)
{
	int	k;
	int	f;
	int	n;
	int	s;
	int	i;
	int	j;

	k = 0;
	(void)flag;
	s = 64;
	i = cub->m.py_index;
	j = cub->m.px_index;
	f = i;
	n = j;
	while (cub->map[i][j] != '1' && cub->map[i][j])
	{
		while (s >= 0)
		{
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
				j, i * s, 0x00FF0000);
			s--;
		}
		i--;
		s = 64;
		k++;
	}
	k *= 64;
}

void	drawing(t_cub *cub)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = 0;
	i = 0;
	j = 0;
	y = 0;
	while (cub->map[x])
	{
		j = 0;
		y = 0;
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == 'N' || cub->map[x][y] == 'S'
				|| cub->map[x][y] == 'W' || cub->map[x][y] == 'E')
			{
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
					j, i, 0x0000FF00);
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
				j + 1, i, 0x0000FF00);
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
				j, i + 1, 0x0000FF00);
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
				j + 1, i + 1, 0x0000FF00);
				bb(cub, cub->map[x][y]);
			}
			y++;
			j += 64;
		}
		x++;
		i += 64;
	}
}

