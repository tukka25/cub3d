/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:35:38 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/11 17:41:46 by abdamoha         ###   ########.fr       */
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
	cub->img.img = mlx_new_image(cub->mlx.mlx, cub->m.width * 64,
				cub->m.height * 64);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	while (cub->map[y])
	{
		j = 0;
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S'
				|| cub->map[y][x] == 'W' || cub->map[y][x] == 'E')
			{
				// my_mlx_pixel_put(&cub->img, (int)((j + cub->move_x + 2) + cub->ray_c.pdx), (int)((i + cub->move_y - 1) + cub->ray_c.pdy), 0x0000FF00);
				// my_mlx_pixel_put(&cub->img, (int)((j + cub->move_x + 2) + cub->ray_c.pdx), (int)((i + cub->move_y - 2) + cub->ray_c.pdy), 0x0000FF00);
				// my_mlx_pixel_put(&cub->img, (int)((j + cub->move_x + 2) + cub->ray_c.pdx), (int)((i + cub->move_y - 3) + cub->ray_c.pdy), 0x0000FF00);
				// my_mlx_pixel_put(&cub->img, (int)((j + cub->move_x + 2) + cub->ray_c.pdx), (int)((i + cub->move_y - 4) + cub->ray_c.pdy), 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x, i + cub->move_y, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x + 1, i + cub->move_y, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x + 2, i + cub->move_y, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x + 3, i + cub->move_y, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x, i + cub->move_y + 1, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x + 1, i + cub->move_y + 1, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x + 2, i + cub->move_y + 1, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x + 3, i + cub->move_y + 1, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x, i + cub->move_y + 2, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x + 1, i + cub->move_y + 2, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x + 2, i + cub->move_y + 2, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + cub->move_x + 3, i + cub->move_y + 2, 0x0000FF00);
			}
			else if (cub->map[y][x] == '1')
			{
				draw_wall(cub, x, y);
			}
			x++;
			j += 64;
		}
		y++;
		i += 64;
	}
	cast_rays(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.mlx_win,
		cub->img.img, 0, 0);
}

void	render(t_cub *cub)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = 0;
	i = 0;
	j = 0;
	y = 0;
	while (cub->map[y])
	{
		j = 0;
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S'
				|| cub->map[y][x] == 'W' || cub->map[y][x] == 'E')
			{
				my_mlx_pixel_put(&cub->img, j, i, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + 1, i, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + 2, i, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j, i + 1, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + 1, i + 1, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + 2, i + 1, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j, i + 2, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + 1, i + 2, 0x0000FF00);
				my_mlx_pixel_put(&cub->img, j + 2, i + 2, 0x0000FF00);
			}
			x++;
			j += 64;
		}
		y++;
		i += 64;
	}
}

void	draw_wall(t_cub *cub, int x, int y)
{
	int		i;
	int		j;
	int		x1;
	int		y1;

	i = 0;
	j = 0;
	x1 = 0;
	y1 = 0;
	x1 = 64 * x;
	y1 = 64 * y;
	while (i < 63)
	{
		j = 0;
		x1 = 64 * x;
		while (j < 63)
		{
			my_mlx_pixel_put(&cub->img, x1, y1, 0xFFFFFF);
			j++;
			x1++;
		}
		i++;
		y1++;
	}
}
