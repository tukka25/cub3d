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

void	check_horz_vert(t_cub *cub, int flag)
{
	if (cub->game.map.map_2d[(int)(cub->game.map.py_pix
			/ cub->game.map.scale_y)]
	[(int)(cub->game.map.px_pix / cub->game.map.scale_x)] == '1'
			&& flag == 1)
	{
		cub->game.map.px_pix += 64 * cos(cub->ray_c.angle);
		cub->game.map.py_pix += 64 * sin(cub->ray_c.angle);
	}
	else if (cub->game.map.map_2d[(int)(cub->game.map.py_pix
			/ cub->game.map.scale_y)]
	[(int)(cub->game.map.px_pix / cub->game.map.scale_x)] == '1'
			&& flag == 2)
	{
		cub->game.map.px_pix -= 16 * cos(cub->ray_c.angle);
		cub->game.map.py_pix -= 16 * sin(cub->ray_c.angle);
	}
	return ;
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
