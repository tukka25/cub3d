/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:15:04 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/24 20:40:00 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_check_file_extension(char **args, char *file, t_game *game)
{
	if (!ft_strchr(file, '.')
		|| ft_strncmp(".xpm", (file + ft_strlen(file) - 4), 4))
	{
		free(file);
		cu_free_2d(args);
		cu_print_error("Texture must be an existing .xpm file", game);
	}
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
	cu_check_file_extension(args, path, game);
	cu_check_texture_file(args, path, game);
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

void	cu_check_identifier(char *line, t_game *game)
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
		cu_print_error("Invalid identifier", game);
	}
	cu_free_2d(tmp);
	return ;
}

void	cu_saving_components(t_game *game)
{
	int	i;

	i = 0;
	while (game->file.file_2d && game->file.file_2d[i])
	{
		cu_check_identifier(game->file.file_2d[i], game);
		cu_saving_textures(game->file.file_2d[i], game);
		cu_saving_colors(game->file.file_2d[i], game);
		cu_saving_map(game->file.file_2d[i], i, game);
		i++;
	}
	cu_check_missing(game);
	cu_get_width(game);
	printf("north: %s\n", game->north);
	printf("south: %s\n", game->south);
	printf("west: %s\n", game->west);
	printf("east: %s\n", game->east);
	printf("floor: %d\n", game->floor);
	printf("ceiling: %d\n", game->ceiling);
	for (int i = 0; game->map.map_2d[i]; i++)
		printf("%s", game->map.map_2d[i]);
	printf("\np_x: %d, p_y: %d, p_direction: %c\n", game->map.p_x, game->map.p_y, game->map.p_direction);
	return ;
}
