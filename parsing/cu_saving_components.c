/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:15:04 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/07/06 15:33:16 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_check_file_extension(char **args, char *file, t_cub *cub)
{
	if (!ft_strchr(file, '.')
		|| ft_strncmp(".xpm", (file + ft_strlen(file) - 4), 4))
	{
		free(file);
		cu_free_2d(args);
		cu_print_error("Texture must be an existing .xpm file", cub);
	}
	return ;
}

static char	*cu_checking_texture(char **args, char *iden, t_cub *cub)
{
	char	*path;

	if (cu_is_duplicate(iden, cub))
	{
		cu_free_2d(args);
		cu_print_error("Duplicate texture found", cub);
	}
	cu_check_texture_args(args, cub);
	path = ft_strdup(args[1]);
	if (path[ft_strlen(path) - 1] == '\n')
		path[ft_strlen(path) - 1] = 0;
	cu_check_file_extension(args, path, cub);
	cu_check_texture_file(args, path, cub);
	return (path);
}

void	cu_saving_textures(char *line, t_cub *cub)
{
	char	**split;

	split = ft_split(line, ' ');
	if (cu_cmp_id(split[0], "NO", 2))
		cub->game.north = cu_checking_texture(split, "NO", cub);
	else if (cu_cmp_id(split[0], "SO", 2))
		cub->game.south = cu_checking_texture(split, "SO", cub);
	else if (cu_cmp_id(split[0], "WE", 2))
		cub->game.west = cu_checking_texture(split, "WE", cub);
	else if (cu_cmp_id(split[0], "EA", 2))
		cub->game.east = cu_checking_texture(split, "EA", cub);
	cu_free_2d(split);
	return ;
}

void	cu_check_identifier(char *line, t_cub *cub)
{
	char	**tmp;
	int		len;

	if (cu_is_map_begininng(line))
		return ;
	tmp = ft_split(line, ' ');
	len = ft_strlen(tmp[0]);
	if (!cu_cmp_id(tmp[0], "NO", len) && !cu_cmp_id(tmp[0], "SO", len)
		&& !cu_cmp_id(tmp[0], "WE", len) && !cu_cmp_id(tmp[0], "EA", len)
		&& !cu_cmp_id(tmp[0], "F", len) && !cu_cmp_id(tmp[0], "C", len)
		&& !cu_cmp_id(tmp[0], "\n", len))
	{
		cu_free_2d(tmp);
		cu_print_error("Invalid identifier", cub);
	}
	cu_free_2d(tmp);
	return ;
}

void	cu_saving_components(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->game.file.file_2d && cub->game.file.file_2d[i])
	{
		cu_check_identifier(cub->game.file.file_2d[i], cub);
		cu_saving_textures(cub->game.file.file_2d[i], cub);
		cu_saving_colors(cub->game.file.file_2d[i], cub);
		cu_saving_map(cub->game.file.file_2d[i], i, cub);
		i++;
	}
	cu_check_missing(cub);
	cu_get_width(cub);
	return ;
}
