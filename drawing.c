/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:35:38 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/26 19:27:18 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	cub->img.img = mlx_new_image(cub->mlx.mlx, WIDTH,
				HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	// while (cub->game.map.map_2d[y])
	// {
	// 	j = 0;
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
	// 	// i += cub->game.map.scale_y;
	// }
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
	x1 = x * cub->game.map.scale_x;
	y1 = y * cub->game.map.scale_y;
	while (i < cub->game.map.scale_y - 1)
	{
		j = 0;
		x1 = x * cub->game.map.scale_x;
		while (j < cub->game.map.scale_x - 1)
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
