/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:24:40 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/07/09 22:24:10 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*cu_first_coordinate(t_cub *cub)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (&cub->n_texture);
	else
		return (&cub->e_texture);
}

t_img	*cu_second_coordinate(t_cub *cub)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (&cub->n_texture);
	else
		return (&cub->w_texture);
}

t_img	*cu_third_coordinate(t_cub *cub)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (&cub->s_texture);
	else
		return (&cub->w_texture);
}

t_img	*cu_fourth_coordinate(t_cub *cub)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (&cub->s_texture);
	else
		return (&cub->e_texture);
}

void	looking_up(t_cub *cub, int a, float yo, float xo)
{
	// float	yo;
	// float	xo;

	// cub->ray_c.ys_h = (((int)cub->game.map.py_pix >> 6) << 6) - 0.0001;
	// cub->ray_c.xs_h = (py - cub->ray_c.ys_h) * (-1 / tan(a)) + px;
	(void)a;
	while (1)
		{
			if ((int)cub->ray_c.ys_v <= 0 || (int)cub->ray_c.ys_v
				/ cub->game.map.scale_y >= cub->game.map.nline
				|| (int)cub->ray_c.xs_v <= 0 || (int)cub->ray_c.xs_v
				/ cub->game.map.scale_x >= ft_strlen(cub->game.map.map_2d[(int)
						(cub->ray_c.ys_v / cub->game.map.scale_y)]))
				break ;
			if (cub->game.map.map_2d[(int)(cub->ray_c.ys_v
					/ cub->game.map.scale_y)][(int)(cub->ray_c.xs_v
				/ cub->game.map.scale_x)] != '0')
				break ;
			cub->ray_c.xs_v += xo;
			cub->ray_c.ys_v += yo;
		}
}
