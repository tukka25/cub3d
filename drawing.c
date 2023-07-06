/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:35:38 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/07 01:34:55 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawing(t_cub *cub)
{
	// // int		i;
	// // int		j;
	// int		x;
	// int		y;

	// x = 0;
	// // i = 0;
	// // j = 0;
	// y = 0;
	cub->img.img = mlx_new_image(cub->mlx.mlx, WIDTH,
				HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	// while (cub->game.map.map_2d[y])
	// {
	// 	// j = 0;
	// 	x = 0;
	// 	while (cub->game.map.map_2d[y][x])
	// 	{
	// 		if (cub->game.map.map_2d[y][x] == 'N' || cub->game.map.map_2d[y][x] == 'S'
	// 			|| cub->game.map.map_2d[y][x] == 'W' || cub->game.map.map_2d[y][x] == 'E')
	// 		{
	// 			// my_mlx_pixel_put(&cub->img, (int)((j + cub->game.map.px_pix + 2) + cub->ray_c.pdx), (int)((i + cub->move_y - 1) + cub->ray_c.pdy), 0x0000FF00);
	// 			// my_mlx_pixel_put(&cub->img, (int)((j + cub->game.map.px_pix + 2) + cub->ray_c.pdx), (int)((i + cub->move_y - 2) + cub->ray_c.pdy), 0x0000FF00);
	// 			// my_mlx_pixel_put(&cub->img, (int)((j + cub->game.map.px_pix + 2) + cub->ray_c.pdx), (int)((i + cub->move_y - 3) + cub->ray_c.pdy), 0x0000FF00);
	// 			// my_mlx_pixel_put(&cub->img, (int)((j + cub->game.map.px_pix + 2) + cub->ray_c.pdx), (int)((i + cub->move_y - 4) + cub->ray_c.pdy), 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix, cub->game.map.py_pix, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix + 1, cub->game.map.py_pix, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix + 2, cub->game.map.py_pix, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix + 3, cub->game.map.py_pix, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix, cub->game.map.py_pix + 1, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix + 1, cub->game.map.py_pix + 1, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix + 2, cub->game.map.py_pix + 1, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix + 3, cub->game.map.py_pix + 1, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix, cub->game.map.py_pix + 2, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix + 1, cub->game.map.py_pix + 2, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix + 2, cub->game.map.py_pix + 2, 0x0000FF00);
	// 			my_mlx_pixel_put(cub, cub->game.map.px_pix + 3, cub->game.map.py_pix + 2, 0x0000FF00);
	// 			cub->game.map.map_2d[y][x] = '0';
	// 		}
	// 		else if (cub->game.map.map_2d[y][x] == '1')
	// 		{
	// 			// j++;
	// 			draw_wall(cub, x, y);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
	// draw_floor_ceiling(cub, 0xADD8E6, 0x012231);
	cast_rays(cub);
	// printf("d = %d\n", j);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.mlx_win,
		cub->img.img, 0, 0);
}

void	draw_wall(t_cub *cub, int x, int y)
{
	int		i;
	int		j;
	int		x1;
	int		y1;

	i = 0;
	j = 0;
	x1 = x * 64;
	y1 = y * 64;
	while (i < 63)
	{
		j = 0;
		x1 = x * 64;
		while (j < 63)
		{
			my_mlx_pixel_put(cub, x1, y1, 0xFFFFFF);
			j++;
			x1++;
		}
		i++;
		y1++;
	// return;
	}
}
