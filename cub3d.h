/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:21 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/22 13:57:17 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

typedef struct s_map
{
	int		dir_len;
	int		cam_plane;
	char	cord;
	int		height;
	int		width;
	int		px_index;
	int		py_index;
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
	t_map	m;
	t_mlx	mlx;
	t_img	img;
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
void	move_back(t_cub *cub);
void	move_down(t_cub *cub);
void	move_forward(t_cub *cub);
#endif