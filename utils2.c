/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:24:40 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/07/09 22:24:10 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*cu_first_coordinate(t_cub *cub)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (&cub->n_texture);
	else
		return (&cub->e_texture);
}

t_img	*cu_second_coordinate(t_cub *cub)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (&cub->n_texture);
	else
		return (&cub->w_texture);
}

t_img	*cu_third_coordinate(t_cub *cub)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (&cub->s_texture);
	else
		return (&cub->w_texture);
}

t_img	*cu_fourth_coordinate(t_cub *cub)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (&cub->s_texture);
	else
		return (&cub->e_texture);
}

void	looking_right(t_cub *cub, int a, float yo, float xo)
{
	// float	yo;
	// float	xo;

	// cub->ray_c.ys_h = (((int)cub->game.map.py_pix >> 6) << 6) - 0.0001;
	// cub->ray_c.xs_h = (py - cub->ray_c.ys_h) * (-1 / tan(a)) + px;
	(void)a;
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
}

void	looking_up(t_cub *cub, float yo, float xo)
{
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
}

void	looking_down(t_cub *cub, float yo, float xo)
{
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
}

void	looking_left(t_cub *cub, float xo, float yo)
{
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
}

void	looking_up_cal(t_cub *cub, float yo, float xo, float a)
{
	cub->ray_c.ys_h = (((int)cub->game.map.py_pix >> 6) << 6) - 0.0001;
	cub->ray_c.xs_h = (cub->game.map.py_pix - cub->ray_c.ys_h) * (-1 / tan(a)) + cub->game.map.px_pix;
	yo = -64;
	xo = -yo * (-1 / tan(a));
	looking_up(cub, yo, xo);
}

void	looking_down_cal(t_cub *cub, float xo, float yo, float a)
{
	cub->ray_c.ys_h = (((int)cub->game.map.py_pix >> 6) << 6) + 64;
	cub->ray_c.xs_h = (cub->game.map.py_pix - cub->ray_c.ys_h) * (-1 / tan(a)) + cub->game.map.px_pix;
	yo = 64;
	xo = -yo * (-1 / tan(a));
	looking_down(cub, yo, xo);
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
	cub->ray_c.ys_v = (cub->game.map.px_pix - cub->ray_c.xs_v) * (-tan(a)) + cub->game.map.py_pix;
	xo = -64;
	yo = -xo * (-tan(a));
	looking_right(cub, a, yo, xo);
}

void	looking_left_cal(t_cub *cub, float xo, float yo, float a)
{
	cub->ray_c.xs_v = (((int)cub->game.map.px_pix >> 6) << 6) + 64;
	cub->ray_c.ys_v = (cub->game.map.px_pix - cub->ray_c.xs_v) * (-tan(a)) + cub->game.map.py_pix;
	xo = 64;
	yo = -xo * (-tan(a));
	looking_left(cub, xo, yo);
}