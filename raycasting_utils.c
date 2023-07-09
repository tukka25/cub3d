/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:34:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/09 22:25:17 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_angle(t_cub *cub)
{
	if (cub->game.map.p_direction == 'N')
		cub->ray_c.angle = deg_to_rad(90, cub);
	else if (cub->game.map.p_direction == 'S')
		cub->ray_c.angle = deg_to_rad(270, cub);
	else if (cub->game.map.p_direction == 'W')
		cub->ray_c.angle = deg_to_rad(180, cub);
	else if (cub->game.map.p_direction == 'E')
		cub->ray_c.angle = deg_to_rad(0, cub);
	return ;
}

void	scaling(t_cub *cub)
{
	cub->game.map.scale_x = 64;
	cub->game.map.scale_y = 64;
	cub->game.map.px_pix = cub->game.map.scale_x * cub->game.map.p_x + 32;
	cub->game.map.py_pix = cub->game.map.scale_y * cub->game.map.p_y + 32;
	return ;
}

void	cu_check_coordinate(t_cub *cub, float a)
{
	if (a >= 0 && a < M_PI / 2)
		cub->texture = cu_first_coordinate(cub);
	if (a >= M_PI / 2 && a < M_PI)
		cub->texture = cu_second_coordinate(cub);
	if (a >= M_PI && a < 3 * M_PI / 2)
		cub->texture = cu_third_coordinate(cub);
	if (a >= 3 * M_PI / 2 && a <= 2 * M_PI)
		cub->texture = cu_fourth_coordinate(cub);
}

int	cu_get_color(t_cub *cub, int x, int y)
{
	char	*dst;
	int		color;

	dst = cub->texture->addr + (y * cub->texture->line_length + x
				* (cub->texture->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	cu_texture(t_cub *cub)
{
	cub->n_texture.img = mlx_xpm_file_to_image(cub->mlx.mlx, cub->game.north,
			&cub->n_texture.t_width, &cub->n_texture.t_height);
	cub->s_texture.img = mlx_xpm_file_to_image(cub->mlx.mlx, cub->game.south,
			&cub->s_texture.t_width, &cub->s_texture.t_height);
	cub->e_texture.img = mlx_xpm_file_to_image(cub->mlx.mlx, cub->game.east,
			&cub->e_texture.t_width, &cub->e_texture.t_height);
	cub->w_texture.img = mlx_xpm_file_to_image(cub->mlx.mlx, cub->game.west,
			&cub->w_texture.t_width, &cub->w_texture.t_height);
	if (!cub->n_texture.img || !cub->s_texture.img || !cub->e_texture.img
		|| !cub->w_texture.img)
		cu_print_error("invalid texture", cub);
	cub->e_texture.addr = mlx_get_data_addr(cub->e_texture.img,
			&cub->e_texture.bits_per_pixel, &cub->e_texture.line_length,
			&cub->e_texture.endian);
	cub->s_texture.addr = mlx_get_data_addr(cub->s_texture.img,
			&cub->s_texture.bits_per_pixel, &cub->s_texture.line_length,
			&cub->s_texture.endian);
	cub->n_texture.addr = mlx_get_data_addr(cub->n_texture.img,
			&cub->n_texture.bits_per_pixel, &cub->n_texture.line_length,
			&cub->n_texture.endian);
	cub->w_texture.addr = mlx_get_data_addr(cub->w_texture.img,
			&cub->w_texture.bits_per_pixel, &cub->w_texture.line_length,
			&cub->w_texture.endian);
	return ;
}
