/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:04:48 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/27 00:02:45 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_free_2d(char **str_2d)
{
	int	i;

	i = 0;
	while (str_2d && str_2d[i])
		free(str_2d[i++]);
	if (str_2d)
		free(str_2d);
}

void	cu_freedom(t_game *game)
{
	cu_free_2d(game->file.file_2d);
	if (game->file.line)
		free(game->file.line);
	free(game->NO);
	free(game->SO);
	free(game->WE);
	free(game->EA);
}