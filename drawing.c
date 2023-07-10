/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:35:38 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/10 20:53:09 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawing(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->mlx.mlx, WIDTH,
			HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	cub->game.map.map_2d[cub->game.map.p_y][cub->game.map.p_x] = '0';
	cast_rays(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.mlx_win,
		cub->img.img, 0, 0);
	return ;
}

void	ray_len_cal(t_cub *cub, float a, float arr[])
{
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

void	looking_right_cal(t_cub *cub, float xo, float yo, float a)
{
	cub->ray_c.xs_v = (((int)cub->game.map.px_pix >> 6) << 6) - 0.0001;
	cub->ray_c.ys_v = (cub->game.map.px_pix - cub->ray_c.xs_v) * (-tan(a))
		+ cub->game.map.py_pix;
	xo = -64;
	yo = -xo * (-tan(a));
	looking_right(cub, a, yo, xo);
}

void	looking_left_cal(t_cub *cub, float xo, float yo, float a)
{
	cub->ray_c.xs_v = (((int)cub->game.map.px_pix >> 6) << 6) + 64;
	cub->ray_c.ys_v = (cub->game.map.px_pix - cub->ray_c.xs_v) * (-tan(a))
		+ cub->game.map.py_pix;
	xo = 64;
	yo = -xo * (-tan(a));
	looking_left(cub, xo, yo);
}
