/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:21 by abdamoha          #+#    #+#             */
/*   Updated: 2023/06/14 18:20:50 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define Speed 8
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>


typedef struct s_ray_c
{
	float	pdx;
	float	pdy;
	float	angle;
	float	wall_length;
	float	ray_length;
}	t_ray_c;

typedef struct s_map
{
	int		dir_len;
	int		cam_plane;
	char	cord;
	int		height;
	int		width;
	int		px_index;
	int		start_px;
	int		start_py;
	int		px_pix;
	int		py_index;
	int		py_pix;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_img
{
	void	*background_img;
	void	*wall_img;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_cub
{
	int		i;
	int		fd;
	int		j;
	char	*line;
	char	**tmp;
	char	**map;
	int		*f_colors;
	int		*c_colors;
	int		move_x;
	int		move_y;
	float	pi;
	t_map	m;
	t_mlx	mlx;
	t_img	img;
	t_ray_c	ray_c;
}	t_cub;

void	pars(char **argv, t_cub *cub);
void	error_exit(char *str);
void	check_req(t_cub *cub, char *line);
int		ft_strlen_2d(char **str);
void	free_strings(char **str);
void	check_map(t_cub *cub, char *av);
int		all_spaces(char *str);
int		len_till_nl(char *str);
void	insert_map(t_cub *cub, char *av);
void	map_pars(t_cub *cub);
void	free_and_exit(t_cub *cub, char *str);
void	drawing(t_cub *cub);
int		key_hook(int keycode, t_cub *cub);
void	move_up(t_cub *cub);
void	move_left(t_cub *cub);
void	move_down(t_cub *cub);
void	move_right(t_cub *cub);
void	draw_wall(t_cub *cub, int x, int y);
void	render(t_cub *cub);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	rotate_right(t_cub *cub);
void	rotate_left(t_cub *cub);
float	deg_to_rad(int i, t_cub *cub);
int		rad_to_deg(float i, t_cub *cub);
int		exit_w(t_cub *cub);
void	cast_rays(t_cub *cub);
void	draw_line(t_cub *cub, int *arr, int color);
void	check_horizontal(t_cub *cub, int *arr, float a);
int		check_vertical(t_cub *cub, int *arr, float a);
#endif