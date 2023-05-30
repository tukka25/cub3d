/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:28:51 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/30 20:03:51 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_init(t_game *game)
{
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->floor = -1;
	game->ceiling = -1;
	game->file.fd = 0;
	game->file.nline = 0;
	game->file.line = NULL;
	game->file.file_2d = NULL;
	game->map.map_2d = NULL;
	game->map.map_pos = -1;
	game->map.nline = 0;
	return ;
}
