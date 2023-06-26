/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:44:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/26 20:22:55 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_cub *cub)
{
	int	i;
	int	pos;

	i = 0;
	pos = cub->game.map.py_pix;
	float 	a = 0;
	int	x1;
	int	y1;
	int	h = 0;
	float f = 0;
	int *arr = malloc(4 * sizeof(int));
	x1 = cub->game.map.px_pix;
	y1 = cub->game.map.py_pix;
	// printf("i = %c\n", cub->game.map.map_2d[cub->game.map.py_pix / cub->game.map.scale_x][cub->game.map.px_pix / cub->game.map.scale_x]);
	a = cub->ray_c.angle - deg_to_rad(45, cub);
	float d = 0;
	if (a < 0)
		a += 2 * M_PI;
		// printf("d = %f\n", (M_PI / 2) / (WIDTH) - 0.0003);
		// exit(0);
		arr[0] = 0;
		arr[1] = 0;
	while (h < WIDTH)
	{
		// x1 = cub->game.map.px_pix;
		// y1 = cub->game.map.py_pix;
		check_horizontal(cub, a);
		f = cub->ray_c.angle - a;
		// 	if (f < 0)
		// 		f += 2 * M_PI;
		// 	else if (f > 2 * M_PI)
		// 		f -= 2 * M_PI;
			// if (d <= M_PI / 2)
			// cub->ray_c.ray_length = cub->ray_c.ray_length * cos(f);
		cub->ray_c.wall_length = ((cub->game.map.scale_y * HEIGHT) / cub->ray_c.ray_length) / 2;
		x1 = (((HEIGHT) / 2) - cub->ray_c.wall_length) / 2;
		arr[2] = x1;
		arr[3] =  cub->ray_c.wall_length + x1;
		draw_line(cub, arr, 0xFF0000);
		arr[0]++;
		arr[1]++;
		h++;
		// printf("a1=%d\n", arr[0]);
		// printf("a2=%d\n", arr[1]);
		// i = 0;
		if (a >= 2 * M_PI)
			a = 0;
		a += 0.002364;
		d += 0.002364;
	}
	free(arr);
}

