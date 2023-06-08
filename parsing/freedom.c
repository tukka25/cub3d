/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:04:48 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/03 17:05:59 by talsaiaa         ###   ########.fr       */
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
	cu_free_2d(game->map.map_2d);
	if (game->file.line)
		free(game->file.line);
	if (game->north)
		free(game->north);
	if (game->south)
		free(game->south);
	if (game->west)
		free(game->west);
	if (game->east)
		free(game->east);
}

void	cu_is_2_commas(char *line, t_game *game)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (line[i])
	{
		if (line[i] == ',')
			n++;
		i++;
	}
	if (n != 2)
	{
		free(line);
		cu_print_error("Invalid color commas", game);
	}
	return ;
}