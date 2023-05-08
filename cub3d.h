/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:21 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/08 03:59:38 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_map
{
	char	cord;
	int		px_index;
	int		py_index;
}	t_map;

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
	t_map	*m;
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
#endif