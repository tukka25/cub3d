/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:13:37 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/30 20:03:37 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_map
{
	int		map_pos;
	int		nline;
	char	**map_2d;
}				t_map;

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

void	cu_print_error(char *msg, t_game *game);
void	cu_args_check(char *av, t_game *game);
void	cu_saving_file(t_game *game);
void	cu_saving_components(t_game *game);
void	cu_freedom(t_game *game);
void	cu_init(t_game *game);
char	*cu_strtrimchar(char const *str, int const c);
void	cu_free_2d(char **str_2d);
bool	cu_cmp_id(char *line, char *identifier, int len);
bool	cu_is_whtspace(int c);
void	cu_check_texture_file(char **args, char *path, t_game *game);
bool	cu_is_duplicate(char *iden, t_game *game);
void	cu_check_texture_args(char **args, t_game *game);
int		cu_atoi(char *str);
void	cu_saving_textures(char *line, t_game *game);
void	cu_saving_colors(char *line, t_game *game);
char	**cu_file_to_2d(char **pre, char *line, int nline, t_game *game);
void	cu_saving_map(char *line, int map_start, t_game *game);

#endif