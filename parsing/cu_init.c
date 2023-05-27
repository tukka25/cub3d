/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:28:51 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/27 20:37:07 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_init(t_game *game)
{
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->floor = 0;
	game->ceiling = 0;
	game->file.fd = 0;
	game->file.nline = 0;
	game->file.line = NULL;
	game->file.file_2d = NULL;
	return ;
}
