/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:35:38 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/08 20:41:13 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawing(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->mlx.mlx, WIDTH,
				HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	cub->game.map.map_2d[cub->game.map.p_y][cub->game.map.p_x] = '0';
	cast_rays(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.mlx_win,
		cub->img.img, 0, 0);
}
