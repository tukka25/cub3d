/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:13:37 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/03/15 16:27:03 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

extern int WIN_H;
extern int WIN_W;

# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define LOOK_LEFT 123
# define LOOK_RIGHT 124

# include "mlx/mlx.h"
# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	int		nline;
	int		linelen;
	char	*a;
	char	*one_d;
	char	**two_d;
}				t_map;

typedef struct s_file
{
	int		fd;
	int		fileLen;
	char	*line;
	char	*fileArray;
	char	**file2D;
}				t_file;

typedef struct s_game
{
	t_map	map;
	t_file	file;
}				t_game;

void	cu_print_error(char *msg);
void	cu_args_check(int ac, char *av);
void	cu_saving_file(t_game *game);

#endif