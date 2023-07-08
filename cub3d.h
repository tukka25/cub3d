/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:21 by abdamoha          #+#    #+#             */
/*   Updated: 2023/07/08 00:32:55 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SPEED 8
# define WIDTH 1500
# define HEIGHT 850
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "mlx/mlx.h"

typedef struct s_ray_c
{
	float	pdx;
	float	pdy;
	float	angle;
	float	wall_length;
	float	ray_length;
	float	ys_h;
	float	xs_h;
	float	ys_v;
	float	xs_v;
	float	tmp_length;
}	t_ray_c;

typedef struct s_map
{
	int		map_pos;
	int		nline;
	int		p_x;
	int		p_y;
	int		map_width;
	char	p_direction;
	char	**map_2d;
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
	float	scale_x;
	float	scale_y;
}	t_map;

typedef struct s_file
{
	int		fd;
	int		nline;
	char	*line;
	char	**file_2d;
}				t_file;

typedef struct s_game
{
	t_map	map;
	t_file	file;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
}				t_game;

typedef	struct	s_img
{	
	void	*background_img;
	void	*wall_img;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		t_width;
	int		t_height;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_cub
{
	int		i;
	int		fd;
	int		j;
	char	*line;
	char	**tmp;
	int		*f_colors;
	int		*c_colors;
	int		move_x;
	int		move_y;
	float	pi;
	t_mlx	mlx;
	t_img	img;
	t_img	texture;
	t_ray_c	ray_c;
	t_game	game;
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
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void	rotate_right(t_cub *cub);
void	rotate_left(t_cub *cub);
float	deg_to_rad(int i, t_cub *cub);
int		rad_to_deg(float i, t_cub *cub);
int		exit_w(t_cub *cub);
void	cast_rays(t_cub *cub);
void	draw_line(t_cub *cub, float *arr, int color);
void	check_horizontal(t_cub *cub, float a);
float	check_vertical(t_cub *cub, float a);
void	convert_angle(t_cub *cub);
void	scaling(t_cub *cub);
void	check_left_right(t_cub *cub, int flag);
void	check_horz_vert(t_cub *cub, int flag);
void	draw_floor_ceiling(t_cub *cub, int c1, int c2);

void	cu_args_check(char *av, t_cub *cub);
int		cu_atoi(char *str);
void	cu_init(t_cub *cub);
void	cu_print_error(char *msg, t_cub *cub);
void	cu_check_space(int y, int x, t_cub *cub);
void	cu_check_edge(char *line, t_cub *cub);
void	cu_is_valid_character(int y, int c, t_cub *cub);
bool	cu_is_player(int c);
void	cu_is_space(int c, int y, int x, t_cub *cub);
char	*cu_strtrimchar(char const *str, int const c);
bool	cu_cmp_id(char *iden, char *cmp, int len);
bool	cu_is_whtspace(int c);
void	cu_check_texture_file(char **args, char *path, t_cub *cub);
bool	cu_is_duplicate(char *iden, t_cub *cub);
void	cu_check_texture_args(char **args, t_cub *cub);
void	cu_freedom(t_cub *cub);
void	cu_free_2d(char **str_2d);
void	cu_saving_file(t_cub *cub);
void	cu_saving_components(t_cub *cub);
void	cu_saving_colors(char *line, t_cub *cub);
void	cu_saving_map(char *line, int index, t_cub *cub);
void	cu_check_map(t_cub *cub);
char	*cu_dup_and_trim(char *line);
bool	cu_is_map_begininng(char *line);
char	**cu_2d_dup(char **arrays, int start, int nline);
int		cu_2d_len(char **arrays);
void	cu_check_missing(t_cub *cub);
void	cu_is_2_commas(char *line, t_cub *cub);
void	cu_get_width(t_cub *cub);
void	cu_draw_texture(t_cub *cub, int h, float *arr);
int		cu_get_color(t_cub *cub, int x, int y);
void	cu_texture(t_cub *cub);

#endif