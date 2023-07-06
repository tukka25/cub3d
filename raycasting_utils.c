/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:34:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/07 01:00:55 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	convert_angle(t_cub *cub)
{
	// printf("p_direction = %d\n", cub->game.map.p_direction);
	if (cub->game.map.p_direction == 'N')
		cub->ray_c.angle = deg_to_rad(90, cub);
	else if (cub->game.map.p_direction == 'S')
		cub->ray_c.angle = deg_to_rad(270, cub);
	else if (cub->game.map.p_direction == 'W')
		cub->ray_c.angle = deg_to_rad(180, cub);
	else if (cub->game.map.p_direction == 'E')
		cub->ray_c.angle = deg_to_rad(0, cub);
}

void	scaling(t_cub *cub)
{
	printf("c = %d\n", cub->game.map.map_width - 1);
	cub->game.map.px_pix = cub->game.map.p_x;
	cub->game.map.py_pix = cub->game.map.p_y;
}

// int	rgb_to_hex(int)
// {
	
// }

void	draw_floor_ceiling(t_cub *cub, int c1, int c2)
{
	int	i;
	// int	j;
	double	arr[4];

	i = 0;
	// j = 0;
	(void)c2;
	arr[0] = 0;
	arr[1] = WIDTH;
	arr[2] = 0;
	arr[3] = 0;
	while (i < HEIGHT / 2)
	{
		draw_line(cub, arr, c1);
		arr[2]++;
		arr[3]++;
		i++;
	}
	while (i < HEIGHT)
	{
		draw_line(cub, arr, c2);
		arr[2]++;
		arr[3]++;
		i++;
	}
}