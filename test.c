/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:13:20 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/03/10 20:48:15 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		get_r(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}
int		get_g(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}
int		get_b(int rgb)
{
	return (rgb & 0xFF);
}

int		window_close(void)
{
	exit(0);
}

int		key_hook(int keycode, void *args)
{
	(void)args;
	printf("key pressed: %d\n", keycode);
	return 0;
}

int		mouse_hook(void *mlx_win)
{
	printf("mouse pos: %d\n", mlx_mouse_get_pos(mlx_win, 0, (int *)1));
	return 0;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		color;
	int		x = 0;
	int		y = 0;
	int		WIN_H = 800;
	int		WIN_W = 800;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_H, WIN_W, "CUB3D");
	img.img = mlx_new_image(mlx, WIN_H, WIN_W);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_length,
				&img.endian);
	color = create_rgb(255, 255, 0);
	// my_mlx_pixel_put(&img, 5, 5, color); //0x00FF0000 is red and hex rep of (0, 255, 0, 0)
	while (y <= WIN_H / 2)
	{
		while (x <= WIN_W)
		{
			my_mlx_pixel_put(&img, x++, y, color);
		}
		x = 0;
		my_mlx_pixel_put(&img, x, y++, color);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 17, 0, window_close, 0);
	mlx_key_hook(mlx_win, window_close, 0);
	mlx_key_hook(mlx_win, key_hook, 0);
	mlx_mouse_hook(mlx_win, mouse_hook, mlx_win);
	mlx_loop(mlx);
}