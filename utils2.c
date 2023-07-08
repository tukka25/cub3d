/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 02:02:59 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/08 22:20:48 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*cu_first_coordinate(t_cub *cub, int y, int x)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (cub->n_texture.addr + (y * cub->n_texture.line_length + x
				* (cub->n_texture.bits_per_pixel / 8)));
	else
		return (cub->e_texture.addr + (y * cub->e_texture.line_length + x
				* (cub->e_texture.bits_per_pixel / 8)));
}

char	*cu_second_coordinate(t_cub *cub, int y, int x)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (cub->n_texture.addr + (y * cub->n_texture.line_length + x
				* (cub->n_texture.bits_per_pixel / 8)));
	else
		return (cub->w_texture.addr + (y * cub->w_texture.line_length + x
				* (cub->w_texture.bits_per_pixel / 8)));
}

char	*cu_third_coordinate(t_cub *cub, int y, int x)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (cub->s_texture.addr + (y * cub->s_texture.line_length + x
				* (cub->s_texture.bits_per_pixel / 8)));
	else
		return (cub->w_texture.addr + (y * cub->w_texture.line_length + x
				* (cub->w_texture.bits_per_pixel / 8)));
}

char	*cu_fourth_coordinate(t_cub *cub, int y, int x)
{
	if (cub->ray_c.tmp_length > cub->ray_c.ray_length)
		return (cub->s_texture.addr + (y * cub->s_texture.line_length + x
				* (cub->s_texture.bits_per_pixel / 8)));
	else
		return (cub->e_texture.addr + (y * cub->e_texture.line_length + x
				* (cub->e_texture.bits_per_pixel / 8)));
}
