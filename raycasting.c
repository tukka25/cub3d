/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:44:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/11 18:47:41 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_cub *cub)
{
	int	i;
	int	pos;

	i = 0;
	pos = cub->m.py_pix;
	float 	a = 0;
	int	x1;
	int	y1;
	int	h = 0;
	int *arr = malloc(4 * sizeof(int));
	// arr[0] = 0;
	// arr[1] = 0;
	// arr[2] = 100;
	// arr[3] = (cub->m.height * 64) - 100;
	// int	arr[4];

	x1 = cub->m.px_pix;
	y1 = cub->m.py_pix;
	printf("i = %c\n", cub->map[cub->m.py_pix / 64][cub->m.px_pix / 64]);
	// a = rad_to_deg(cub->ray_c.angle, cub) - 45;
	a = cub->ray_c.angle - deg_to_rad(45, cub);
	// float s = rad_to_deg(cub->ray_c.angle, cub);
	if (a < 0)
		a += 360;
	// float	d = 0;
	// int arr[4] = {0, 0, (cub->m.height * 64) - 100, 100};
	// int *arr = malloc(5 * sizeof(int));
	while (h < cub->m.width * 64)
	{
		x1 = cub->m.px_pix;
		y1 = cub->m.py_pix;
		// d = cub->pi * a / 180.0;
		if (a == 0 || a == M_PI)
		{
			x1 += round(Speed * cos(a));
			while (1)
			{
				x1++;
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
				
			}
			cub->ray_c.ray_length = sqrt((x1 - cub->m.px_pix) * (x1 - cub->m.px_pix)
							+ (y1 - cub->m.py_pix) * (y1 - cub->m.py_pix));
			cub->ray_c.wall_length = (64 / cub->ray_c.ray_length) * 100;
			// printf("length = %f\n", cub->ray_c.wall_length);
			// while (i < cub->m.width * 64)
			// {
			// 	arr[3] = cub->ray_c.wall_length;
				arr[0] = cub->m.px_pix;
				arr[1] = x1;
				arr[2] = cub->m.py_pix;
				arr[3] = y1;
				draw_line(cub, arr, 0x00FF00);
			// 	arr[0]++;
			// 	arr[1]++;
			// 	i++;
			// }
		}
		if (a == M_PI / 2)
		{
			x1 += round(Speed * cos(a));
			y1 -= round(Speed * sin(a));
			while (1)
			{
				y1--;
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
			}
			cub->ray_c.ray_length = sqrt((x1 - cub->m.px_pix) * (x1 - cub->m.px_pix)
							+ (y1 - cub->m.py_pix) * (y1 - cub->m.py_pix));
			cub->ray_c.wall_length = (64 / cub->ray_c.ray_length) * 100;
			// printf("length = %f\n", cub->ray_c.wall_length);
			arr[0] = cub->m.px_pix;
				arr[1] = x1;
				arr[2] = cub->m.py_pix;
				arr[3] = y1;
				draw_line(cub, arr, 0x00FF00);
		}
		else if ((a > 0 && a < M_PI / 2))
		{
			while (1)
			{
				x1 += round(Speed * cos(a));
				y1 -= round(Speed * sin(a));
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
			}
			// check_horizontal(cub);
			// check_vertical(cub);
			cub->ray_c.ray_length = sqrt((x1 - cub->m.px_pix) * (x1 - cub->m.px_pix)
							+ (y1 - cub->m.py_pix) * (y1 - cub->m.py_pix));
			cub->ray_c.wall_length = (64 / cub->ray_c.ray_length) * 100;
			// cub->ray_c.wall_length = (64 * cub->m.height) / cub->ray_c.ray_length;
			// printf("length = %f\n", cub->ray_c.ray_length);
			// printf("length = %f\n", cub->ray_c.wall_length);
			arr[0] = cub->m.px_pix;
				arr[1] = x1;
				arr[2] = cub->m.py_pix;
				arr[3] = y1;
				draw_line(cub, arr, 0x00FF00);
			// int arr[4] = {0, 0, 100, (cub->m.height * 64) - 100};
			// while (i < cub->m.width * 64)
			// {
			// 	// if (cub->ray_c.ray_length < 100)
			// 	arr[3] = cub->ray_c.wall_length;
			// 	draw_line(cub, arr, 0x00FF00);
			// 	arr[0]++;
			// 	arr[1]++;
			// 	i++;
			// }
			// return ;
		}
		else if (a > M_PI / 2 && a < M_PI)
		{
			while (1)
			{
				x1 += round(Speed * cos(a));
				y1 -= round(Speed * sin(a));
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
			}
			cub->ray_c.ray_length = sqrt((x1 - cub->m.px_pix) * (x1 - cub->m.px_pix)
							+ (y1 - cub->m.py_pix) * (y1 - cub->m.py_pix));
			cub->ray_c.wall_length = (64 / cub->ray_c.ray_length) * 100;
			// printf("length = %f\n", cub->ray_c.wall_length);
			arr[0] = cub->m.px_pix;
				arr[1] = x1;
				arr[2] = cub->m.py_pix;
				arr[3] = y1;
				draw_line(cub, arr, 0x00FF00);
			// if (cub->ray_c.wall_length > cub->m.height * 64)
			// {
			// 	cub->ray_c.wall_length = (cub->m.height * 64) - 100;
			// }
			// while (i < cub->m.width * 64)
			// {
			// 	arr[3] = cub->ray_c.wall_length;
			// 	draw_line(cub, arr, 0x00FF00);
			// 	arr[0]++;
			// 	arr[1]++;
			// 	i++;
			// }
		} 
		else if (a > M_PI && a < 3 * M_PI / 2)
		{
			while (1)
			{
				// i = 0;
				// my_mlx_pixel_put(&cub->img, x1 + 2 , y1 + 5, 0x00FF00);
				// y1++;
				// x1--;
				x1 += round(Speed * cos(a));
				y1 -= round(Speed * sin(a));
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
			}
			cub->ray_c.ray_length = sqrt((x1 - cub->m.px_pix) * (x1 - cub->m.px_pix)
							+ (y1 - cub->m.py_pix) * (y1 - cub->m.py_pix));
			cub->ray_c.wall_length = (64 / cub->ray_c.ray_length) * 100;
			// printf("length = %f\n", cub->ray_c.wall_length);
			arr[0] = cub->m.px_pix;
				arr[1] = x1;
				arr[2] = cub->m.py_pix;
				arr[3] = y1;
				draw_line(cub, arr, 0x00FF00);
			// while (i < cub->m.width * 64)
			// {
			// 	arr[3] = cub->ray_c.wall_length - 100;
			// 	draw_line(cub, arr, 0x00FF00);
			// 	arr[0]++;
			// 	arr[1]++;
			// 	i++;
			// }
		}
		else if (a > 3 * M_PI / 2 && a < 2 * M_PI)
		{
			while (1)
			{
				// i = 0;
				// my_mlx_pixel_put(&cub->img, x1 + 2 , y1 + 5, 0x00FF00);
				// y1++;
				// x1++;
				x1 += round(Speed * cos(a));
				y1 -= round(Speed * sin(a));
				if (cub->map[y1 / 64][x1 / 64] == '1')
					break;
			}
			cub->ray_c.ray_length = sqrt((x1 - cub->m.px_pix) * (x1 - cub->m.px_pix)
							+ (y1 - cub->m.py_pix) * (y1 - cub->m.py_pix));
			cub->ray_c.wall_length = (64 / cub->ray_c.ray_length) * 100;
			arr[0] = cub->m.px_pix;
				arr[1] = x1;
				arr[2] = cub->m.py_pix;
				arr[3] = y1;
				draw_line(cub, arr, 0x00FF00);
			// while (i < cub->m.width * 64)
			// {
			// 	arr[3] = cub->ray_c.wall_length - 100;
			// 	draw_line(cub, arr, 0x00FF00);
			// 	arr[0]++;
			// 	arr[1]++;
			// 	i++;
			// }
		}
		else
			x1 += Speed;
		h++;
		a += ((float)90 / cub->m.width * 64) * M_PI / 180;
		printf("a = %f\n", a);
		i = 0;
		if (a >= 360)
			a = 0;
	}
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

void draw_line(t_cub *cub, int *arr, int color)
{
	int	x1 = arr[0];
	int	y1 = arr[2];
	int	x2 = arr[1];
	int	y2 = arr[3];
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        my_mlx_pixel_put(&cub->img, x1, y1, color);
        
        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}