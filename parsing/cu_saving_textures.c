/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:15:04 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/27 00:00:54 by talsaiaa         ###   ########.fr       */
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

// gotta check if file is .xpm as well
static char	*cu_checking_texture(char *line, char *iden, t_game *game)
{
	char	**tmp;
	char	*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cu_check_duplicate(iden, game);
	tmp = ft_split(line, ' ');
	if (tmp[2] && tmp[2][0] != '\n')
	{
		cu_free_2d(tmp);
		cu_print_error("Invalid identifier", game);
	}
	while (tmp && tmp[i])
	{
		if (cu_is_whtspace(tmp[i][j]))
		{
			cu_free_2d(tmp);
			cu_print_error("Invalid white space", game);
		}
		j++;
		if (!tmp[i][j])
		{
			j = 0;
			i++;
		}
	}
	path = ft_strdup(tmp[1]);
	cu_free_2d(tmp);
	cu_check_texture_file(path, game);
	return (path);
}

void	cu_saving_textures(t_game* game)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (game->file.file_2d && game->file.file_2d[i])
	{
		tmp = cu_strtrimchar(game->file.file_2d[i], ' ');
		if (cu_cmp_id(tmp, "NO "))
			game->NO = cu_checking_texture(tmp, "NO ", game);
		if (cu_cmp_id(tmp, "SO "))
			game->SO = cu_checking_texture(tmp, "SO ", game);
		if (cu_cmp_id(tmp, "WE "))
			game->WE = cu_checking_texture(tmp, "WE ", game);
		if (cu_cmp_id(tmp, "EA "))
			game->EA = cu_checking_texture(tmp, "EA ", game);
		i++;
		free(tmp);
	}
	if (!game->NO || !game->SO || !game->WE || !game->EA)
		cu_print_error("Texture identifier not found", game);
	printf("NO: %s\n", game->NO);
	printf("SO: %s\n", game->SO);
	printf("WE: %s\n", game->WE);
	printf("EA: %s\n", game->EA);
	return ;
}