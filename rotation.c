/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:37:47 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/31 14:55:23 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_cub *cub)
{
	if (cub->ray_c.angle - 0.05 < 0)
		cub->ray_c.angle = deg_to_rad(360, cub);
	cub->ray_c.angle -= 0.05;
	cub->ray_c.pdx = cos(cub->ray_c.angle) * 5;
	cub->ray_c.pdy = sin(cub->ray_c.angle) * 5;
	printf("angle = %f\n", cub->ray_c.angle * 180 / M_PI);
}

void	rotate_left(t_cub *cub)
{
	if (cub->ray_c.angle + 0.05 > deg_to_rad(360, cub))
		cub->ray_c.angle = deg_to_rad(0, cub);
	cub->ray_c.angle += 0.05;
	cub->ray_c.pdx = cos(cub->ray_c.angle) * 5;
	cub->ray_c.pdy = sin(cub->ray_c.angle) * 5;
	printf("angle = %f\n", cub->ray_c.angle * 180 / M_PI);
}
