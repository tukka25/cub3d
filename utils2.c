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
