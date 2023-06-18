/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:44:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/18 19:11:37 by abdamoha         ###   ########.fr       */
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
	x1 = cub->m.px_pix;
	y1 = cub->m.py_pix;
	printf("i = %c\n", cub->map[cub->m.py_pix / 64][cub->m.px_pix / 64]);
	a = cub->ray_c.angle - deg_to_rad(45, cub);
	float d = 0;
	if (a < 0)
		a += 2 * M_PI;
		// printf("d = %f\n", (M_PI / 2) / (cub->m.width * 64) - 0.0003);
		// exit(0);
	// while (d <= M_PI_2)
	// {
		x1 = cub->m.px_pix;
		y1 = cub->m.py_pix;
		// if (a > 0 && a < 2 * M_PI)
		// {
			check_horizontal(cub, arr, a);
			// while (1)
			// {
			// 	x1 += round((Speed + 300)  * cos(a));
			// 	y1 -= round((Speed + 300) * sin(a));
			// 	if (cub->map[y1 / 64][x1 / 64] == '1' || y1 <= 0 || x1 <= 0)
			// 		break;
			// }
			// while (cub->map[y1 / 64][x1 / 64] == '1' && cub->map[y1 / 64][x1 / 64])
			// {
			// 	printf("g\n");
			// 	y1 += round(Speed + 3 * cos(a));
			// }
			// cub->ray_c.ray_length = sqrt((x1 - cub->m.px_pix) * (x1 - cub->m.px_pix)
			// 				+ (y1 - cub->m.py_pix) * (y1 - cub->m.py_pix));
			// cub->ray_c.wall_length = (64 / cub->ray_c.ray_length) * 100;
			// arr[0] = cub->m.px_pix;
			// 	arr[1] = x1;
			// 	arr[2] = cub->m.py_pix;
			// 	arr[3] = y1;
			// 	draw_line(cub, arr, 0x00FF00);
		// }
		// else
		// 	x1 += Speed;
		h++;
		// printf("a=%f\n", a);
		i = 0;
		if (a >= 2 * M_PI)
			a = 0;
		a += 0.001364;
		d += 0.001364;
	// }
}

