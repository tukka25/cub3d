/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:13:43 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/07/08 20:54:15 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || y >= HEIGHT
	 || x >= WIDTH)
		return ;
	dst = cub->img.addr + (y * cub->img.line_length + x * (cub->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double	deg_to_rad(int i, t_cub *cub)
{
	double	s;

	s = 0.0;
	(void)cub;
	s = M_PI * i / 180.0;
	return (s);
}

int		rad_to_deg(double i, t_cub *cub)
{
	int		s;

	s = 0;
	(void)cub;

	s = i * 180 / M_PI;
	return (s);
}

int	exit_w(t_cub *cub)
{
	(void)cub;
	exit(0);
	return (0);
}