void	check_horizontal(t_cub *cub, float a)
{
	float	px;
	float	py;
	float	yo;
	float	xo;
	int		arr[4];

	px = cub->game.map.px_pix;
	py = cub->game.map.py_pix;
	cub->ray_c.ys_h = (int)cub->game.map.py_pix;
	cub->ray_c.xs_h = 1 / tan(a);
	(void)yo;
	(void)xo;
	printf("a = %d\n", rad_to_deg(a, cub));
	int i = 0;
	if (a == 0 || a == 360)
	{
		cub->ray_c.ys_h = (int)py;
		cub->ray_c.xs_h = (int)px;
		// cub->ray_c.xs_h = ((py - cub->ray_c.ys_h) * (-1 / tan(a))) * -1 + px;
		// yo = 1;
		// xo = -yo * (-1 / tan(a));
		while (1)
		{
			if ((int)cub->ray_c.ys_h <= 0 || (int)cub->ray_c.ys_h / cub->game.map.scale_y >= cub->game.map.nline
			|| (int)cub->ray_c.xs_h <= 0 || (int)cub->ray_c.xs_h  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)][(int)(cub->ray_c.xs_h / cub->game.map.scale_x)] == '1')
				break;
			// cub->ray_c.ys_h -= Speed;
			cub->ray_c.xs_h += 1;
			i++;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_h;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_h;
	}
	else if (a == M_PI)
	{
		cub->ray_c.ys_h = (int)py;
		cub->ray_c.xs_h = (int)px;
		// yo = 1;
		// xo = -yo * (-1 / tan(a));
		while (1)
		{
			if ((int)cub->ray_c.ys_h <= 0 || (int)cub->ray_c.ys_h / cub->game.map.scale_y >= cub->game.map.nline
			|| (int)cub->ray_c.xs_h <= 0 || (int)cub->ray_c.xs_h  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)][(int)(cub->ray_c.xs_h / cub->game.map.scale_x)] == '1')
				break;
			// cub->ray_c.ys_h -= Speed;
			cub->ray_c.xs_h -= 1;
			i++;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_h;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_h;
	}
	else if (a > 0 && a < M_PI / 2)
	{
		cub->ray_c.ys_h = (int)py - 1;
		cub->ray_c.xs_h = ((py - cub->ray_c.ys_h) * (-1 / tan(a))) * -1 + px;
		yo = 1;
		xo = -yo * (-1 / tan(a));
		while (1)
		{
			if ((int)cub->ray_c.ys_h <= 0 || (int)cub->ray_c.ys_h / cub->game.map.scale_y >= cub->game.map.nline
			|| (int)cub->ray_c.xs_h <= 0 || (int)cub->ray_c.xs_h  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)][(int)(cub->ray_c.xs_h / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.ys_h -= 1;
			cub->ray_c.xs_h += xo;
			i++;
		}
		if (cub->ray_c.xs_h >= WIDTH)
			cub->ray_c.xs_h -= 64;
		if (cub->ray_c.ys_h >= HEIGHT)
			cub->ray_c.ys_h -= 64;
		arr[0] = px;
		arr[1] = cub->ray_c.xs_h;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_h;
		// draw_line(cub, arr, 0x00FF00);
	}
	else if (a > M_PI / 2 && a < M_PI)
	{
		cub->ray_c.ys_h = (int)py - 1;
		cub->ray_c.xs_h = ((py - cub->ray_c.ys_h) * (-1 / tan(a))) * -1 + px;
		yo = 1;
		xo = -yo * (-1 / tan(a));
		// printf("xo = %f, cub->ray_c.xs_h = %f\n", xo, cub->ray_c.xs_h);
		while (1)
		{
			if (cub->ray_c.ys_h <= 0 || (int)cub->ray_c.ys_h / cub->game.map.scale_y >= cub->game.map.nline
			|| cub->ray_c.xs_h <= 0 || (int)cub->ray_c.xs_h  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)]))
				break;
			// printf("px = %f\n", cub->ray_c.xs_h);
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)][(int)(cub->ray_c.xs_h / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.ys_h -= 1;
			cub->ray_c.xs_h += xo;
			i++;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_h;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_h;
		// draw_line(cub, arr, 0x00FF00);
	}
	else if (a > M_PI && a < (3 * M_PI) / 2)
	{
		cub->ray_c.ys_h = (int)py - 0.0001;
		cub->ray_c.xs_h = ((py - cub->ray_c.ys_h) * (-1 / tan(a))) + px;
		yo = 1;
		xo = -yo * (-1 / tan(a));
		// printf("xo = %f, cub->ray_c.xs_h = %f\n", xo, cub->ray_c.xs_h);
		while (1)
		{
			if (cub->ray_c.ys_h <= 0 || (int)cub->ray_c.ys_h / cub->game.map.scale_y >= cub->game.map.nline
			|| cub->ray_c.xs_h <= 0 || (int)cub->ray_c.xs_h  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)]))
			{
				// cub->ray_c.ys_h -= 65;
				break;
			}
			// printf("px = %f\n", cub->ray_c.xs_h);
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)][(int)(cub->ray_c.xs_h / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.ys_h += 1;
			cub->ray_c.xs_h -= xo;
			i++;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_h;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_h;
		// draw_line(cub, arr, 0x00FF00);
	}
	else if (a > 3 * M_PI / 2 && a < 2 * M_PI)
	{
		cub->ray_c.ys_h = (int)py - 0.0001;
		cub->ray_c.xs_h = ((py - cub->ray_c.ys_h) * (-1 / tan(a))) + px;
		yo = 1;
		xo = yo * (-1 / tan(a));
		// printf("xo = %f, cub->ray_c.xs_h = %f\n", xo, cub->ray_c.xs_h);
		while (1)
		{
			if (cub->ray_c.ys_h <= 0 || (int)cub->ray_c.ys_h / cub->game.map.scale_y >= cub->game.map.nline
			|| cub->ray_c.xs_h <= 0 || (int)cub->ray_c.xs_h  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)]))
			{
				// cub->ray_c.ys_h -= 65;
				break;
			}
			// printf("px = %f\n", cub->ray_c.xs_h);
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)][(int)(cub->ray_c.xs_h / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.ys_h += 1;
			cub->ray_c.xs_h += xo;
			i++;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_h;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_h;
		// draw_line(cub, arr, 0x00FF00);
	}
	cub->ray_c.ray_length = sqrt(((arr[1] - arr[0]) * (arr[1] - arr[0]))
	+ ((arr[3] - arr[2]) * (arr[3] - arr[2])));
	if (a == M_PI / 2 || a == deg_to_rad(90, cub))
	{
		printf("h = %f\n", cub->ray_c.ray_length);
	}
	cub->ray_c.tmp_length = check_vertical(cub, a);
	if (a == M_PI / 2 || a == deg_to_rad(90, cub))
	{
		printf("v = %f\n", cub->ray_c.tmp_length);
	}
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
	{
		// draw_line(cub, arr, 0xFF0000);
		cub->ray_c.ray_length = cub->ray_c.tmp_length;
		cub->ray_c.ys_h = cub->ray_c.ys_v;
		cub->ray_c.xs_h = cub->ray_c.xs_v;
	}
	// else
	// 	draw_line(cub, arr, 0xFF0000);
}

