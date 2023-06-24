/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:14:46 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/24 20:54:44 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

// int	main(int ac, char **av)
// {
// 	t_game	game;

// 	cu_init(&cub);
// 	if (ac != 2)
// 		cu_print_error("Invalid number of arguments", &cub);
// 	game.file.fd = open(av[1], O_DIRECTORY);
// 	if (game.file.fd > 0)
// 		cu_print_error("Argument cannot be a directory", &cub);
// 	game.file.fd = open(av[1], O_RDONLY);
// 	cu_args_check(av[1], &cub);
// 	cu_saving_file(&cub);
// 	cu_saving_components(&cub);
// 	cu_freedom(&cub);
// 	close (game.file.fd);
// 	return (0);
// }
