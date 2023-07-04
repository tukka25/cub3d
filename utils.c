/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:13:43 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/07/04 21:05:19 by talsaiaa         ###   ########.fr       */
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

int		cu_get_color(t_cub *cub, int x, int y)
{
	int		color;
	char	*dst;

	dst = cub->texture.addr + (y * cub->texture.line_length + x * (cub->texture.bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

float	deg_to_rad(int i, t_cub *cub)
{
	float	s;

	s = 0.0;
	(void)cub;
	s = M_PI * i / 180.0;
	return (s);
}

int		rad_to_deg(float i, t_cub *cub)
{
	int		s;

	s = 0;
	(void)cub;

	// printf("i = %f\n", i * M_PI);
	s = i * 180 / M_PI;
	// printf("s = %d\n", s);
	return (s);
}

int	exit_w(t_cub *cub)
{
	(void)cub;
	exit(0);
	return (0);
}