int	check_vertical(t_cub *cub, float a)
{
	float	px;
	float	py;
	float	yo;
	float	xo;
	int		arr[4];

	cub->ray_c.xs_v = 1;
	px = cub->game.map.px_pix;
	py = cub->game.map.py_pix;
	cub->ray_c.ys_v = -tan(a);
	if (a == M_PI / 2)
	{
		printf("here\n");
		cub->ray_c.xs_v = cub->game.map.px_pix;
		// px = cub->game.map.px_pix;
		// py = cub->game.map.py_pix;
		cub->ray_c.ys_v = cub->game.map.py_pix;
		while (1)
		{
			if (cub->ray_c.ys_v <= 0 || (int)cub->ray_c.ys_v / cub->game.map.scale_y >= cub->game.map.nline
			|| cub->ray_c.xs_v <= 0 || (int)cub->ray_c.xs_v  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)][(int)(cub->ray_c.xs_v / cub->game.map.scale_x)] == '1')
				break;
			// cub->ray_c.xs_v += 1;
			cub->ray_c.ys_v -= 1;
			// i++;
		}
		// if (cub->ray_c.xs_v >= cub->game.map.width * 64)
		// 	cub->ray_c.xs_v -= 64;
		// if (cub->ray_c.ys_v >= cub->game.map.height * 64)
		// 	cub->ray_c.ys_v -= 64;
		arr[0] = px;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_v;
	}
	else if (a == 3 * M_PI / 2)
	{
		printf("her1e\n");
		cub->ray_c.xs_v = cub->game.map.px_pix;
		// px = cub->game.map.px_pix;
		// py = cub->game.map.py_pix;
		cub->ray_c.ys_v = cub->game.map.py_pix;
		while (1)
		{
			if (cub->ray_c.ys_v <= 0 || (int)cub->ray_c.ys_v / cub->game.map.scale_y >= cub->game.map.nline
			|| cub->ray_c.xs_v <= 0 || (int)cub->ray_c.xs_v  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)][(int)(cub->ray_c.xs_v / cub->game.map.scale_x)] == '1')
				break;
			// cub->ray_c.xs_v += 1;
			cub->ray_c.ys_v += 1;
			// i++;
		}
		// if (cub->ray_c.xs_v >= cub->game.map.width * 64)
		// 	cub->ray_c.xs_v -= 64;
		// if (cub->ray_c.ys_v >= cub->game.map.height * 64)
		// 	cub->ray_c.ys_v -= 64;
		arr[0] = px;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_v;
	}
	else if (a > 0 && a < M_PI / 2)
	{
		cub->ray_c.xs_v = (int)px + 1;
		cub->ray_c.ys_v = ((px - cub->ray_c.xs_v) * (-tan(a))) * -1 + py;
		xo = 1;
		yo = -xo * (-tan(a));
		while (1)
		{
			if (cub->ray_c.ys_v <= 0 || (int)cub->ray_c.ys_v / cub->game.map.scale_y >= cub->game.map.nline
			|| cub->ray_c.xs_v <= 0 || (int)cub->ray_c.xs_v  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)][(int)(cub->ray_c.xs_v / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.xs_v += 1;
			cub->ray_c.ys_v -= yo;
			// i++;
		}
		// if (cub->ray_c.xs_v >= WIDTH)
		// 	cub->ray_c.xs_v -= 64;
		// if (cub->ray_c.ys_v >= HEIGHT)
		// 	cub->ray_c.ys_v -= 64;
		arr[0] = px;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_v;
		// draw_line(cub, arr, 0xFF0000);
	}
	else if (a > M_PI / 2 && a < M_PI)
	{
		cub->ray_c.xs_v = (int)px - 0.0001;
		cub->ray_c.ys_v = ((px - cub->ray_c.xs_v) * (-tan(a))) + py;
		xo = 1;
		yo = -xo * (-tan(a));
		// printf("xo = %f, cub->ray_c.xs_v = %f\n", xo, cub->ray_c.xs_v);
		while (1)
		{
			if (cub->ray_c.ys_v <= 0 || (int)cub->ray_c.ys_v / cub->game.map.scale_y >= cub->game.map.nline
			|| cub->ray_c.xs_v <= 0 || (int)cub->ray_c.xs_v  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)]))
			{
				// cub->ray_c.ys_v -= 65;
				break;
			}
			// printf("px = %f\n", cub->ray_c.xs_v);
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)][(int)(cub->ray_c.xs_v / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.xs_v -= 1;
			cub->ray_c.ys_v += yo;
			// i++;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_v;
		// draw_line(cub, arr, 0xFF0000);
	}
	else if (a > M_PI && a < (3 * M_PI) / 2)
	{
		cub->ray_c.xs_v = (int)px - 0.0001;
		cub->ray_c.ys_v = ((px - cub->ray_c.xs_v) * (-tan(a))) * -1 + py;
		xo = 1;
		yo = -xo * (-tan(a));
		// printf("x2o = %f, x2s = %f, cub->ray_c.xs_v = %f\n", cub->ray_c.ys_v, yo, cub->ray_c.xs_v);
		while (1)
		{
			if (cub->ray_c.ys_v <= 0 || (int)cub->ray_c.ys_v / cub->game.map.scale_y >= cub->game.map.nline
			|| cub->ray_c.xs_v <= 0 || (int)cub->ray_c.xs_v  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)]))
			{
				// cub->ray_c.ys_v -= 65;
				break;
			}
			// printf("px = %f\n", cub->ray_c.xs_v);
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)][(int)(cub->ray_c.xs_v / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.xs_v -= 1;
			cub->ray_c.ys_v += yo;
			// i++;
		}
		// if (cub->ray_c.xs_v >= WIDTH)
		// 	cub->ray_c.xs_v = WIDTH;
		// if (cub->ray_c.ys_v >= HEIGHT)
		// 	cub->ray_c.ys_v = HEIGHT;
		arr[0] = px;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_v;
		// draw_line(cub, arr, 0xFF0000);
	}
	else if (a > 3 * M_PI / 2 && a < 2 * M_PI)
	{
		cub->ray_c.xs_v = (int)px + 1;
		cub->ray_c.ys_v = ((px - cub->ray_c.xs_v) * (-tan(a))) * -1 + py;
		xo = 1;
		yo = -xo * (-tan(a));
		while (1)
		{
			if (cub->ray_c.ys_v <= 0 || (int)cub->ray_c.ys_v / cub->game.map.scale_y >= cub->game.map.nline
			|| cub->ray_c.xs_v <= 0 || (int)cub->ray_c.xs_v  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)][(int)(cub->ray_c.xs_v / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.xs_v += 1;
			cub->ray_c.ys_v -= yo;
			// i++;
		}
		// if (cub->ray_c.xs_v >= WIDTH)
		// 	cub->ray_c.xs_v = WIDTH;
		// if (cub->ray_c.ys_v >= HEIGHT)
		// 	cub->ray_c.ys_v = HEIGHT;
		arr[0] = px;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_v;
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
        my_mlx_pixel_put(cub, x1, y1, color);
        
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