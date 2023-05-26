/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:21:45 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/26 21:14:29 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_print_error(char *msg, t_game *game)
{
	printf("Error\n");
	printf("%s\n", msg);
	if (game->file.fd > 0)
		close(game->file.fd);
	cu_freedom(game);
	exit (1);
}
