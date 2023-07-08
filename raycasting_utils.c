/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:34:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/08 02:33:51 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_angle(t_cub *cub)
{
	// printf("p_direction = %d\n", cub->game.map.p_direction);
	if (cub->game.map.p_direction == 'N')
		cub->ray_c.angle = deg_to_rad(90, cub);
	else if (cub->game.map.p_direction == 'S')
		cub->ray_c.angle = deg_to_rad(270, cub);
	else if (cub->game.map.p_direction == 'W')
		cub->ray_c.angle = deg_to_rad(180, cub);
	else if (cub->game.map.p_direction == 'E')
		cub->ray_c.angle = deg_to_rad(0, cub);
}

void	scaling(t_cub *cub)
{
	printf("c = %d\n", cub->game.map.map_width - 1);
	// cub->game.map.scale_x = round(WIDTH / (cub->game.map.map_width - 1));
	cub->game.map.scale_x = 64;
	// printf("s_x = %d\n", HEIGHT / cub->game.map.nline);
	// printf("floor = %d\n", cub->game.floor);
	// printf("ceiling = %d\n", cub->game.ceiling);
	// exit(0);
	// cub->game.map.scale_y = round(HEIGHT / cub->game.map.nline);
	cub->game.map.scale_y = 64;
	cub->game.map.px_pix = cub->game.map.scale_x * cub->game.map.p_x;
	cub->game.map.py_pix = cub->game.map.scale_y * cub->game.map.p_y;
}

void	cu_draw_texture(t_cub *cub, int h, float *arr)
{
	float		start;
	float		end;
	// int		wall_height;
	float		xo;
	float	y_step;
	float		y = 0;

	// (void)arr;
	// wall_height = HEIGHT / cub->ray_c.ray_length;
	start = arr[2];
	end = arr[3];
	// printf("ray length: %f, ray temp: %f\n", cub->ray_c.ray_length, cub->ray_c.tmp_length);
	if (cub->ray_c.ray_length < cub->ray_c.tmp_length)
		xo = (int)(cub->ray_c.xs_h / cub->game.map.scale_y * cub->texture.t_width) % (int)cub->texture.t_width;
	else
		xo = (int)(cub->ray_c.ys_v / cub->game.map.scale_x * cub->texture.t_width) % (int)cub->texture.t_width;
	// printf("xo: %d\n", xo);
	y_step = cub->texture.t_height / cub->ray_c.wall_length;
	while (start <= end)
	{
		my_mlx_pixel_put(cub, h, start++, cu_get_color(cub, xo, y += y_step));
		if (xo > cub->texture.t_width)
			xo = cub->texture.t_width - 1;
		if (y + y_step >= cub->texture.t_height)
			y = cub->texture.t_height - y_step - 1;
	}
}

int		cu_get_color(t_cub *cub, int x, int y)
{
	int		color;
	char	*dst;

	dst = cub->texture.addr + (y * cub->texture.line_length + x * (cub->texture.bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	cu_texture(t_cub *cub)
{
	cub->texture.img = mlx_xpm_file_to_image(cub->mlx.mlx, cub->game.west,
	&cub->texture.t_width, &cub->texture.t_height);
	cub->texture.addr = mlx_get_data_addr(cub->texture.img,
	&cub->texture.bits_per_pixel, &cub->texture.line_length,
	&cub->texture.endian);
}

// void	draw_floor_ceiling(t_cub *cub, int c1, int c2)
// {
// 	int	i;
// 	int	j;
// 	int	arr[4];

// 	i = 0;
// 	j = 0;
// 	(void)c2;
// 	arr[0] = 0;
// 	arr[1] = WIDTH;
// 	arr[2] = 0;
// 	arr[3] = 0;
// 	while (i < HEIGHT / 2)
// 	{
// 		draw_line(cub, arr, c1);
// 		arr[2]++;
// 		arr[3]++;
// 		i++;
// 	}
// 	while (i < HEIGHT)
// 	{
// 		draw_line(cub, arr, c2);
// 		arr[2]++;
// 		arr[3]++;
// 		i++;
// 	}
// }
