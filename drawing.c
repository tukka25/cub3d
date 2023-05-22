/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:35:38 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/22 13:25:05 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	bb(t_cub *cub, char flag)
// {
// 	int	k;
// 	int	f;
// 	int	n;
// 	int	s;
// 	int	i;
// 	int	w;
// 	int	j;

// 	k = 0;
// 	(void)flag;
// 	s = 64;
// 	i = cub->m.py_index;
// 	j = cub->m.px_index;
// 	f = i;
// 	n = j;
// 	w = j;
// 	while (cub->map[i][j] != '1' && cub->map[i][j])
// 	{
// 		while (s > 0)
// 		{
// 			if (i * 64 <= 64 || f * 64 <= 64)
// 				break ;
// 			mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 				n * 64 + s, f * 64 - s, 0x00FF0000);
// 			mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 				j * 64, i * 64 - s, 0x00FF0000);
// 			mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 				w * 64 - s, f * 64 - s, 0x00FF0000);
// 			s--;
// 		}
// 		if (i * 64 <= 64 || f * 64 <= 64)
// 				break ;
// 		n++;
// 		w--;
// 		f--;
// 		k++;
// 		i--;
// 		// f = i;
// 		s = 64;
// 	}
// 	// k--;
// 	// n--;
// 	// w++;
// 	// f++;
// 	k *= 64;
// 	n *= 64;
// 	w *= 64;
// 	while (s > 0)
// 	{
// 		// if (i * 64 <= 64 || f * 64 <= 64)
// 		// 	break ;
// 		mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 			6 * 64 + s, 64, 0x00FF0000);
// 		// mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 		// 	j * 64, i * 64 - s, 0x00FF0000);
// 		// mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 		// 	w * 64 - s, f * 64 - s, 0x00FF0000);
// 		s--;
// 	}
// 	s = 64;
// 	while (s > 0)
// 	{
// 		// if (i * 64 <= 64 || f * 64 <= 64)
// 		// 	break ;
// 		mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 			7 * 64 + s, 64, 0x00FF0000);
// 		// mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 		// 	j * 64, i * 64 - s, 0x00FF0000);
// 		// mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 		// 	w * 64 - s, f * 64 - s, 0x00FF0000);
// 		s--;
// 	}
// 	s = 64;
// 	while (s > 0)
// 	{
// 		// if (i * 64 <= 64 || f * 64 <= 64)
// 		// 	break ;
// 		mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 			8 * 64 + s, 64, 0x00FF0000);
// 		// mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 		// 	j * 64, i * 64 - s, 0x00FF0000);
// 		// mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 		// 	w * 64 - s, f * 64 - s, 0x00FF0000);
// 		s--;
// 	}
// 	s = 64;
// 	while (s > 0)
// 	{
// 		// if (i * 64 <= 64 || f * 64 <= 64)
// 		// 	break ;
// 		mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 			9 * 64 + s, 64, 0x00FF0000);
// 		// mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 		// 	j * 64, i * 64 - s, 0x00FF0000);
// 		// mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
// 		// 	w * 64 - s, f * 64 - s, 0x00FF0000);
// 		s--;
// 	}
// 	cub->m.dir_len = k;
// 	cub->m.cam_plane = n - w;
// 	printf("len to wall = %d\n", cub->m.dir_len);
// 	printf("len to wall = %d\n", n - w);
// 	// printf("len to wall = %d\n", f);
// 	// printf("len to wall = %d\n", w);
// }

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
					j + 2, i, 0x0000FF00);
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
					j, i + 1, 0x0000FF00);
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
					j + 1, i + 1, 0x0000FF00);
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
					j + 2, i + 1, 0x0000FF00);
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
					j, i + 2, 0x0000FF00);
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
					j + 1, i + 2, 0x0000FF00);
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.mlx_win,
					j + 2, i + 2, 0x0000FF00);
				// bb(cub, cub->map[x][y]);
			}
			y++;
			j += 64;
		}
		x++;
		i += 64;
	}
}

