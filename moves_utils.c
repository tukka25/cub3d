/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:30:41 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/10 20:48:04 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_horz_vert(t_cub *cub, int flag)
{
	float	x;
	float	y;
	float	n;
	float	k;

	n = SPEED * cos(cub->ray_c.angle);
	k = SPEED * sin(cub->ray_c.angle);
	x = cub->game.map.px_pix;
	y = cub->game.map.py_pix;
	if ((cub->game.map.map_2d[(int)floor((y - k * 4) / cub->game.map.scale_y)]
			[(int)floor((x - n * 4) / cub->game.map.scale_x)] == '1'
			&& flag == 1))
	{
		return (1);
	}
	else if (cub->game.map.map_2d[(int)floor((y + k * 2)
				/ cub->game.map.scale_y)]
		[(int)((x + n * 2) / cub->game.map.scale_x)] == '1'
				&& flag == 2)
	{
		return (1);
	}
	return (0);
}

int	check_left_right(t_cub *cub, int flag)
{
	float	x;
	float	y;
	float	n;
	float	k;

	n = SPEED * cos(cub->ray_c.angle);
	k = SPEED * sin(cub->ray_c.angle);
	x = cub->game.map.px_pix;
	y = cub->game.map.py_pix;
	if (cub->game.map.map_2d[(int)((y - n * 2) / cub->game.map.scale_y)]
	[(int)((x + k * 2) / cub->game.map.scale_x)] == '1' && flag == 1)
	{
		return (1);
	}
	else if (cub->game.map.map_2d[(int)((y + n * 2)
			/ cub->game.map.scale_y)]
	[(int)((x - k * 2) / cub->game.map.scale_x)] == '1' && flag == 2)
	{
		return (1);
	}
	return (0);
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
