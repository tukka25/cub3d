/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_texture_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:40:40 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/24 20:55:05 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	cu_cmp_id(char *iden, char *cmp, int len)
{
	if (ft_strlen(cmp) != len)
		return (false);
	if (!ft_strncmp(iden, cmp, len))
		return (true);
	return (false);
}

bool	cu_is_whtspace(int c)
{
	if (c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (true);
	return (false);
}

void	cu_check_texture_file(char **args, char *path, t_cub *cub)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		free(path);
		cu_free_2d(args);
		cu_print_error("Texture cannot be a directory", cub);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		cu_free_2d(args);
		cu_print_error("Texture file does not exist", cub);
	}
	close (fd);
	return ;
}

bool	cu_is_duplicate(char *iden, t_cub *cub)
{
	if ((cu_cmp_id(iden, "NO", 2) && cub->game.north)
		|| (cu_cmp_id(iden, "SO", 2) && cub->game.south)
		|| (cu_cmp_id(iden, "WE", 2) && cub->game.west)
		|| (cu_cmp_id(iden, "EA", 2) && cub->game.east)
		|| (cu_cmp_id(iden, "F", 1) && cub->game.floor != -1)
		|| (cu_cmp_id(iden, "C", 1) && cub->game.ceiling != -1))
		return (true);
	return (false);
}

void	cu_check_texture_args(char **args, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (args[2] && args[2][0] != '\n')
	{
		cu_free_2d(args);
		cu_print_error("Invalid texture identifier", cub);
	}
	while (args && args[i])
	{
		if (cu_is_whtspace(args[i][j]))
		{
			cu_free_2d(args);
			cu_print_error("Invalid white space", cub);
		}
		j++;
		if (!args[i][j])
		{
			j = 0;
			i++;
		}
	}
	return ;
}
