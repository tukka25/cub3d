/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:44:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/08 20:47:10 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_cub *cub)
{
	int	i;
	int	pos;

	i = 0;
	pos = cub->m.py_pix;
	int	a = 0;
	int	x1;
	int	y1;
	int	h = 0;

	x1 = cub->m.px_pix;
	y1 = cub->m.py_pix;
	printf("i = %c\n", cub->map[cub->m.py_pix / 64][cub->m.px_pix / 64]);
	a = rad_to_deg(cub->ray_c.angle, cub) - 30;
	float	d = 0;
	// printf("a = %d\n", a);
	while (h < 60)
	{
		x1 = cub->m.px_pix;
		y1 = cub->m.py_pix;
		d = deg_to_rad(a, cub);
		if (a == 0 || a == 360)
		{
			x1 += Speed * cos(d);
			while (1)
			{
				my_mlx_pixel_put(&cub->img, x1 + 2 , y1 + 5, 0xFF0000);
				x1++;
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
				
			}
		}
		if (a == 90)
		{
			x1 += Speed * cos(d);
			y1 -= Speed * sin(d);
			while (1)
			{
				my_mlx_pixel_put(&cub->img, x1 + 2 , y1 + 5, 0xFF0000);
				y1--;
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
			}
		}
		else if ((a > 0 && a < 90))
		{
			// printf("--------------\n");
			// printf("x1 in = %d\n", x1);
			// printf("y1 in = %d\n", y1);
			// printf("--------------\n");
			// printf("a = %d\n", a);
			while (1)
			{
				my_mlx_pixel_put(&cub->img, x1 + 2, y1 + 5, 0xFF0000);
				x1 += round(Speed * cos(d));
				y1 -= round(Speed * sin(d));
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
			}
		}
		else if (a > 90 && a < 180)
		{
			while (1)
			{
				i = 0;
				my_mlx_pixel_put(&cub->img, x1 + 2 , y1 + 5, 0xFF0000);
				// y1--;
				// x1--;
				x1 += round(Speed * cos(d));
				y1 -= round(Speed * sin(d));
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
				
			}
		} 
		else if (a > 180 && a < 270)
		{
			while (1)
			{
				i = 0;
				my_mlx_pixel_put(&cub->img, x1 + 2 , y1 + 5, 0xFF0000);
				// y1++;
				// x1--;
				x1 += round(Speed * cos(d));
				y1 -= round(Speed * sin(d));
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
				
			}
		}
		else if (a > 270 && a < 360)
		{
			while (1)
			{
				i = 0;
				my_mlx_pixel_put(&cub->img, x1 + 2 , y1 + 5, 0xFF0000);
				// y1++;
				// x1++;
				x1 += round(Speed * cos(d));
				y1 -= round(Speed * sin(d));
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
				
			}
		}
		else
			x1 += Speed;
		h++;
		a++;
	}
}

void	draw_line(t_cub *cub)
{
	(void)cub;
	// printf("arr = %d\n", arr[4]);
	// exit(0);
	// {
	// 	i = 0;
	// 	while (i < 64)
	// 	{
	// 		my_mlx_pixel_put(&cub->img, x1 + 2  + 64 * cos(d), y1 + 5 + 64 * sin(d), 0xFF0000);
	// 		i++;
	// 	}
	// 	if (cub->map[y1 / 64][x1 / 64] == '1')
	// 		break ;
	// }
	// (void)cub;
	// if (arr[0] < arr[2])
	// {
	// 	while (arr[0] < arr[2])
	// 	{
	// 		printf("i\n");
	// 		my_mlx_pixel_put(&cub->img, arr[0] , arr[1], 0xFF0000);
	// 		arr[0]++;
	// 	}
	// }
	// else
	// {
	// 	// int	g = 125;
	// 	int		f = cub->move_x;
	// 	int		n = cub->move_y;
	// 	int		d = arr[0];
	// 	while (arr[0] > arr[2] && arr[1] > 0)
	// 	{
	// 		// printf("a = %d\n", rad_to_deg(cub->ray_c.angle, cub))
	// 		f += cos(cub->ray_c.angle);
	// 		n += sin(cub->ray_c.angle);
	// 		my_mlx_pixel_put(&cub->img, d + f, arr[1] + n, 0xFF0000);
	// 		arr[0]--;
	// 		if (arr[1] > 0)
	// 			arr[1]--;
	// 		// g++;
	// 	}
	// }
}

void	check_horizontal(t_cub *cub)
{
	int	ys;
	int	xs;
	int	px;
	int	py;

	xs = 0;
	// int	i = 0;
	ys = 64;
	px = cub->m.px_pix;
	py = cub->m.py_pix;
	xs = 64 / tan(cub->ray_c.angle);
	// printf("kjh = %d\n", py - 64 / 64);
	// exit(0);;
	while ((cub->map[(py - ys) / 64][(px + xs) / 64] != '1' && 
	cub->map[(py - ys) / 64][(px + xs) / 64] != '\0'))
	{
		// printf("c = %c\n", cub->map[(py - 64) / 64][(px + xs) / 64]);
		// if (xs > 0 && py > 0)
			my_mlx_pixel_put(&cub->img, xs + px, py - ys, 0x0000FF);
			my_mlx_pixel_put(&cub->img, xs + px, py - ys - 1, 0x0000FF);
		ys += 64;
		xs += 64 / tan(cub->ray_c.angle);
	}
	check_vertical(cub);
}

void	check_vertical(t_cub *cub)
{
	int	ys;
	int	xs;
	int	px;
	int	py;

	xs = 64;
	px = cub->m.px_pix;
	py = cub->m.py_pix;
	ys = 64 / tan(cub->ray_c.angle);
	printf("ys = %d\n", ys);
	printf("c = %c\n", cub->map[(py + ys) / 64][(px + xs) / 64]);
	while (cub->map[(py + ys) / 64][(px + xs) / 64] != '\0' 
		&& cub->map[(py + ys) / 64][(px + xs) / 64] != '1')
		{
			my_mlx_pixel_put(&cub->img, xs + px, py - ys, 0xFF0000);
			my_mlx_pixel_put(&cub->img, xs + px, py - ys - 1, 0xFF0000);
			xs += 64;
			ys += 64 / tan(cub->ray_c.angle);
		}
}

				// int dx = abs(x2 - x1);
				// int dy = abs(y2 - y1);
				// int sx = x1 < x2 ? 1 : -1;
				// int sy = y1 < y2 ? 1 : -1;
				// int err = dx - dy;

				// while (x1 != x2 || y1 != y2) {
				// 	my_mlx_pixel_put(&cub->img, x1 + 2, y1 + 1, 0xFF0000);
				// 	int err2 = 2 * err;
					
				// 	if (err2 > -dy) {
				// 		err -= dy;
				// 		x1 += sx;
				// 	}
					
				// 	if (err2 < dx) {
				// 		err += dx;
				// 		y1 += sy;
				// 	}
				// }