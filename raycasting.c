/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:44:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/03 03:07:29 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_cub *cub)
{
	int	i;
	int	pos;

	i = 0;
	pos = cub->m.py_pix;
	// printf("pos = %d\n", pos);
	// check_horizontal(cub);
	// while (1)
	// {
	// 	i = 0;
	// 	while (i < 8)
	// 	{
	// 		pos -= 8;
	// 		i++;
	// 	}
	// 		// printf("c = %c\n", cub->map[pos / 64][cub->m.px_pix / 64]);
	// 	if (cub->map[pos / 64][cub->m.px_pix / 64] == '1')
	// 	{
	// 		int	arr[5] = {cub->m.px_pix, cub->m.py_pix, 0 ,pos, cub->m.py_pix - pos};
	// 		draw_line(arr, cub);
	// 		// printf("bye\n");
	// 		// printf("pos = %d\n", pos);
	// 		break ;
	// 	}
	// }
}

void	draw_line(int *arr, t_cub *cub)
{
	// printf("arr = %d\n", arr[4]);
	// exit(0);
	(void)cub;
	if (arr[0] < arr[2])
	{
		while (arr[0] < arr[2])
		{
			printf("i\n");
			my_mlx_pixel_put(&cub->img, arr[0] , arr[1], 0xFF0000);
			arr[0]++;
		}
	}
	else
	{
		// int	g = 125;
		int		f = cub->move_x;
		int		n = cub->move_y;
		int		d = arr[0];
		while (arr[0] > arr[2] && arr[1] > 0)
		{
			// printf("a = %d\n", rad_to_deg(cub->ray_c.angle, cub))
			f += cos(cub->ray_c.angle);
			n += sin(cub->ray_c.angle);
			my_mlx_pixel_put(&cub->img, d + f, arr[1] + n, 0xFF0000);
			arr[0]--;
			if (arr[1] > 0)
				arr[1]--;
			// g++;
		}
	}
}

void	check_horizontal(t_cub *cub)
{
	int	ys;
	int	xs;

	xs = 0;
	ys = 64;
	xs = tan(cub->ray_c.angle) * ys;
}