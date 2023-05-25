/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:33:32 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/25 15:02:57 by abdamoha         ###   ########.fr       */
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
	if (cub->map[cub->m.px_index - 1][cub->m.py_index] != '1')
	{
		cub->move_y -= Speed * sin(cub->ray_c.angle); 
		cub->move_x += Speed * cos(cub->ray_c.angle); 
	}
}

void	move_down(t_cub *cub)
{
	if (cub->map[cub->m.px_index + 1][cub->m.py_index] != '1')
	{
		cub->move_y += Speed * sin(cub->ray_c.angle);
		cub->move_x -= Speed * cos(cub->ray_c.angle);
	}
}

void	move_right(t_cub *cub)
{
	if (cub->map[cub->m.px_index][cub->m.py_index + 1] != '1')
	{
		cub->move_x += Speed * cos(cub->ray_c.angle);
		cub->move_y += Speed * sin(cub->ray_c.angle);
	}
}

void	move_left(t_cub *cub)
{
	if (cub->map[cub->m.px_index][cub->m.py_index - 1] != '1')
	{
		cub->move_x -= Speed * cos(cub->ray_c.angle);
		cub->move_y -= Speed * sin(cub->ray_c.angle);
	}
}
