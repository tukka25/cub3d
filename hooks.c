/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:33:32 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/10 20:26:41 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == UP || keycode == RIGHT || keycode == DOWN || keycode == LEFT
		|| keycode == A_RIGHT || keycode == A_LEFT)
	{
		if (keycode == UP)
			move_up(cub);
		else if (keycode == RIGHT)
			move_right(cub);
		else if (keycode == DOWN)
			move_down(cub);
		else if (keycode == LEFT)
			move_left(cub);
		else if (keycode == A_RIGHT)
			rotate_right(cub);
		else if (keycode == A_LEFT)
			rotate_left(cub);
	}
	else if (keycode == ESC)
	{
		mlx_destroy_image(cub->mlx.mlx, cub->img.img);
		cu_print_error("Game Over!", cub);
	}
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	drawing(cub);
	return (0);
}

void	move_up(t_cub *cub)
{
	if (check_horz_vert(cub, 1) == 0)
	{
		cub->game.map.px_pix -= SPEED * cos(cub->ray_c.angle);
		cub->game.map.py_pix -= SPEED * sin(cub->ray_c.angle);
	}
}

void	move_down(t_cub *cub)
{
	if (check_horz_vert(cub, 2) == 0)
	{
		cub->game.map.px_pix += SPEED * cos(cub->ray_c.angle);
		cub->game.map.py_pix += SPEED * sin(cub->ray_c.angle);
	}
}

void	move_right(t_cub *cub)
{
	if (check_left_right(cub, 1) == 0)
	{
		cub->game.map.px_pix += SPEED * sin(cub->ray_c.angle);
		cub->game.map.py_pix -= SPEED * cos(cub->ray_c.angle);
	}
}

void	move_left(t_cub *cub)
{
	if (check_left_right(cub, 2) == 0)
	{
		cub->game.map.px_pix -= SPEED * sin(cub->ray_c.angle);
		cub->game.map.py_pix += SPEED * cos(cub->ray_c.angle);
	}
}
