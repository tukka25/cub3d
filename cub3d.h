/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:13:37 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/26 01:27:59 by talsaiaa         ###   ########.fr       */
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
	int		nline;
	int		linelen;
	char	*a;
	char	*one_d;
	char	**two_d;
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
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F;
	int		C;
}				t_game;

void	cu_print_error(char *msg, t_game *game);
void	cu_args_check(char *av, t_game *game);
void	cu_saving_file(t_game *game);
void	cu_saving_textures(t_game* game);

#endif