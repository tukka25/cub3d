/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:15:04 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/29 20:26:33 by talsaiaa         ###   ########.fr       */
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

	if (cu_is_duplicate(iden, game))
	{
		cu_free_2d(args);
		cu_print_error("Duplicate texture found", game);
	}
	cu_check_texture_args(args, game);
	path = ft_strdup(args[1]);
	if (path[ft_strlen(path) - 1] == '\n')
		path[ft_strlen(path) - 1] = 0;
	cu_check_texture_file(path, game);
	cu_check_file_extension(path, game);
	return (path);
}

void	cu_saving_textures(char *line, t_game *game)
{
	char	**split;

	split = ft_split(line, ' ');
	if (cu_cmp_id(split[0], "NO", 2))
		game->north = cu_checking_texture(split, "NO", game);
	else if (cu_cmp_id(split[0], "SO", 2))
		game->south = cu_checking_texture(split, "SO", game);
	else if (cu_cmp_id(split[0], "WE", 2))
		game->west = cu_checking_texture(split, "WE", game);
	else if (cu_cmp_id(split[0], "EA", 2))
		game->east = cu_checking_texture(split, "EA", game);
	cu_free_2d(split);
	return ;
}

void	cu_saving_components(t_game *game)
{
	int	i;

	i = 0;
	while (game->file.file_2d && game->file.file_2d[i])
	{
		cu_saving_textures(game->file.file_2d[i], game);
		cu_saving_colors(game->file.file_2d[i], game);
		i++;
	}
	if (!game->north || !game->south || !game->west || !game->east
		|| game->floor == -1 || game->ceiling == -1)
		cu_print_error("Texture identifier not found", game);
	printf("north: %s\n", game->north);
	printf("south: %s\n", game->south);
	printf("west: %s\n", game->west);
	printf("east: %s\n", game->east);
	printf("floor: %d\n", game->floor);
	printf("ceiling: %d\n", game->ceiling);
	return ;
}
