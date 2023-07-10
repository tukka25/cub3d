/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:35 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/10 21:28:28 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	first_init(t_cub *cub)
{
	cub->i = 0;
	cub->j = 0;
	cub->f_colors = NULL;
	cub->c_colors = NULL;
	cub->move_x = 0;
	cub->move_y = 0;
	cub->pi = 3.14159265359;
	convert_angle(cub);
	scaling(cub);
	cub->ray_c.pdx = cos(cub->ray_c.angle) * 5;
	cub->ray_c.pdy = sin(cub->ray_c.angle) * 5;
	return ;
}

int	main(int ac, char **av)
{
	t_cub	cub;

	cu_init(&cub);
	if (ac != 2)
		cu_print_error("Invalid number of arguments", &cub);
	cub.game.file.fd = open(av[1], O_DIRECTORY);
	if (cub.game.file.fd > 0)
		cu_print_error("Argument cannot be a directory", &cub);
	cub.game.file.fd = open(av[1], O_RDONLY);
	cu_args_check(av[1], &cub);
	cu_saving_file(&cub);
	cu_saving_components(&cub);
	first_init(&cub);
	cub.mlx.mlx = mlx_init();
	cub.mlx.mlx_win = mlx_new_window(cub.mlx.mlx, WIDTH,
			HEIGHT, "cub3d");
	cu_texture(&cub);
	drawing(&cub);
	mlx_hook(cub.mlx.mlx_win, 2, 1L << 0, key_hook, &cub);
	mlx_hook(cub.mlx.mlx_win, 17, 0, exit_w, &cub);
	mlx_loop(cub.mlx.mlx);
	cu_freedom(&cub);
	close (cub.game.file.fd);
	return (0);
}

void	looking_left(t_cub *cub, float xo, float yo)
{
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

int	exit_w(t_cub *cub)
{
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.mlx_win);
	cu_print_error("Game Over!", cub);
	return (0);
}
