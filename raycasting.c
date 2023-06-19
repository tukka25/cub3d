/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:44:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/19 19:09:56 by abdamoha         ###   ########.fr       */
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
	// int *arr = malloc(4 * sizeof(int));
	x1 = cub->m.px_pix;
	y1 = cub->m.py_pix;
	printf("i = %c\n", cub->map[cub->m.py_pix / 64][cub->m.px_pix / 64]);
	a = cub->ray_c.angle - deg_to_rad(45, cub);
	float d = 0;
	if (a < 0)
		a += 2 * M_PI;
		// printf("d = %f\n", (M_PI / 2) / (cub->m.width * 64) - 0.0003);
		// exit(0);
	while (d <= M_PI_2)
	{
		x1 = cub->m.px_pix;
		y1 = cub->m.py_pix;
		// if (a > 0 && a < 2 * M_PI)
		// {
			check_horizontal(cub, a);
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
		a += 0.002364;
		d += 0.002364;
	}
}

void	check_horizontal(t_cub *cub, float a)
{
	float	ys;
	float	xs;
	float	px;
	float	py;
	float	yo;
	float	xo;
	int		arr[4];

	px = cub->m.px_pix;
	py = cub->m.py_pix;
	ys = (int)cub->m.py_pix;
	xs = 64 / tan(a);
	(void)yo;
	(void)xo;
	printf("a = %d\n", rad_to_deg(a, cub));
	int i = 0;
	if (a > 0 && a < M_PI / 2)
	{
		ys = (int)py - 64;
		xs = ((py - ys) * (-1 / tan(a))) * -1 + px;
		yo = 64;
		xo = -yo * (-1 / tan(a));
		while (1)
		{
			if (ys <= 0 || ys >= cub->m.height * 64
			|| xs <= 0 || xs >= cub->m.width * 64)
				break;
			if (cub->map[(int)(ys / 64)][(int)(xs / 64)] == '1')
				break;
			ys -= 65;
			xs += xo;
			i++;
		}
		if (xs >= cub->m.width * 64)
			xs -= 64;
		if (ys >= cub->m.height * 64)
			ys -= 64;
		arr[0] = px;
		arr[1] = xs;
		arr[2] = py;
		arr[3] = ys;
		// draw_line(cub, arr, 0x00FF00);
	}
	else if (a > M_PI / 2 && a < M_PI)
	{
		ys = (int)py - 65;
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
		arr[0] = px;
		arr[1] = xs;
		arr[2] = py;
		arr[3] = ys;
		// draw_line(cub, arr, 0x00FF00);
	}
	else if (a > M_PI && a < (3 * M_PI) / 2)
	{
		ys = (int)py - 0.0001;
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
		arr[0] = px;
		arr[1] = xs;
		arr[2] = py;
		arr[3] = ys;
		// draw_line(cub, arr, 0x00FF00);
	}
	else if (a > 3 * M_PI / 2 && a < 2 * M_PI)
	{
		ys = (int)py - 0.0001;
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
		arr[0] = px;
		arr[1] = xs;
		arr[2] = py;
		arr[3] = ys;
		// draw_line(cub, arr, 0x00FF00);
	}
	// else if (a == 0 || a == 2 * M_PI)
	// {
	// 	while (cub->map[(int)py / 64][(int)px / 64] != '1')
	// 	{
	// 		px += Speed;
	// 	}
	// 	arr[0] = px;
	// 	arr[1] = xs + px;
	// 	arr[2] = py;
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
	// 	arr[0] = px;
	// 	arr[1] = xs + px;
	// 	arr[2] = cub->m.py_pix;
	// 	arr[3] = cub->m.py_pix;
	// 	draw_line(cub, arr, 0x00FF00);
	// }
	cub->ray_c.ray_length = sqrt(((arr[1] - arr[0]) * (arr[1] - arr[0]))
	+ ((arr[3] - arr[2]) * (arr[3] - arr[2])));
	ys = check_vertical(cub, a);
	if (ys < cub->ray_c.ray_length)
		cub->ray_c.ray_length = ys;
}

