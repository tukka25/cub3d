/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:21:45 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/25 22:36:25 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_print_error(char *msg, t_game *game)
{
	int	i;

	i = 0;
	printf("Error\n");
	printf("%s\n", msg);
	if (game->file.fd > 0)
		close(game->file.fd);
	while (game->file.file_2d && game->file.file_2d[i])
		free(game->file.file_2d[i++]);
	if (game->file.file_2d)
		free(game->file.file_2d);
	if (game->file.line)
		free(game->file.line);
	exit (1);
}
