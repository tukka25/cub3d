/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:04:48 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/24 20:55:05 by abdamoha         ###   ########.fr       */
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

void	cu_freedom(t_cub *cub)
{
	cu_free_2d(cub->game.file.file_2d);
	cu_free_2d(cub->game.map.map_2d);
	if (cub->game.file.line)
		free(cub->game.file.line);
	if (cub->game.north)
		free(cub->game.north);
	if (cub->game.south)
		free(cub->game.south);
	if (cub->game.west)
		free(cub->game.west);
	if (cub->game.east)
		free(cub->game.east);
}

void	cu_is_2_commas(char *line, t_cub *cub)
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
		cu_print_error("Invalid color commas", cub);
	}
	return ;
}
