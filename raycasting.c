/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:44:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/09 22:25:21 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_cub *cub)
{
	rayc_init(cub);
	if (cub->ray_c.a < 0)
		cub->ray_c.a += 2 * M_PI;
	cub->ray_c.arr[0] = 0;
	cub->ray_c.arr[1] = 0;
	while (cub->ray_c.h < WIDTH)
	{
		check_horizontal(cub, cub->ray_c.a);
		cub->ray_c.x1 = (((HEIGHT) / 2) - cub->ray_c.wall_length) / 2;
		cub->ray_c.arr[2] = cub->ray_c.x1 + 150;
		cub->ray_c.arr[3] = cub->ray_c.wall_length + cub->ray_c.x1 + 150;
		cu_draw_texture(cub, cub->ray_c.h, cub->ray_c.arr, cub->ray_c.a);
		cub->ray_c.f = cub->ray_c.a - cub->ray_c.angle;
		if (cub->ray_c.f < 0)
			cub->ray_c.f += 2 * M_PI;
		else if (cub->ray_c.f > 2 * M_PI)
			cub->ray_c.f -= 2 * M_PI;
		cub->ray_c.ray_length = cub->ray_c.ray_length * cos(cub->ray_c.f);
		cub->ray_c.wall_length = (((64 * HEIGHT) / cub->ray_c.ray_length) / 2);
		floor_ceiling(cub);
		cub->ray_c.a += 0.001;
		if (cub->ray_c.a > 2 * M_PI)
			cub->ray_c.a -= 2 * M_PI;
	}
}

void	check_horizontal(t_cub *cub, float a)
{
	float	yo;
	float	xo;
	float	arr[4];

	if (a < M_PI)
	{
		cub->ray_c.ys_h = (((int)cub->game.map.py_pix >> 6) << 6) - 0.0001;
		cub->ray_c.xs_h = (cub->game.map.py_pix - cub->ray_c.ys_h) * (-1 / tan(a)) + cub->game.map.px_pix;
		yo = -64;
		xo = -yo * (-1 / tan(a));
		while (1)
		{
			if ((int)cub->ray_c.ys_h <= 0 || (int)cub->ray_c.ys_h
				/ cub->game.map.scale_y >= cub->game.map.nline
				|| (int)cub->ray_c.xs_h <= 0 || (int)cub->ray_c.xs_h
				/ cub->game.map.scale_x
				>= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h
						/ cub->game.map.scale_y)]))
				break ;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h
					/ cub->game.map.scale_y)][(int)(cub->ray_c.xs_h
				/ cub->game.map.scale_x)] != '0')
				break ;
			cub->ray_c.ys_h += yo;
			cub->ray_c.xs_h += xo;
		}
		arr[0] = cub->game.map.px_pix;
		arr[1] = cub->ray_c.xs_h;
		arr[2] = cub->game.map.py_pix;
		arr[3] = cub->ray_c.ys_h;
	}
	else if (a > M_PI)
	{
		cub->ray_c.ys_h = (((int)cub->game.map.py_pix >> 6) << 6) + 64;
		cub->ray_c.xs_h = (cub->game.map.py_pix - cub->ray_c.ys_h) * (-1 / tan(a)) + cub->game.map.px_pix;
		yo = 64;
		xo = -yo * (-1 / tan(a));
		while (1)
		{
			if ((int)cub->ray_c.ys_h <= 0 || (int)cub->ray_c.ys_h
				/ cub->game.map.scale_y >= cub->game.map.nline
				|| (int)cub->ray_c.xs_h <= 0 || (int)cub->ray_c.xs_h
				/ cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)
						(cub->ray_c.ys_h / cub->game.map.scale_y)]))
				break ;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h
					/ cub->game.map.scale_y)][(int)(cub->ray_c.xs_h
				/ cub->game.map.scale_x)] != '0')
				break ;
			cub->ray_c.ys_h += yo;
			cub->ray_c.xs_h += xo;
		}
		arr[0] = cub->game.map.px_pix;
		arr[1] = cub->ray_c.xs_h;
		arr[2] = cub->game.map.py_pix;
		arr[3] = cub->ray_c.ys_h;
	}
	else
	{
		cub->ray_c.ys_h = cub->game.map.py_pix;
		cub->ray_c.xs_h = cub->game.map.px_pix;
		arr[0] = cub->game.map.px_pix;
		arr[1] = cub->game.map.py_pix;
		arr[2] = cub->game.map.px_pix;
		arr[3] = cub->game.map.py_pix;
	}
	cub->ray_c.ray_length = sqrt(((arr[1] - arr[0]) * (arr[1] - arr[0]))
			+ ((arr[3] - arr[2]) * (arr[3] - arr[2])));
	cub->ray_c.tmp_length = check_vertical(cub, a);
	if (cub->ray_c.tmp_length < cub->ray_c.ray_length)
	{
		cub->ray_c.ray_length = cub->ray_c.tmp_length;
		cub->ray_c.ys_h = cub->ray_c.ys_v;
		cub->ray_c.xs_h = cub->ray_c.xs_v;
	}
}

