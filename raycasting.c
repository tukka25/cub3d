/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:44:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/08 20:53:56 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_cub *cub)
{
	int	i;

	i = 0;
	float 	a = 0;
	float	x1;
	float	y1;
	float	h = 0;
	float f = 0;
	float *arr = malloc(4 * sizeof(float));
	x1 = cub->game.map.px_pix;
	y1 = cub->game.map.py_pix;
	a = cub->ray_c.angle + deg_to_rad(45, cub);
	if (a > 2 * M_PI)
		a -= 2 * M_PI;
	arr[0] = 0;
	arr[1] = 0;
	while (h < WIDTH)
	{
		check_horizontal(cub, a);
		x1 = (((HEIGHT) / 2) - cub->ray_c.wall_length) / 2;
		arr[2] = x1 + 150;
		arr[3] =  cub->ray_c.wall_length + x1 + 150;
		cu_draw_texture(cub, h, arr, a);
		f = a - cub->ray_c.angle;
			if (f < 0)
				f += 2 * M_PI;
			else if (f > 2 * M_PI)
				f -= 2 * M_PI;
		cub->ray_c.ray_length = cub->ray_c.ray_length * cos(f);
		cub->ray_c.wall_length = (((64 * HEIGHT) / cub->ray_c.ray_length) / 2);
		draw_line(cub, (float []){arr[0], arr[1], 0, arr[2]}, cub->game.floor);
		draw_line(cub, (float []){arr[0], arr[1], arr[3], HEIGHT}, cub->game.ceiling);
		arr[0]++;
		arr[1]++;
		h++;
		a -= 0.001;
		if (a < 0)
			a += 2 * M_PI;
	}
	free(arr);
}

void	check_horizontal(t_cub *cub, float a)
{
	float	px;
	float	py;
	float	yo;
	float	xo;
	float	arr[4];

	px = cub->game.map.px_pix;
	py = cub->game.map.py_pix;
	if (a < M_PI)
	{
		cub->ray_c.ys_h = (((int)py >> 6) << 6) - 0.0001;
		cub->ray_c.xs_h = (py - cub->ray_c.ys_h) * (-1 / tan(a)) + px;
		yo = -64;
		xo = -yo * (-1 / tan(a));
		while (1)
		{
			if ((int)cub->ray_c.ys_h <= 0 || (int)cub->ray_c.ys_h / cub->game.map.scale_y >= cub->game.map.nline
			|| (int)cub->ray_c.xs_h <= 0 || (int)cub->ray_c.xs_h  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)][(int)(cub->ray_c.xs_h / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.ys_h += yo;
			cub->ray_c.xs_h += xo;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_h;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_h;
	}
	else if (a > M_PI)
	{
		cub->ray_c.ys_h = (((int)py >> 6) << 6) + 64;
		cub->ray_c.xs_h = (py - cub->ray_c.ys_h) * (-1 / tan(a)) + px;
		yo = 64;
		xo = -yo * (-1 / tan(a));
		while (1)
		{
			if ((int)cub->ray_c.ys_h <= 0 || (int)cub->ray_c.ys_h / cub->game.map.scale_y >= cub->game.map.nline
			|| (int)cub->ray_c.xs_h <= 0 || (int)cub->ray_c.xs_h  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)][(int)(cub->ray_c.xs_h / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.ys_h += yo;
			cub->ray_c.xs_h += xo;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_h;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_h;
	}
	else
	{
		cub->ray_c.ys_h = py;
		cub->ray_c.xs_h = px;
		arr[0] = px;
		arr[1] = py;
		arr[2] = px;
		arr[3] = py;
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
	float	px;
	float	py;
	float	yo;
	float	xo;
	float 	k;
	float	arr[4];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	px = cub->game.map.px_pix;
	py = cub->game.map.py_pix;
	if ((a < M_PI / 2 || a > 3 * M_PI / 2))
	{
		cub->ray_c.xs_v = (((int)px >> 6) << 6) - 0.0001;
		cub->ray_c.ys_v = (px - cub->ray_c.xs_v) * (-tan(a)) + py;
		xo = -64;
		yo = -xo * (-tan(a));
		while (1)
		{
			if ((int)cub->ray_c.ys_v <= 0 || (int)cub->ray_c.ys_v / cub->game.map.scale_y >= cub->game.map.nline
			|| (int)cub->ray_c.xs_v <= 0 || (int)cub->ray_c.xs_v  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)][(int)(cub->ray_c.xs_v / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.xs_v += xo;
			cub->ray_c.ys_v += yo;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_v;
	}
	else if(a > M_PI / 2 && a < 3 * M_PI / 2)
	{
		cub->ray_c.xs_v = (((int)px >> 6) << 6) + 64;
		cub->ray_c.ys_v = (px - cub->ray_c.xs_v) * (-tan(a)) + py;
		xo = 64;
		yo = -xo * (-tan(a));
		while (1)
		{
			if ((int)cub->ray_c.ys_v <= 0 || (int)cub->ray_c.ys_v / cub->game.map.scale_y >= cub->game.map.nline
			|| (int)cub->ray_c.xs_v <= 0 || (int)cub->ray_c.xs_v  / cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v / cub->game.map.scale_y)][(int)(cub->ray_c.xs_v / cub->game.map.scale_x)] != '0')
				break;
			cub->ray_c.xs_v += xo;
			cub->ray_c.ys_v += yo;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_v;
	}
	else
	{
		cub->ray_c.ys_v = py;
		cub->ray_c.xs_v = px;
		arr[0] = px;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_v;
	}
	k = sqrt(((arr[1] - arr[0]) * (arr[1] - arr[0]))
		+ ((arr[3] - arr[2]) * (arr[3] - arr[2])));
	return (k);
}

void draw_line(t_cub *cub, float *arr, int color)
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

void	cu_draw_texture(t_cub *cub, int h, float *arr, float a)
{
	float		start;
	float		end;
	float		xo;
	float	y_step;
	float		y = 0;


	start = arr[2];
	end = arr[3];
	if (cub->ray_c.ray_length < cub->ray_c.tmp_length)
		xo = (int)(cub->ray_c.xs_h / cub->game.map.scale_x * (float)cub->n_texture.t_width) % cub->n_texture.t_width;
	else
		xo = (int)(cub->ray_c.ys_v / cub->game.map.scale_y * (float)cub->n_texture.t_width) % cub->n_texture.t_width;
	y_step = cub->n_texture.t_height / cub->ray_c.wall_length;
	while (start <= end)
	{
		my_mlx_pixel_put(cub, h, start++, cu_get_color(cub, xo, y += y_step, a));
		if (xo > cub->n_texture.t_width)
			xo = cub->n_texture.t_width - 1;
		if (y + y_step >= cub->n_texture.t_height)
			y = cub->n_texture.t_height - y_step - 1;
	}
}