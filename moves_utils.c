/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:30:41 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/09 01:22:48 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_horz_vert(t_cub *cub, int flag)
{
	float	x;
	float	y;

	x = (((int)cub->game.map.px_pix >> 6) << 6);
	y = (((int)cub->game.map.py_pix >> 6) << 6);
	printf("y = %d\n", (((int)(y) / cub->game.map.scale_y)));
	printf("y = %d\n", (int)floor((x) / cub->game.map.scale_x));
	if ((cub->game.map.map_2d[(int)((y) / cub->game.map.scale_y)]
		[(int)((cub->game.map.px_pix) / cub->game.map.scale_x)] != '0'
			&& flag == 1))
	{
		printf("hi\n");
		cub->game.map.px_pix += round(16 * cos(cub->ray_c.angle));
		cub->game.map.py_pix += round(16 * sin(cub->ray_c.angle));
	}
	else if (cub->game.map.map_2d[(int)(y
			/ cub->game.map.scale_y)]
	[(int)(cub->game.map.px_pix / cub->game.map.scale_x)] == '1'
			&& flag == 2)
	{
		return (1);
	}
	return (0);
}

void	check_left_right(t_cub *cub, int flag)
{
	if (cub->game.map.map_2d[(int)(cub->game.map.py_pix
			/ cub->game.map.scale_y)]
	[(int)(cub->game.map.px_pix / cub->game.map.scale_x)] == '1' && flag == 1)
	{
		cub->game.map.px_pix += 16 * sin(cub->ray_c.angle);
		cub->game.map.py_pix -= 16 * cos(cub->ray_c.angle);
	}
	else if (cub->game.map.map_2d[(int)(cub->game.map.py_pix
			/ cub->game.map.scale_y)]
	[(int)(cub->game.map.px_pix / cub->game.map.scale_x)] == '1' && flag == 2)
	{
		cub->game.map.px_pix -= 16 * sin(cub->ray_c.angle);
		cub->game.map.py_pix += 16 * cos(cub->ray_c.angle);
	}
	return ;
}

void	rayc_init(t_cub *cub)
{
	cub->ray_c.arr = malloc(4 * sizeof(float));
	cub->ray_c.x1 = cub->game.map.px_pix;
	cub->ray_c.h = 0;
	cub->ray_c.f = 0;
	cub->ray_c.a = cub->ray_c.angle - deg_to_rad(45, cub);
}

void	floor_ceiling(t_cub *cub)
{
	draw_line(cub, (float []){cub->ray_c.arr[0], cub->ray_c.arr[1],
			0, cub->ray_c.arr[2]}, cub->game.ceiling);
		draw_line(cub, (float []){cub->ray_c.arr[0], cub->ray_c.arr[1],
			cub->ray_c.arr[3], HEIGHT}, cub->game.floor);
		cub->ray_c.arr[0]++;
		cub->ray_c.arr[1]++;
		cub->ray_c.h++;
}

void	looking_up_calculations(t_cub *cub, int a)
{
	float	xo;
	float	yo;

	xo = 0.0;
	yo = 0.0;
	cub->ray_c.xs_v = (((int)cub->game.map.px_pix >> 6) << 6) - 0.0001;
	cub->ray_c.ys_v = (cub->game.map.px_pix - cub->ray_c.xs_v) * (-tan(a)) + cub->game.map.py_pix;
	xo = -64;
	yo = -xo * (-tan(a));
	looking_up(cub, a, yo, xo);
}