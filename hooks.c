/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:33:32 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/25 18:51:08 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == 123 || keycode == 124 || keycode == 0 || keycode == 1
		|| keycode == 2 || keycode == 13)
	{
		if (keycode == 13)
			move_up(cub);
		else if (keycode == 2)
			move_right(cub);
		else if (keycode == 1)
			move_down(cub);
		else if (keycode == 0)
			move_left(cub);
		else if (keycode == 124)
			rotate_right(cub);
		else if (keycode == 123)
			rotate_left(cub);
	}
	else if (keycode == 53)
		exit(0);
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	drawing(cub);
	return (0);
}

void	move_up(t_cub *cub)
{
	cub->game.map.px_pix += round(SPEED * cos(cub->ray_c.angle));
	cub->game.map.py_pix -= round(SPEED * sin(cub->ray_c.angle));
	cub->move_y -= round(SPEED * sin(cub->ray_c.angle));
	cub->move_x += round(SPEED * cos(cub->ray_c.angle));
	check_horz_vert(cub, 1);
}

void	move_down(t_cub *cub)
{
	cub->game.map.px_pix -= round(SPEED  * cos(cub->ray_c.angle));
	cub->game.map.py_pix += round(SPEED * sin(cub->ray_c.angle));
	cub->move_y += round(SPEED * sin(cub->ray_c.angle));
	cub->move_x -= round(SPEED * cos(cub->ray_c.angle));
	check_horz_vert(cub, 2);
}

void	move_right(t_cub *cub)
{
	cub->game.map.px_pix -= round(SPEED * sin(cub->ray_c.angle));
	cub->game.map.py_pix -= round(SPEED * cos(cub->ray_c.angle));
	cub->move_x += round(SPEED * sin(cub->ray_c.angle));
	cub->move_y += round(SPEED * cos(cub->ray_c.angle));
	check_left_right(cub, 1);
}

void	move_left(t_cub *cub)
{
	cub->game.map.px_pix += round(SPEED * sin(cub->ray_c.angle));
	cub->game.map.py_pix += round(SPEED * cos(cub->ray_c.angle));
	cub->move_x -= round(SPEED * sin(cub->ray_c.angle));
	cub->move_y -= round(SPEED * cos(cub->ray_c.angle));
	check_left_right(cub, 2);
}
