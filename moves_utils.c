/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:30:41 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/07 01:14:03 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_horz_vert(t_cub *cub, int flag)
{
	if (cub->game.map.map_2d[(int)(cub->game.map.py_pix)][(int)(cub->game.map.px_pix)] == '1'
			&& flag == 1)
	{
		cub->game.map.px_pix -= SPEED * cos(cub->ray_c.angle);
		cub->game.map.py_pix += SPEED * sin(cub->ray_c.angle);
		cub->move_y += SPEED * sin(cub->ray_c.angle);
		cub->move_x -= SPEED * cos(cub->ray_c.angle);
	}
	else if (cub->game.map.map_2d[(int)(cub->game.map.py_pix)][(int)(cub->game.map.px_pix)] == '1'
			&& flag == 2)
	{
		cub->game.map.px_pix += SPEED  * cos(cub->ray_c.angle);
		cub->game.map.py_pix -= SPEED * sin(cub->ray_c.angle);
		cub->move_y -= SPEED * sin(cub->ray_c.angle);
		cub->move_x += SPEED * cos(cub->ray_c.angle);
	}
}

void	check_left_right(t_cub *cub, int flag)
{
	if (cub->game.map.map_2d[(int)(cub->game.map.py_pix)][(int)(cub->game.map.px_pix)] == '1'
			&& flag == 1)
	{
		cub->game.map.px_pix += SPEED * sin(cub->ray_c.angle);
		cub->game.map.py_pix += SPEED * cos(cub->ray_c.angle);
		cub->move_x -= SPEED * sin(cub->ray_c.angle);
		cub->move_y -= SPEED * cos(cub->ray_c.angle);
	}
	else if (cub->game.map.map_2d[(int)(cub->game.map.py_pix)][(int)(cub->game.map.px_pix)] == '1'
			&& flag == 2)
	{
		cub->game.map.px_pix -= SPEED * sin(cub->ray_c.angle);
		cub->game.map.py_pix -= SPEED * cos(cub->ray_c.angle);
		cub->move_x += SPEED * sin(cub->ray_c.angle);
		cub->move_y += SPEED * cos(cub->ray_c.angle);
	}
}