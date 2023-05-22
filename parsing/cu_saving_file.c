/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:56:24 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/22 17:05:34 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_saving_file(t_game *game)
{
	game->file.nline = 0;
	game->file.line = get_next_line(game->file.fd);
	if (game->file.line == 0)
		cu_print_error("File is empty");
	game->file.nline++;
	game->file.fileArray = ft_strdup(game->file.line);
	free(game->file.line);
	while (game->file.line)
	{
		game->file.line = get_next_line(game->file.fd);
		if (!game->file.line)
			break ;
		game->file.fileArray = ft_strjoin(game->file.fileArray, game->file.line);
		free(game->file.line);
		game->file.nline++;
	}
	game->file.fileLen = ft_strlen(game->file.fileArray);
	printf("%s", game->file.fileArray);
}