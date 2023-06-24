/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:30:41 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/24 22:03:06 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	check_horz_vert(t_cub *cub, int flag)
{
	if (cub->game.map.map_2d[(int)(cub->game.map.py_pix / cub->game.map.scale_y)][(int)(cub->game.map.px_pix / cub->game.map.scale_x)] == '1'
			&& flag == 1)
	{
		cub->game.map.px_pix -= round(SPEED * cos(cub->ray_c.angle));
		cub->game.map.py_pix += round(SPEED * sin(cub->ray_c.angle));
		cub->move_y += round(SPEED * sin(cub->ray_c.angle));
		cub->move_x -= round(SPEED * cos(cub->ray_c.angle));
	}
	else if (cub->game.map.map_2d[(int)(cub->game.map.py_pix / cub->game.map.scale_y)][(int)(cub->game.map.px_pix / cub->game.map.scale_x)] == '1'
			&& flag == 2)
	{
		cub->game.map.px_pix += round(SPEED  * cos(cub->ray_c.angle));
		cub->game.map.py_pix -= round(SPEED * sin(cub->ray_c.angle));
		cub->move_y -= round(SPEED * sin(cub->ray_c.angle));
		cub->move_x += round(SPEED * cos(cub->ray_c.angle));
	}
}

void	check_left_right(t_cub *cub, int flag)
{
	if (cub->game.map.map_2d[(int)(cub->game.map.py_pix / cub->game.map.scale_y)][(int)(cub->game.map.px_pix / cub->game.map.scale_x)] == '1'
			&& flag == 1)
	{
		cub->game.map.px_pix -= round(SPEED * sin(cub->ray_c.angle));
		cub->game.map.py_pix -= round(SPEED * cos(cub->ray_c.angle));
		cub->move_x -= round(SPEED * sin(cub->ray_c.angle));
		cub->move_y -= round(SPEED * cos(cub->ray_c.angle));
	}
	else if (cub->game.map.map_2d[(int)(cub->game.map.py_pix / cub->game.map.scale_y)][(int)(cub->game.map.px_pix / cub->game.map.scale_x)] == '1'
			&& flag == 2)
	{
		cub->game.map.px_pix += round(SPEED * sin(cub->ray_c.angle));
		cub->game.map.py_pix += round(SPEED * cos(cub->ray_c.angle));
		cub->move_x += round(SPEED * sin(cub->ray_c.angle));
		cub->move_y += round(SPEED * cos(cub->ray_c.angle));
	}
}