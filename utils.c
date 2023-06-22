/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:00:47 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/22 14:48:30 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen_2d(char **str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || y >= cub->m.height * 64
	 || x >= cub->m.width * 64)
		return ;
	dst = cub->img.addr + (y * cub->img.line_length + x * (cub->img.bits_per_pixel / 8));
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