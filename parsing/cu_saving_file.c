/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:56:24 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/30 18:34:36 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**cu_file_to_2d(char **pre, char *line, int nline, t_game *game)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (nline + 1));
	if (!new)
		cu_print_error("Malloc error", game);
	while (pre && pre[i])
	{
		new[i] = ft_strdup(pre[i]);
		free(pre[i]);
		i++;
	}
	new[i] = ft_strdup(line);
	new[i + 1] = 0;
	free(pre);
	free(line);
	return (new);
}

void	cu_saving_file(t_game *game)
{	
	game->file.line = get_next_line(game->file.fd);
	if (!game->file.line)
		cu_print_error("File is empty", game);
	while (game->file.line)
	{
		game->file.nline++;
		game->file.file_2d = cu_file_to_2d(game->file.file_2d, game->file.line,
				game->file.nline, game);
		game->file.line = get_next_line(game->file.fd);
	}
	return ;
}