void	check_horizontal(t_cub *cub, int *arr, float a)
{
	float	ys;
	float	xs;
	float	px;
	float	py;
	float	yo;
	float	xo;

	px = cub->m.px_pix;
	py = cub->m.py_pix;
	ys = (int)cub->m.py_pix;
	xs = 64 / tan(a);
	// printf("a = %d\n", rad_to_deg(a, cub));
	// if (a == M_PI)
	// {
	// 	while (cub->map[ys / 64][xs/ 64] == '1')
	// 	{
	// 		if (cub->map[ys / 64][xs + 1 / 64] == '1')
	// 			return ;
	// 		xs -= 64;
	// 	}
	// 	arr[0] = cub->m.px_pix;
	// 	arr[1] = xs;
	// 	arr[2] = cub->m.py_pix;
	// 	arr[3] = 0;
	// 	draw_line(cub, arr, 0x00FF00);
	// }
	// if (a == 0 || a == 2 * M_PI)
	// {
	// 	while (cub->map[ys / 64][xs/ 64] == '1')
	// 	{
	// 		if (cub->map[ys / 64][xs + 1 / 64] == '1')
	// 			return ;
	// 		xs += 64;
	// 	}
	// 	arr[0] = cub->m.px_pix;
	// 	arr[1] = xs + cub->m.px_pix;
	// 	arr[2] = cub->m.py_pix;
	// 	arr[3] = (cub->m.width * 64) - 64;
	// 	draw_line(cub, arr, 0x00FF00);
	// }
	printf("a = %d\n", rad_to_deg(a, cub));
	int i = 0;
	if (a > 0 && a < M_PI / 2)
	{
		ys = (int)cub->m.py_pix - 64;
		xs = ((py - ys) * (-1 / tan(a))) * -1 + px;
		yo = 64;
		xo = -yo * (-1 / tan(a));
		printf("ys = %f, xs = %f\n", ys / 64, xs / 64);
		while (1)
		{
			if (ys <= 0 || ys >= cub->m.height * 64
			|| xs <= 0 || xs >= cub->m.width * 64)
			{
				// ys -= 65;
				break;
			}
			// printf("py = %f, px = %f\n", (py - ys) / 64, (xs + px) / 64);
			if (cub->map[(int)(ys / 64)][(int)(xs / 64)] == '1')
				break;
			ys -= 65;
			xs += xo;
			i++;
		}
		printf("i = %d\n", i);
		printf("ys = %f\n", ys / 64);
		printf("xs = %f\n", xs / 64);
		if (xs >= cub->m.width * 64)
			xs -= 64;
		if (ys >= cub->m.height * 64)
			ys -= 64;
		// printf("px = %f\n", px);
		// printf("px = %f\n", px);
		// printf("after xs = %f, after ys = %f\n, index = %c", xs / 64, ys / 64, cub->map[(int)ys / 64][(int)xs / 64]);
		arr[0] = cub->m.px_pix;
		arr[1] = xs;
		arr[2] = cub->m.py_pix;
		arr[3] = ys;
		draw_line(cub, arr, 0x00FF00);
	}
	else if (a > M_PI / 2 && a < M_PI)
	{
		ys = (int)cub->m.py_pix - 65;
		xs = ((py - ys) * (-1 / tan(a))) * -1 + px;
		yo = 64;
		xo = -yo * (-1 / tan(a));
		// printf("xo = %f, xs = %f\n", xo, xs);
		while (1)
		{
			if (ys <= 0 || ys >= cub->m.height * 64
			|| xs <= 0 || xs >= cub->m.width * 64)
			{
				// ys -= 65;
				break;
			}
			// printf("px = %f\n", xs);
			if (cub->map[(int)(ys / 64)][(int)(xs / 64)] == '1')
				break;
			ys -= 65;
			xs += xo;
			i++;
		}
		arr[0] = cub->m.px_pix;
		arr[1] = xs;
		arr[2] = cub->m.py_pix;
		arr[3] = ys;
		draw_line(cub, arr, 0x00FF00);
	}
	else if (a > M_PI && a < (3 * M_PI) / 2)
	{
		ys = (int)cub->m.py_pix - 0.0001;
		xs = ((py - ys) * (-1 / tan(a))) + px;
		yo = 64;
		xo = -yo * (-1 / tan(a));
		// printf("xo = %f, xs = %f\n", xo, xs);
		while (1)
		{
			if (ys <= 0 || ys >= cub->m.height * 64
			|| xs <= 0 || xs >= cub->m.width * 64)
			{
				// ys -= 65;
				break;
			}
			// printf("px = %f\n", xs);
			if (cub->map[(int)(ys / 64)][(int)(xs / 64)] == '1')
				break;
			ys += 65;
			xs -= xo;
			i++;
		}
		arr[0] = cub->m.px_pix;
		arr[1] = xs;
		arr[2] = cub->m.py_pix;
		arr[3] = ys;
		draw_line(cub, arr, 0x00FF00);
	}
	else if (a > 3 * M_PI / 2 && a < 2 * M_PI)
	{
		ys = (int)cub->m.py_pix - 0.0001;
		xs = ((py - ys) * (-1 / tan(a))) + px;
		yo = 64;
		xo = yo * (-1 / tan(a));
		printf("xo = %f, xs = %f\n", xo, xs);
		while (1)
		{
			if (ys <= 0 || ys >= cub->m.height * 64
			|| xs <= 0 || xs >= cub->m.width * 64)
			{
				// ys -= 65;
				break;
			}
			printf("px = %f\n", xs);
			if (cub->map[(int)(ys / 64)][(int)(xs / 64)] == '1')
				break;
			ys += 65;
			xs += xo;
			i++;
		}
		arr[0] = cub->m.px_pix;
		arr[1] = xs;
		arr[2] = cub->m.py_pix;
		arr[3] = ys;
		draw_line(cub, arr, 0x00FF00);
	}
	// else if (a == 0 || a == 2 * M_PI)
	// {
	// 	while (cub->map[(int)py / 64][(int)px / 64] != '1')
	// 	{
	// 		px += Speed;
	// 	}
	// 	arr[0] = cub->m.px_pix;
	// 	arr[1] = xs + cub->m.px_pix;
	// 	arr[2] = cub->m.py_pix;
	// 	arr[3] = cub->m.py_pix;
	// 	draw_line(cub, arr, 0x00FF00);
	// }
	// else if (a == M_PI)
	// {
	// 	printf("a = %d\n", rad_to_deg(a, cub));
	// 	while (cub->map[(int)py / 64][(int)px / 64] != '1')
	// 	{
	// 		px -= Speed;
	// 	}
	// 	arr[0] = cub->m.px_pix;
	// 	arr[1] = xs + cub->m.px_pix;
	// 	arr[2] = cub->m.py_pix;
	// 	arr[3] = cub->m.py_pix;
	// 	draw_line(cub, arr, 0x00FF00);
	// }
	// cub->ray_c.ray_length = sqrt(((arr[1] - arr[0]) * (arr[1] - arr[0]))
	// + ((arr[3] - arr[2]) * (arr[3] - arr[2])));
	// check_vertical(cub, arr, a);
}

