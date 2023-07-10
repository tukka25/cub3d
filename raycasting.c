/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:44:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/11 02:57:04 by talsaiaa         ###   ########.fr       */
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
		cub->ray_c.f = cub->ray_c.a - cub->ray_c.angle;
		if (cub->ray_c.f < 0)
			cub->ray_c.f += 2 * M_PI;
		else if (cub->ray_c.f > 2 * M_PI)
			cub->ray_c.f -= 2 * M_PI;
		cub->ray_c.ray_length = cub->ray_c.ray_length * cos(cub->ray_c.f);
		cub->ray_c.tmp_length = cub->ray_c.tmp_length * cos(cub->ray_c.f);
		cub->ray_c.wall_length = (((64 * HEIGHT) / cub->ray_c.ray_length) / 2);
		cub->ray_c.x1 = (((HEIGHT) / 2) - cub->ray_c.wall_length) / 2;
		cub->ray_c.arr[2] = cub->ray_c.x1 + 150;
		cub->ray_c.arr[3] = cub->ray_c.wall_length + cub->ray_c.x1 + 150;
		cu_draw_texture(cub, cub->ray_c.h, cub->ray_c.arr, cub->ray_c.a);
		floor_ceiling(cub);
		cub->ray_c.a += 0.001;
		if (cub->ray_c.a > 2 * M_PI)
			cub->ray_c.a -= 2 * M_PI;
	}
	free(cub->ray_c.arr);
}

void	check_horizontal(t_cub *cub, float a)
{
	float	yo;
	float	xo;
	float	arr[4];

	yo = 0.0;
	xo = 0.0;
	if (a < M_PI)
		looking_up_cal(cub, yo, xo, a);
	else if (a > M_PI)
		looking_down_cal(cub, xo, yo, a);
	else
	{
		cub->ray_c.ys_h = cub->game.map.py_pix;
		cub->ray_c.xs_h = cub->game.map.px_pix;
	}
	arr[0] = cub->game.map.px_pix;
	arr[1] = cub->ray_c.xs_h;
	arr[2] = cub->game.map.py_pix;
	arr[3] = cub->ray_c.ys_h;
	ray_len_cal(cub, a, arr);
}

float	check_vertical(t_cub *cub, float a)
{
	float	yo;
	float	xo;
	float	arr[4];

	yo = 0.0;
	xo = 0.0;
	if ((a < M_PI / 2 || a > 3 * M_PI / 2))
		looking_right_cal(cub, xo, yo, a);
	else if (a > M_PI / 2 && a < 3 * M_PI / 2)
		looking_left_cal(cub, xo, yo, a);
	else
	{
		cub->ray_c.ys_v = cub->game.map.py_pix;
		cub->ray_c.xs_v = cub->game.map.px_pix;
	}
	arr[0] = cub->game.map.px_pix;
	arr[1] = cub->ray_c.xs_v;
	arr[2] = cub->game.map.py_pix;
	arr[3] = cub->ray_c.ys_v;
	return (sqrt(((arr[1] - arr[0]) * (arr[1] - arr[0]))
			+ ((arr[3] - arr[2]) * (arr[3] - arr[2]))));
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
	init_vals(cub, (int []){x1, y1, x2, y2});
	while (x1 != x2 || y1 != y2)
	{
		my_mlx_pixel_put(cub, x1, y1, color);
		cub->ray_c.err2 = 2 * cub->ray_c.err;
		if (cub->ray_c.err2 > -cub->ray_c.dy)
		{
			cub->ray_c.err -= cub->ray_c.dy;
			x1 += cub->ray_c.sx;
		}
		if (cub->ray_c.err2 < cub->ray_c.dx)
		{
			cub->ray_c.err += cub->ray_c.dx;
			y1 += cub->ray_c.sy;
		}
	}
}

void	cu_draw_texture(t_cub *cub, int h, float *arr, float a)
{
	float	start = 0.0f;
	float	end = 0.0f;
	float	xo = 0.0f;
	float	y_step = 0.0f;
	float	y;

	start = arr[2];
	end = arr[3];
	y = 0.0f;
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
		my_mlx_pixel_put(cub, h, start++, cu_get_color(cub, xo, y += y_step));
	}
}
