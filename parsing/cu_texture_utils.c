/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_texture_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:40:40 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/28 18:29:53 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	cu_cmp_id(char *line, char *identifier, int len)
{
	if (!ft_strncmp(line, identifier, len))
		return (true);
	return (false);
}

bool	cu_is_whtspace(int c)
{
	if (c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (true);
	return (false);
}

void	cu_check_texture_file(char *path, t_game *game)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		cu_print_error("Texture cannot be a directory", game);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
		cu_print_error("Texture file does not exist", game);
	close (fd);
	return ;
}

void	cu_check_duplicate(char *iden, t_game *game)
{
	if ((cu_cmp_id(iden, "NO", 2) && game->north)
		|| (cu_cmp_id(iden, "SO", 2) && game->south)
		|| (cu_cmp_id(iden, "WE", 2) && game->west)
		|| (cu_cmp_id(iden, "EA", 2) && game->east))
		cu_print_error("Duplicate identifier found", game);
	return ;
}

void	cu_check_texture_args(char **args, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (args[2] && args[2][0] != '\n')
	{
		cu_free_2d(args);
		cu_print_error("Invalid identifier", game);
	}
	while (args && args[i])
	{
		if (cu_is_whtspace(args[i][j]))
		{
			cu_free_2d(args);
			cu_print_error("Invalid white space", game);
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
