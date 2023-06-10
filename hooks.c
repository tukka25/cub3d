/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:33:32 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/10 19:12:12 by abdamoha         ###   ########.fr       */
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
	int	a;

	a = rad_to_deg(cub->ray_c.angle, cub);
	if (a == 0 || a == 360)
	{
		cub->m.px_pix += Speed;
	}
	else if (a == 90)
	{
		cub->m.py_pix -= round(Speed * sin(cub->ray_c.angle));
	}
	else if (a > 0 && a < 90)
	{
		cub->m.px_pix += round(Speed * cos(cub->ray_c.angle));
		cub->m.py_pix -= round(Speed * sin(cub->ray_c.angle));
	}
	else if (a > 90 && a < 180)
	{
		cub->m.px_pix += round(Speed * cos(cub->ray_c.angle));
		cub->m.py_pix -= round(Speed * sin(cub->ray_c.angle));
	}
	else if (a > 180 && a < 270)
	{
		cub->m.px_pix += round(Speed  * cos(cub->ray_c.angle));
		cub->m.py_pix -= round(Speed * sin(cub->ray_c.angle));
	}
	else if (a > 270 && a < 360)
	{
		cub->m.px_pix += round(Speed * cos(cub->ray_c.angle));
		cub->m.py_pix -= round(Speed * sin(cub->ray_c.angle));
	}
	cub->move_y -= round(Speed * sin(cub->ray_c.angle));
	cub->move_x += round(Speed * cos(cub->ray_c.angle));
}

void	move_down(t_cub *cub)
{
	int	a;

	a = rad_to_deg(cub->ray_c.angle, cub);
	if (a == 0 || a == 360)
	{
		cub->m.px_pix -= Speed;
	}
	if (a == 90)
	{
		cub->m.py_pix += round(Speed * sin(cub->ray_c.angle));
	}
	if (a > 0 && a < 90)
	{
		cub->m.px_pix -= round(Speed * cos(cub->ray_c.angle));
		cub->m.py_pix += round(Speed * sin(cub->ray_c.angle));
	}
	else if (a > 90 && a < 180)
	{
		cub->m.px_pix -= round(Speed  * cos(cub->ray_c.angle));
		cub->m.py_pix += round(Speed * sin(cub->ray_c.angle));
	}
	else if (a > 180 && a < 270)
	{
		cub->m.px_pix -= round(Speed  * cos(cub->ray_c.angle));
		cub->m.py_pix += round(Speed * sin(cub->ray_c.angle));
	}
	else if (a > 270 && a < 360)
	{
		cub->m.px_pix -= round(Speed  * cos(cub->ray_c.angle));
		cub->m.py_pix += round(Speed * sin(cub->ray_c.angle));
	}
	cub->move_y += round(Speed * sin(cub->ray_c.angle));
	cub->move_x -= round(Speed * cos(cub->ray_c.angle));
}

void	move_right(t_cub *cub)
{
	int			a;

	a = rad_to_deg(cub->ray_c.angle, cub);
	if (a == 0 || a == 360)
	{
		cub->m.py_pix += Speed;
		cub->move_y += Speed;
	}
	else if ((a > 0 && a < 90))
	{
		cub->m.px_pix += round(Speed * sin(cub->ray_c.angle));
		cub->m.py_pix += round(Speed * cos(cub->ray_c.angle));
		cub->move_x += round(Speed * sin(cub->ray_c.angle));
		cub->move_y += round(Speed * cos(cub->ray_c.angle));
	}
	else if (a > 90 && a < 180)
	{
		cub->m.px_pix += round(Speed * sin(cub->ray_c.angle));
		cub->m.py_pix += round(Speed * cos(cub->ray_c.angle));
		cub->move_x += round(Speed * sin(cub->ray_c.angle));
		cub->move_y += round(Speed * cos(cub->ray_c.angle));
	} 
	else if (a > 180 && a < 270)
	{
		cub->m.px_pix += round(Speed * sin(cub->ray_c.angle));
		cub->m.py_pix += round(Speed * cos(cub->ray_c.angle));
		cub->move_x += round(Speed * sin(cub->ray_c.angle));
		cub->move_y += round(Speed * cos(cub->ray_c.angle));
	}
	else if (a > 270 && a < 360)
	{
		cub->m.px_pix += round(Speed * sin(cub->ray_c.angle));
		cub->m.py_pix += round(Speed * cos(cub->ray_c.angle));
		cub->move_x += round(Speed * sin(cub->ray_c.angle));
		cub->move_y += round(Speed * cos(cub->ray_c.angle));
	}
	else
	{
		cub->m.px_pix += Speed;
		cub->move_x += Speed;
	}
}

void	move_left(t_cub *cub)
{
	int		a;

	a = rad_to_deg(cub->ray_c.angle, cub);
	if (a == 0 || a == 360)
	{
		cub->m.py_pix -= Speed;
		cub->move_y -= Speed;
	}
	else if ((a > 0 && a < 90))
	{
		cub->m.px_pix -= round(Speed * sin(cub->ray_c.angle));
		cub->m.py_pix -= round(Speed * cos(cub->ray_c.angle));
		cub->move_x -= round(Speed * sin(cub->ray_c.angle));
		cub->move_y -= round(Speed * cos(cub->ray_c.angle));
	}
	else if (a > 90 && a < 180)
	{
		cub->m.px_pix -= round(Speed * sin(cub->ray_c.angle));
		cub->m.py_pix -= round(Speed * cos(cub->ray_c.angle));
		cub->move_x -= round(Speed * sin(cub->ray_c.angle));
		cub->move_y -= round(Speed * cos(cub->ray_c.angle));
	}
	else if (a > 180 && a < 270)
	{
		cub->m.px_pix -= round(Speed * sin(cub->ray_c.angle));
		cub->m.py_pix -= round(Speed * cos(cub->ray_c.angle));
		cub->move_x -= round(Speed * sin(cub->ray_c.angle));
		cub->move_y -= round(Speed * cos(cub->ray_c.angle));
	}
	else if (a > 270 && a < 360)
	{
		cub->m.px_pix -= round(Speed * sin(cub->ray_c.angle));
		cub->m.py_pix -= round(Speed * cos(cub->ray_c.angle));
		cub->move_x -= round(Speed * sin(cub->ray_c.angle));
		cub->move_y -= round(Speed * cos(cub->ray_c.angle));
	}
	else
	{
		cub->m.px_pix -= Speed;
		cub->move_x -= Speed;
	}
}
