/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:37:47 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/10 21:36:09 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_cub *cub)
{
	if (cub->ray_c.angle + 0.05 > deg_to_rad(360, cub))
		cub->ray_c.angle = deg_to_rad(0, cub);
	cub->ray_c.angle += 0.05;
	cub->ray_c.pdx = cos(cub->ray_c.angle) * SPEED;
	cub->ray_c.pdy = sin(cub->ray_c.angle) * SPEED;
	return ;
}

void	rotate_left(t_cub *cub)
{
	if (cub->ray_c.angle - 0.05 < 0)
		cub->ray_c.angle = deg_to_rad(360, cub);
	cub->ray_c.angle -= 0.05;
	cub->ray_c.pdx = cos(cub->ray_c.angle) * SPEED;
	cub->ray_c.pdy = sin(cub->ray_c.angle) * SPEED;
	return ;
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
		if (cub->game.map.map_2d[(int)(cub->ray_c.ys_h / cub->game.map.scale_y)]
			[(int)(cub->ray_c.xs_h / cub->game.map.scale_x)] != '0')
			break ;
		cub->ray_c.ys_h += yo;
		cub->ray_c.xs_h += xo;
	}
}

void	looking_up_cal(t_cub *cub, float yo, float xo, float a)
{
	cub->ray_c.ys_h = (((int)cub->game.map.py_pix >> 6) << 6) - 0.0001;
	cub->ray_c.xs_h = (cub->game.map.py_pix - cub->ray_c.ys_h) * (-1 / tan(a))
		+ cub->game.map.px_pix;
	yo = -64;
	xo = -yo * (-1 / tan(a));
	looking_up(cub, yo, xo);
}

void	looking_down_cal(t_cub *cub, float xo, float yo, float a)
{
	cub->ray_c.ys_h = (((int)cub->game.map.py_pix >> 6) << 6) + 64;
	cub->ray_c.xs_h = (cub->game.map.py_pix - cub->ray_c.ys_h) * (-1 / tan(a))
		+ cub->game.map.px_pix;
	yo = 64;
	xo = -yo * (-1 / tan(a));
	looking_down(cub, yo, xo);
}
