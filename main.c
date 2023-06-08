/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:14:46 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/29 18:00:43 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	cu_init(&game);
	if (ac != 2)
		cu_print_error("Invalid number of arguments", &game);
	game.file.fd = open(av[1], O_DIRECTORY);
	if (game.file.fd > 0)
		cu_print_error("Argument cannot be a directory", &game);
	game.file.fd = open(av[1], O_RDONLY);
	cu_args_check(av[1], &game);
	cu_saving_file(&game);
	cu_saving_components(&game);
	cu_freedom(&game);
	close (game.file.fd);
	return (0);
}