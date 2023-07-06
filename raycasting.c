/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:44:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/07 01:33:08 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_cub *cub)
{
	double 	a = 0;
	int	h = 0;
	a = cub->ray_c.angle + deg_to_rad(45, cub);
	if (a > 2 * M_PI)
		a -= 2 * M_PI;
	cu_texture(cub);
	while (h < WIDTH)
	{
		check_horizontal(cub, a);
		cub->ray_c.wall_length = HEIGHT / cub->ray_c.ray_length;
		if (cub->ray_c.tmp_length < cub->ray_c.ray_length)
			cub->ray_c.wall_length = HEIGHT / cub->ray_c.tmp_length;
		// draw_line(cub, (int[]){arr[0], arr[1], 0, arr[2]}, cub->game.ceiling);
		// draw_line(cub, (int[]){arr[0], arr[1], arr[3], HEIGHT}, cub->game.floor)		)rr[1]++;
		cu_draw_texture(cub, h);
		h++;
		a -= 0.001;
		if (a < 0)
			a += 2 * M_PI;
	}
}

void	check_horizontal(t_cub *cub, double a)
{
	double	px;
	double	py;
	double	yo;
	double	xo;
	double	arr[4];

	px = cub->game.map.px_pix;
	py = cub->game.map.py_pix;
	(void)yo;
	(void)xo;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	if (a < M_PI)
	{
		cub->ray_c.ys_h = floor(py) - 0.001;
		cub->ray_c.xs_h = (py - cub->ray_c.ys_h) * (-1 / tan(a)) + px;
		yo = -1.0;
		xo = -yo * (-1 / tan(a));
		while (1)
		{
			if (cub->ray_c.ys_h <= 0.0 || (int)(cub->ray_c.ys_h) >= cub->game.map.nline
			|| cub->ray_c.xs_h <= 0.0 || (int)(cub->ray_c.xs_h) >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h)][(int)(cub->ray_c.xs_h)] != '0')
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
		cub->ray_c.ys_h = floor(py) + 1.0;
		cub->ray_c.xs_h = (py - cub->ray_c.ys_h) * (-1 / tan(a)) + px;
		yo = 1.0;
		xo = -yo * (-1 / tan(a));
		while (1)
		{
			if (cub->ray_c.ys_h <= 0.0 || (int)(cub->ray_c.ys_h) >= cub->game.map.nline
			|| cub->ray_c.xs_h <= 0.0 || (int)(cub->ray_c.xs_h) >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_h)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h)][(int)(cub->ray_c.xs_h)] != '0')
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
	}
	cub->ray_c.ray_length = sqrt(((arr[1] - arr[0]) * (arr[1] - arr[0]))
	+ ((arr[3] - arr[2]) * (arr[3] - arr[2])));
	cub->ray_c.tmp_length = check_vertical(cub, a);
	// if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
	// {
	// 	draw_line(cub, arr, 0x00FF00);
	// }
}

double	check_vertical(t_cub *cub, double a)
{
	double	px;
	double	py;
	double	yo;
	double	xo;
	double 	k;
	double		arr[4];

	k = 0;
	px = cub->game.map.px_pix;
	py = cub->game.map.py_pix;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	if ((a < M_PI / 2 || a > 3 * M_PI / 2))
	{
		cub->ray_c.xs_v = floor(px) - 0.001;
		cub->ray_c.ys_v = (px - cub->ray_c.xs_v) * (-tan(a)) + py;
		xo = -1.0;
		yo = -xo * (-tan(a));
		while (1)
		{			
			if (cub->ray_c.ys_v <= 0.0 || (int)(cub->ray_c.ys_v) >= cub->game.map.nline
			|| cub->ray_c.xs_v <= 0.0 || (int)(cub->ray_c.xs_v) >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_v)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v)][(int)(cub->ray_c.xs_v)] != '0')
				break;
			cub->ray_c.xs_v += xo;
			cub->ray_c.ys_v += yo;
		}
		arr[0] = px;
		arr[1] = cub->ray_c.xs_v;
		arr[2] = py;
		arr[3] = cub->ray_c.ys_v;
	}
	else if ((a > M_PI / 2 && a < 3 * M_PI / 2))
	{
		cub->ray_c.xs_v = floor(px) + 1.0;
		cub->ray_c.ys_v = ((px - cub->ray_c.xs_v) * (-tan(a))) + py;
		xo = 1.0;
		yo = -xo * (-tan(a));
		while (1)
		{		
			if (cub->ray_c.ys_v <= 0.0 || (int)(cub->ray_c.ys_v) >= cub->game.map.nline
			|| cub->ray_c.xs_v <= 0.0 || (int)(cub->ray_c.xs_v) >= ft_strlen(cub->game.map.map_2d[(int)(cub->ray_c.ys_v)]))
				break;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v)][(int)(cub->ray_c.xs_v)] != '0')
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
	}
	k = sqrt(((arr[1] - arr[0]) * (arr[1] - arr[0]))
		+ ((arr[3] - arr[2]) * (arr[3] - arr[2])));
	// if (k < cub->ray_c.ray_length)
	// 	draw_line(cub, arr, 0xFF0000);
	return (k);
}

void draw_line(t_cub *cub, double *arr, int color)
{
	int	x1 = arr[0] * 64;
	int	y1 = arr[2] * 64;
	int	x2 = arr[1] * 64;
	int	y2 = arr[3] * 64;
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

void	cu_texture(t_cub *cub)
{
	cub->texture.img = mlx_xpm_file_to_image(cub->mlx.mlx, cub->game.west,
	&cub->texture.t_width, &cub->texture.t_height);
	cub->texture.addr = mlx_get_data_addr(cub->texture.img,
	&cub->texture.bits_per_pixel, &cub->texture.line_length,
	&cub->texture.endian);
}

void	cu_draw_texture(t_cub *cub, int h)
{
	int		start;
	int		end;
	// int		wall_height;
	int		xo;
	double	y_step;
	double		y = 0;

	// (void)arr;
	// wall_height = HEIGHT / cub->ray_c.ray_length;
	start = (HEIGHT / 2) - (cub->ray_c.wall_length / 2);
	end = (HEIGHT / 2) + (cub->ray_c.wall_length / 2);
	// printf("ray length: %f, ray temp: %f\n", cub->ray_c.ray_length, cub->ray_c.tmp_length);
	if (cub->ray_c.ray_length < cub->ray_c.tmp_length)
		xo = (int)(cub->ray_c.xs_h * (double)cub->texture.t_width) % cub->texture.t_width;
	else
		xo = (int)(cub->ray_c.ys_v * (double)cub->texture.t_width) % cub->texture.t_width;
	// printf("xo: %d\n", xo);
	y_step = cub->texture.t_height / cub->ray_c.wall_length;
	while (start <= end)
	{
		my_mlx_pixel_put(cub, h, start++, cu_get_color(cub, xo, y += y_step));
		if (xo > cub->texture.t_width)
			xo = cub->texture.t_width - 1;
		if (y + y_step >= cub->texture.t_height)
			y = cub->texture.t_height - y_step - 1;
	}
}