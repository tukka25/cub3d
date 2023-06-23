/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:28:28 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/23 21:28:37 by talsaiaa         ###   ########.fr       */
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