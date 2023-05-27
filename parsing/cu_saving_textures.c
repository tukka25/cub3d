/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:15:04 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/27 20:41:35 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_check_file_extension(char *file, t_game *game)
{
	if (!ft_strchr(file, '.')
		|| ft_strncmp("xpm", (file + ft_strlen(file) - 3), 3))
		cu_print_error("Texture must be an existing .xpm file", game);
	return ;
}

static char	*cu_checking_texture(char **args, char *iden, t_game *game)
{
	char	*path;

	cu_check_duplicate(iden, game);
	cu_check_texture_args(args, game);
	path = ft_strdup(args[1]);
	if (path[ft_strlen(path) - 1] == '\n')
		path[ft_strlen(path) - 1] = 0;
	cu_check_texture_file(path, game);
	cu_check_file_extension(path, game);
	return (path);
}

void	cu_saving_textures(t_game *game)
{
	int		i;
	char	**split;

	i = 0;
	while (game->file.file_2d && game->file.file_2d[i])
	{
		split = ft_split(game->file.file_2d[i], ' ');
		if (cu_cmp_id(split[0], "NO"))
			game->north = cu_checking_texture(split, "NO", game);
		else if (cu_cmp_id(split[0], "SO"))
			game->south = cu_checking_texture(split, "SO", game);
		else if (cu_cmp_id(split[0], "WE"))
			game->west = cu_checking_texture(split, "WE", game);
		else if (cu_cmp_id(split[0], "EA"))
			game->east = cu_checking_texture(split, "EA", game);
		i++;
		cu_free_2d(split);
	}
	if (!game->north || !game->south || !game->west || !game->east)
		cu_print_error("Texture identifier not found", game);
	return ;
}
