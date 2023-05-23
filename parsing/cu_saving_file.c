/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:56:24 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/23 16:31:27 by talsaiaa         ###   ########.fr       */
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
	game->file.file_array = ft_strdup(game->file.line);
	free(game->file.line);
	while (game->file.line)
	{
		game->file.line = get_next_line(game->file.fd);
		if (!game->file.line)
			break ;
		game->file.file_array = ft_strjoin(game->file.file_array,
				game->file.line);
		free(game->file.line);
		game->file.nline++;
	}
	game->file.file_len = ft_strlen(game->file.file_array);
	char	*trim = ft_strnstr(game->file.file_array, "NO", 2);
	printf("%s", game->file.file_array);
	printf("\n%s", trim);
}
