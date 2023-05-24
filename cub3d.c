/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:35 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/24 16:07:56 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	first_init(t_cub *cub)
{
	cub->i = 0;
	cub->j = 0;
	cub->f_colors = NULL;
	cub->c_colors = NULL;
	cub->map = NULL;
	cub->move_x = 0;
	cub->move_y = 0;
	cub->pi = 3.14159265359;
	cub->ray_c.angle = 90 * cub->pi;
	cub->ray_c.pdx = 0;
	cub->ray_c.pdy = 0;
}

int	main(int ac, char *av[])
{
	t_cub	cub;
	int		x;
	int		y;

	x = 64;
	y = 0;
	if (ac == 2)
	{
		first_init(&cub);
		pars(av, &cub);
		cub.mlx.mlx = mlx_init();
		cub.mlx.mlx_win = mlx_new_window(cub.mlx.mlx, cub.m.width * 64,
				cub.m.height * 64, "cub3d");
		// my_mlx_pixel_put(&cub.img, 5, 5, 0xFFFFFFF);
		// mlx_put_image_to_window(cub.mlx.mlx, cub.mlx.mlx_win, 
		// 	cub.img.img, 0, 0);
		drawing(&cub);
		mlx_hook(cub.mlx.mlx_win, 2, 0, key_hook, &cub);
		mlx_loop(cub.mlx.mlx);
	}
	else
		ft_putstr_fd("INVALID INPUTS\n", 2);
	return (0);
}
