/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:15:04 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/26 01:54:30 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	cu_cmp_id(char *line, char *identifier)
{
	if (!ft_strncmp(line, identifier, 3))
		return (true);
	return (false);
}
static bool cu_is_whtspace(int c)
{
	if ( c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (true);
	return (false);
}

static void	cu_check_texture_file(char *path, t_game *game)
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

static void	cu_check_duplicate(char *iden, t_game *game)
{
	if ((cu_cmp_id(iden, "NO ") && game->NO)
		|| (cu_cmp_id(iden,"SO ") && game->SO)
		|| (cu_cmp_id(iden,"WE ") && game->WE)
		|| (cu_cmp_id(iden,"EA ") && game->EA))
		cu_print_error("Duplicate identifier found", game);
	return ;
}

static char	*cu_checking_texture(char *line, char *iden, t_game *game)
{
	char	**path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cu_check_duplicate(iden, game);
	path = ft_split(line, ' ');
	if (path[2] || !path[1])
		cu_print_error("Invalid identifier", game);
	while (path && path[i])
	{
		if (cu_is_whtspace(path[i][j]))
			cu_print_error("Invalid white space", game);
		j++;
		if (!path[i][j])
		{
			j = 0;
			i++;
		}
	}
	path[1][ft_strlen(path[1]) - 1] = '\0'; //to get rid of new line, but may cause problems later.
	cu_check_texture_file(path[1], game);
	return (ft_strtrim(path[1], " "));
}

void	cu_saving_textures(t_game* game)
{
	int	i;

	i = 0;
	game->NO = NULL;
	game->SO = NULL;
	game->WE = NULL;
	game->EA = NULL;
	while (game->file.file_2d && game->file.file_2d[i])
	{
		if (cu_cmp_id(game->file.file_2d[i], "NO "))
			game->NO = cu_checking_texture(game->file.file_2d[i], "NO ", game);
		if (cu_cmp_id(game->file.file_2d[i], "SO "))
			game->SO = cu_checking_texture(game->file.file_2d[i], "SO ", game);
		if (cu_cmp_id(game->file.file_2d[i], "WE "))
			game->WE = cu_checking_texture(game->file.file_2d[i], "WE ", game);
		if (cu_cmp_id(game->file.file_2d[i], "EA "))
			game->EA = cu_checking_texture(game->file.file_2d[i], "EA ", game);
		i++;
	}
	if (!game->NO || !game->SO || !game->WE || !game->EA)
		cu_print_error("Texture identifier not found", game);
	printf("NO: %s\n", game->NO);
	printf("SO: %s\n", game->SO);
	printf("WE: %s\n", game->WE);
	printf("EA: %s\n", game->EA);
	return ;
}