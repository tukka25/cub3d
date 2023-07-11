/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:13:43 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/07/10 21:28:23 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || y >= HEIGHT || x >= WIDTH)
		return ;
	dst = cub->img.addr + (y * cub->img.line_length + x
			* (cub->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

double	deg_to_rad(int i, t_cub *cub)
{
	double	s;

	s = 0.0;
	(void)cub;
	s = M_PI * i / 180.0;
	return (s);
}

int	rad_to_deg(double i, t_cub *cub)
{
	int		s;

	s = 0;
	(void)cub;
	s = i * 180 / M_PI;
	return (s);
}

void	init_vals(t_cub *cub, int arr[])
{
	cub->ray_c.sx = -1;
	cub->ray_c.sy = -1;
	if (arr[0] < arr[2])
		cub->ray_c.sx = 1;
	if (arr[1] < arr[3])
		cub->ray_c.sy = 1;
	cub->ray_c.dx = abs(arr[2] - arr[0]);
	cub->ray_c.dy = abs(arr[3] - arr[1]);
	cub->ray_c.err = cub->ray_c.dx - cub->ray_c.dy;
}

void	convert_fisheye_a(t_cub *cub)
{
	if (cub->ray_c.f < 0)
		cub->ray_c.f += 2 * M_PI;
	else if (cub->ray_c.f > 2 * M_PI)
		cub->ray_c.f -= 2 * M_PI;
}