float	check_vertical(t_cub *cub, float a)
{
	float	yo;
	float	xo;
	float	k;
	float	arr[4];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	if ((a < M_PI / 2 || a > 3 * M_PI / 2))
	{
		cub->ray_c.xs_v = (((int)cub->game.map.px_pix >> 6) << 6) - 0.0001;
		cub->ray_c.ys_v = (cub->game.map.px_pix - cub->ray_c.xs_v) * (-tan(a)) + cub->game.map.py_pix;
		xo = -64;
		yo = -xo * (-tan(a));
		looking_up(cub, a, yo, xo);
		arr[0] = cub->game.map.px_pix;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = cub->game.map.py_pix;
		arr[3] = cub->ray_c.ys_v;
	}
	else if (a > M_PI / 2 && a < 3 * M_PI / 2)
	{
		cub->ray_c.xs_v = (((int)cub->game.map.px_pix >> 6) << 6) + 64;
		cub->ray_c.ys_v = (cub->game.map.px_pix - cub->ray_c.xs_v) * (-tan(a)) + cub->game.map.py_pix;
		xo = 64;
		yo = -xo * (-tan(a));
		while (1)
		{
			if ((int)cub->ray_c.ys_v <= 0 || (int)cub->ray_c.ys_v
				/ cub->game.map.scale_y >= cub->game.map.nline
				|| (int)cub->ray_c.xs_v <= 0 || (int)cub->ray_c.xs_v
				/ cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)
						(cub->ray_c.ys_v / cub->game.map.scale_y)]))
				break ;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v
					/ cub->game.map.scale_y)][(int)(cub->ray_c.xs_v
			/ cub->game.map.scale_x)] != '0')
				break ;
			cub->ray_c.xs_v += xo;
			cub->ray_c.ys_v += yo;
		}
		arr[0] = cub->game.map.px_pix;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = cub->game.map.py_pix;
		arr[3] = cub->ray_c.ys_v;
	}
	else
	{
		cub->ray_c.ys_v = cub->game.map.py_pix;
		cub->ray_c.xs_v = cub->game.map.px_pix;
		arr[0] = cub->game.map.px_pix;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = cub->game.map.py_pix;
		arr[3] = cub->ray_c.ys_v;
	}
	k = sqrt(((arr[1] - arr[0]) * (arr[1] - arr[0]))
			+ ((arr[3] - arr[2]) * (arr[3] - arr[2])));
	return (k);
}

void	draw_line(t_cub *cub, float *arr, int color)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	x1 = arr[0];
	y1 = arr[2];
	x2 = arr[1];
	y2 = arr[3];
    int	dx = abs(x2 - x1);
    int	dy = abs(y2 - y1);
    int	sx = x1 < x2 ? 1 : -1;
    int	sy = y1 < y2 ? 1 : -1;
    int	err = dx - dy;

	// x1 = arr[0];
	// y1 = arr[2];
	// x2 = arr[1];
	// y2 = arr[3];
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = x1 < x2 ? 1 : -1;
    while (x1 != x2 || y1 != y2)
	{
		my_mlx_pixel_put(cub, x1, y1, color);
		int err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	cu_draw_texture(t_cub *cub, int h, float *arr, float a)
{
	float	start;
	float	end;
	float	xo;
	float	y_step;
	float	y;

	start = arr[2];
	end = arr[3];
	y = 0;
	cu_check_coordinate(cub, a);
	if (cub->ray_c.ray_length < cub->ray_c.tmp_length)
		xo = (int)(cub->ray_c.xs_h / cub->game.map.scale_x
				* (float)cub->texture->t_width) % cub->texture->t_width;
	else
		xo = (int)(cub->ray_c.ys_v / cub->game.map.scale_y
				* (float)cub->texture->t_width) % cub->texture->t_width;
	y_step = cub->texture->t_height / cub->ray_c.wall_length;
	while (start <= end)
	{
		if (xo > cub->texture->t_width)
			xo = cub->texture->t_width - 1;
		if (y + y_step >= cub->texture->t_height)
			y = cub->texture->t_height - y_step - 1;
		my_mlx_pixel_put(cub, h, start++,
			cu_get_color(cub, xo, y += y_step));
	}
	return ;
}
