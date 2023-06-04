/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:33:32 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/04 16:36:34 by abdamoha         ###   ########.fr       */
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

	// cub->m.py_pix -= Speed;
	a = rad_to_deg(cub->ray_c.angle, cub);
	if (a > 0 && a < 90)
	{
		// printf("before x = %d\n", cub->m.px_pix);
		// printf("before y = %d\n", cub->m.py_pix);
		cub->m.px_pix += Speed * cos(cub->ray_c.angle);
		cub->m.py_pix -= Speed * sin(cub->ray_c.angle);
		// printf("After x = %d\n", cub->m.px_pix);
		// printf("After y = %d\n", cub->m.py_pix);
	}
	else if (a > 90 && a < 180)
	{
		printf("before x = %d\n", cub->m.px_pix);
		printf("before y = %d\n", cub->m.py_pix);
		cub->m.px_pix += Speed * cos(cub->ray_c.angle);
		cub->m.py_pix -= Speed * sin(cub->ray_c.angle);
		printf("After x = %d\n", cub->m.px_pix);
		printf("After y = %d\n", cub->m.py_pix);
	}
	else if (a > 180 && a < 270)
	{
		printf("before x = %d\n", cub->m.px_pix);
		printf("before y = %d\n", cub->m.py_pix);
		cub->m.px_pix += Speed  * cos(cub->ray_c.angle);
		cub->m.py_pix -= Speed * sin(cub->ray_c.angle);
		printf("After x = %d\n", cub->m.px_pix);
		printf("After y = %d\n", cub->m.py_pix);
	}
	else if (a > 270 && a < 360)
	{
		cub->m.px_pix += Speed * cos(cub->ray_c.angle);
		cub->m.py_pix -= Speed * sin(cub->ray_c.angle);
	}
	cub->move_y -= Speed * sin(cub->ray_c.angle); 
	cub->move_x += Speed * cos(cub->ray_c.angle); 
}

void	move_down(t_cub *cub)
{
	int	a;

	a = rad_to_deg(cub->ray_c.angle, cub);
	if (a > 0 && a < 90)
	{
		printf("before x = %d\n", cub->m.px_pix);
		printf("before y = %d\n", cub->m.py_pix);
		cub->m.px_pix -= Speed * cos(cub->ray_c.angle);
		cub->m.py_pix += Speed * sin(cub->ray_c.angle);
		printf("After x = %d\n", cub->m.px_pix);
		printf("After y = %d\n", cub->m.py_pix);
	}
	else if (a > 90 && a < 180)
	{
		cub->m.px_pix += Speed  * cos(cub->ray_c.angle);
		cub->m.py_pix += Speed * sin(cub->ray_c.angle);
	}
	else if (a > 180 && a < 270)
	{
		cub->m.px_pix += Speed  * cos(cub->ray_c.angle);
		cub->m.py_pix -= Speed * sin(cub->ray_c.angle);
	}
	else if (a > 270 && a < 360)
	{
		cub->m.px_pix -= Speed  * cos(cub->ray_c.angle);
		cub->m.py_pix -= Speed * sin(cub->ray_c.angle);
	}
	cub->move_y += Speed * sin(cub->ray_c.angle);
	cub->move_x -= Speed * cos(cub->ray_c.angle);
}

void	move_right(t_cub *cub)
{
	// static int	i;
	int			a;

	// if (i == 64)
	// {
	// 	i = 0;
	// 	if (cub->map[cub->m.py_index][cub->m.px_index + 1] != '1')
	// 	{
	// 		cub->map[cub->m.py_index][cub->m.px_index + 1] = cub->m.cord;
	// 		cub->m.px_pix += 64;
	// 	}
	// }
	// cub->m.px_pix += Speed;
	a = rad_to_deg(cub->ray_c.angle, cub);
	if (a == 0 || a == 360)
	{
		cub->m.px_pix += Speed;
		cub->move_y += Speed;
	}
	else if ((a > 0 && a < 90))
	{
		// printf("px = %d\n", cub->m.px_pix);
		cub->m.px_pix += Speed;
		// printf("px = %d\n", cub->m.px_pix);
		cub->m.py_pix += Speed;
		cub->move_x += Speed * sin(cub->ray_c.angle);
		cub->move_y += Speed * cos(cub->ray_c.angle);
	}
	else if (a > 90 && a < 180)
	{
		cub->m.px_pix += Speed;
		cub->m.py_pix -= Speed;
		cub->move_x += Speed * sin(cub->ray_c.angle);
		cub->move_y += Speed * cos(cub->ray_c.angle);
	} 
	else if (a > 180 && a < 270)
	{
		cub->m.px_pix -= Speed;
		cub->m.py_pix -= Speed;
		cub->move_x += Speed * sin(cub->ray_c.angle);
		cub->move_y += Speed * cos(cub->ray_c.angle);
	}
	else if (a > 270 && a < 360)
	{
		cub->m.px_pix -= Speed;
		cub->m.py_pix += Speed;
		cub->move_x += Speed * sin(cub->ray_c.angle);
		cub->move_y += Speed * cos(cub->ray_c.angle);
	}
	else
	{
		cub->m.px_pix += Speed;
		cub->move_x += Speed;
	}
	// i += Speed;
}

void	move_left(t_cub *cub)
{
	int		a;

	a = rad_to_deg(cub->ray_c.angle, cub);
	if (a == 0 || a == 360)
	{
		cub->m.px_pix -= Speed;
		cub->move_y -= Speed;
	}
	else if ((a > 0 && a < 90))
	{
		cub->m.px_pix -= Speed;
		cub->m.py_pix -= Speed;
		cub->move_x -= Speed * sin(cub->ray_c.angle);
		cub->move_y -= Speed * cos(cub->ray_c.angle);
	}
	else if (a > 90 && a < 180)
	{
		cub->m.px_pix -= Speed;
		cub->m.py_pix -= Speed;
		cub->move_x -= Speed * sin(cub->ray_c.angle);
		cub->move_y -= Speed * cos(cub->ray_c.angle);
	}
	else if (a > 180 && a < 270)
	{
		cub->m.px_pix += Speed;
		cub->m.py_pix += Speed;
		cub->move_x += -Speed * sin(cub->ray_c.angle);
		cub->move_y += -Speed * cos(cub->ray_c.angle);
	}
	else if (a > 270 && a < 360)
	{
		cub->m.px_pix += Speed;
		cub->m.py_pix += Speed;
		cub->move_x -= Speed * sin(cub->ray_c.angle);
		cub->move_y -= Speed * cos(cub->ray_c.angle);
	}
	else
	{
		cub->m.px_pix -= Speed;
		cub->move_x -= Speed;
	}
}
