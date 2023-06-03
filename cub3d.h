/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:13:37 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/03 17:06:08 by talsaiaa         ###   ########.fr       */
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
	int		p_x;
	int		p_y;
	char	p_direction;
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

void	cu_args_check(char *av, t_game *game);
int		cu_atoi(char *str);
void	cu_init(t_game *game);
void	cu_print_error(char *msg, t_game *game);
void	cu_check_space(int y, int x, t_game *game);
void	cu_check_edge(char *line, t_game *game);
void	cu_is_valid_character(int y, int c, t_game *game);
void	cu_is_player(int c, int y, int x, t_game *game);
void	cu_is_space(int c, int y, int x, t_game *game);
char	*cu_strtrimchar(char const *str, int const c);
bool	cu_cmp_id(char *iden, char *cmp, int len);
bool	cu_is_whtspace(int c);
void	cu_check_texture_file(char **args, char *path, t_game *game);
bool	cu_is_duplicate(char *iden, t_game *game);
void	cu_check_texture_args(char **args, t_game *game);
void	cu_freedom(t_game *game);
void	cu_free_2d(char **str_2d);
void	cu_saving_file(t_game *game);
void	cu_saving_components(t_game *game);
void	cu_saving_colors(char *line, t_game *game);
void	cu_saving_map(char *line, int index, t_game *game);
void	cu_check_map(t_game *game);
char	*cu_dup_and_trim(char *line);
bool	cu_is_map_begininng(char *line);
char	**cu_2d_dup(char **arrays, int start, int nline);
int		cu_2d_len(char **arrays);
void	cu_check_missing(t_game *game);
void	cu_is_2_commas(char *line, t_game *game);

#endif