int	check_vertical(t_cub *cub, float a)
{
	float	ys;
	float	xs;
	float	px;
	float	py;
	float	yo;
	float	xo;
	int		arr[4];

	xs = 64;
	px = cub->m.px_pix;
	py = cub->m.py_pix;
	ys = -tan(a);
	printf("a = %d\n", rad_to_deg(a, cub));
	if (a > 0 && a < M_PI / 2)
	{
		xs = (int)px + 64;
		ys = ((px - xs) * (-tan(a))) * -1 + py;
		xo = 64;
		yo = -xo * (-tan(a));
		while (1)
		{
			if (ys <= 0 || ys >= cub->m.height * 64
			|| xs <= 0 || xs >= cub->m.width * 64)
				break;
			if (cub->map[(int)(ys / 64)][(int)(xs / 64)] == '1')
				break;
			xs += 65;
			ys -= yo;
			// i++;
		}
		// if (xs >= cub->m.width * 64)
		// 	xs -= 64;
		// if (ys >= cub->m.height * 64)
		// 	ys -= 64;
		arr[0] = px;
		arr[1] = xs;
		arr[2] = py;
		arr[3] = ys;
		// draw_line(cub, arr, 0xFF0000);
	}
	else if (a > M_PI / 2 && a < M_PI)
	{
		xs = (int)px - 0.0001;
		ys = ((px - xs) * (-tan(a))) + py;
		xo = 64;
		yo = -xo * (-tan(a));
		printf("xo = %f, xs = %f\n", xo, xs);
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
			xs -= 65;
			ys += yo;
			// i++;
		}
		arr[0] = px;
		arr[1] = xs;
		arr[2] = py;
		arr[3] = ys;
		// draw_line(cub, arr, 0xFF0000);
	}
	else if (a > M_PI && a < (3 * M_PI) / 2)
	{
		xs = (int)px - 0.0001;
		ys = ((px - xs) * (-tan(a))) * -1 + py;
		xo = 64;
		yo = -xo * (-tan(a));
		printf("x2o = %f, x2s = %f, xs = %f\n", ys, yo, xs);
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
			xs -= 64;
			ys += yo;
			// i++;
		}
		if (xs >= cub->m.width * 64)
			xs = cub->m.width * 64;
		if (ys >= cub->m.height * 64)
			ys = cub->m.height * 64;
		arr[0] = px;
		arr[1] = xs;
		arr[2] = py;
		arr[3] = ys;
		// draw_line(cub, arr, 0xFF0000);
	}
	else if (a > 3 * M_PI / 2 && a < 2 * M_PI)
	{
		xs = (int)px + 64;
		ys = ((px - xs) * (-tan(a))) * -1 + py;
		xo = 64;
		yo = -xo * (-tan(a));
		while (1)
		{
			if (ys <= 0 || ys >= cub->m.height * 64
			|| xs <= 0 || xs >= cub->m.width * 64)
				break;
			if (cub->map[(int)(ys / 64)][(int)(xs / 64)] == '1')
				break;
			xs += 64;
			ys -= yo;
			// i++;
		}
		if (xs >= cub->m.width * 64)
			xs = cub->m.width * 64;
		if (ys >= cub->m.height * 64)
			ys = cub->m.height * 64;
		arr[0] = px;
		arr[1] = xs;
		arr[2] = py;
		arr[3] = ys;
		// draw_line(cub, arr, 0xFF0000);
	}
	float k = sqrt(((arr[1] - arr[0]) * (arr[1] - arr[0]))
	+ ((arr[3] - arr[2]) * (arr[3] - arr[2])));
	// if (k <= cub->ray_c.ray_length)
	// 	draw_line(cub, arr, 0xFF0000);
	return (k);
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