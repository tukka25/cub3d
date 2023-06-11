/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:35 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/11 21:21:23 by abdamoha         ###   ########.fr       */
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
	cub->ray_c.angle = deg_to_rad(90, cub);
	cub->ray_c.pdx = cos(cub->ray_c.angle) * 5;
	cub->ray_c.pdy = sin(cub->ray_c.angle) * 5;
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
		printf("fl = %f\n", cub.ray_c.angle);
		pars(av, &cub);
		cub.mlx.mlx = mlx_init();
		cub.mlx.mlx_win = mlx_new_window(cub.mlx.mlx, cub.m.width * 64,
				cub.m.height * 64, "cub3d");
		drawing(&cub);
		mlx_hook(cub.mlx.mlx_win, 2, 0, key_hook, &cub);
		mlx_hook(cub.mlx.mlx_win, 17, 0, exit_w, &cub);
		mlx_loop(cub.mlx.mlx);
	}
	else
		ft_putstr_fd("INVALID INPUTS\n", 2);
	return (0);
}
