/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:56:24 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/25 20:04:41 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**cu_2d_maker(char **tmp, char *line, int nline)
{
	char	**dest;
	int		i;

	i = 0;
	dest = (char **)malloc(sizeof(char *) * (nline + 1));
	if (!dest)
		cu_print_error("Malloc error");
	while (tmp && tmp[i])
	{
		dest[i] = ft_strdup(tmp[i]);
		free(tmp[i]);
		i++;
	}
	dest[i] = ft_strdup(line);
	dest[i + 1] = NULL;
	free(tmp);
	free(line);
	return (dest);
}

void	cu_saving_file(t_game *game)
{	
	game->file.nline = 0;
	game->file.file_2d = NULL;
	game->file.line = get_next_line(game->file.fd);
	while(game->file.line)
	{
		game->file.nline++;
		game->file.file_2d = cu_2d_maker(game->file.file_2d, game->file.line,
				game->file.nline);
		game->file.line = get_next_line(game->file.fd);
	}
}
