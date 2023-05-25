/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:16:48 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/25 22:21:06 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_args_check(char *av, t_game *game)
{
	if (!ft_strchr(av, '.') || ft_strncmp("cub", (av + ft_strlen(av) - 3), 3)
		|| game->file.fd < 0)
		cu_print_error("Argument must be an existing .cub file", game);
	close(game->file.fd);
	return ;
}
