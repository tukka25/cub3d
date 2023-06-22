/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:30:41 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/21 18:38:57 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	check_horz_vert(t_cub *cub, int flag)
{
	if (cub->map[cub->m.py_pix / 64][cub->m.px_pix / 64] == '1'
			&& flag == 1)
	{
		cub->m.px_pix -= round(Speed * cos(cub->ray_c.angle));
		cub->m.py_pix += round(Speed * sin(cub->ray_c.angle));
		cub->move_y += round(Speed * sin(cub->ray_c.angle));
		cub->move_x -= round(Speed * cos(cub->ray_c.angle));
	}
	else if (cub->map[cub->m.py_pix / 64][cub->m.px_pix / 64] == '1'
			&& flag == 2)
	{
		cub->m.px_pix += round(Speed  * cos(cub->ray_c.angle));
		cub->m.py_pix -= round(Speed * sin(cub->ray_c.angle));
		cub->move_y -= round(Speed * sin(cub->ray_c.angle));
		cub->move_x += round(Speed * cos(cub->ray_c.angle));
	}
}

void	check_left_right(t_cub *cub, int flag)
{
	if (cub->map[cub->m.py_pix / 64][cub->m.px_pix / 64] == '1'
			&& flag == 1)
	{
		cub->m.px_pix -= round(Speed * sin(cub->ray_c.angle));
		cub->m.py_pix -= round(Speed * cos(cub->ray_c.angle));
		cub->move_x -= round(Speed * sin(cub->ray_c.angle));
		cub->move_y -= round(Speed * cos(cub->ray_c.angle));
	}
	else if (cub->map[cub->m.py_pix / 64][cub->m.px_pix / 64] == '1'
			&& flag == 2)
	{
		cub->m.px_pix += round(Speed * sin(cub->ray_c.angle));
		cub->m.py_pix += round(Speed * cos(cub->ray_c.angle));
		cub->move_x += round(Speed * sin(cub->ray_c.angle));
		cub->move_y += round(Speed * cos(cub->ray_c.angle));
	}
}