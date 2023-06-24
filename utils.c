/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:13:43 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/24 21:40:32 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
//remember to protect
	if (x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

float	deg_to_rad(int i, t_cub *cub)
{
	float	s;

	s = 0.0;
	s = cub->pi * i / 180.0;
	return (s);
}

int		rad_to_deg(float i, t_cub *cub)
{
	int		s;

	s = 0;
	// printf("i = %f\n", i * cub->pi);
	s = i * 180 / cub->pi;
	// printf("s = %d\n", s);
	return (s);
}

int	exit_w(t_cub *cub)
{
	(void)cub;
	exit(0);
	return (0);
}