int	check_vertical(t_cub *cub, int *arr, float a)
{
	float	ys;
	float	xs;
	float	px;
	float	py;
	float	atan;

	xs = 64;
	px = cub->m.px_pix;
	py = cub->m.py_pix;
	ys = -tan(a);
	printf("a = %d\n", rad_to_deg(a, cub));
	atan = -tan(a) * xs;
	int	i = 0;
	// printf("ys = %c\n", cub->map[(py) / 64][(px) / 64]);
	// printf("c = %c\n", cub->map[(py + ys) / 64][(px + xs) / 64]);
	// if (ys > 0)
	// {
		// if (a > M_PI / 2 && a < (3 * M_PI) / 2)
		// {
		// 	printf("ys = %f\n", ys);
		// 	while (1)
		// 	{
		// 		// printf("ys = %d, xs = %d\n", (py - ys) / 64, (xs + px) / 64);
		// 		if (ys <= 0 || ys + py >= cub->m.height * 64
		// 			|| xs + px <= 0 || (xs + px) >= cub->m.width * 64)
		// 			break;
		// 		if (cub->map[(int)(py - ys) / 64][(int)(xs + px) / 64] == '1')
		// 			break;
		// 		ys += -tan(a) * xs;
		// 		xs += 64;
		// 		i++;
		// 	}
		// 	arr[0] = cub->m.px_pix;
		// 	arr[1] = xs + cub->m.px_pix;
		// 	arr[2] = cub->m.py_pix;
		// 	arr[3] = cub->m.py_pix - ys;
		// 	draw_line(cub, arr, 0xFF0000);
		// }
		if (a > (3 * M_PI) / 2 || a < M_PI / 2)
		{
			i = 0;
			ys = -tan(a) * 64;
			printf("ys2 = %f\n", ys);
			while (1)
			{
				// printf("ys = %d, xs = %d\n", (py - ys) / 64, (xs + px) / 64);
				// if (ys <= 0 || ys + py >= cub->m.height * 64
				// 	|| xs + px <= 0 || (xs + px) >= cub->m.width * 64)
				// 	break;
				printf("py = %f, px = %f\n", (py + ys) / 64 , (px + xs) / 64);
				if (cub->map[(int)(py + ys) / 64][(int)(px + xs) / 64] == '1')
					break;
				ys++;
				xs += 65;
				i++;
			}
			printf("py o = %f, px o = %f\n", (py + ys)/64 , (px + xs)/64);
			printf("i = %d\n", i);
			arr[0] = cub->m.px_pix;
			arr[1] = cub->m.px_pix + xs;
			arr[2] = cub->m.py_pix;
			arr[3] = cub->m.py_pix + ys;
			draw_line(cub, arr, 0xFF0000);
		}
	// }
	
	return (ys);
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