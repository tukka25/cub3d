/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:35 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/09 17:20:07 by abdamoha         ###   ########.fr       */
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
		cub.mlx.mlx_win = mlx_new_window(cub.mlx.mlx, cub.m.width * 64, cub.m.height * 64, "cub3d");
		cub.img.background_img = mlx_xpm_file_to_image(cub.mlx.mlx, "./img/pixels.xpm", &x, &x);
		if (!cub.img.background_img)
		{
			printf("error1\n");
			exit(1);
		}
		cub.img.wall_img = mlx_xpm_file_to_image(cub.mlx.mlx,
				"./img/wallll.xpm", &x, &x);
		if (!cub.img.wall_img)
		{
			printf("error2\n");
			exit(1);
		}
		drawing(&cub);
		mlx_loop(cub.mlx.mlx);
	}
	else
		ft_putstr_fd("INVALID INPUTS\n", 2);
	return (0);
}
