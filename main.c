/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:14:46 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/22 16:59:12 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	
	game.file.fd = open(av[1], O_RDONLY);
	cu_args_check(ac, av[1]);
	cu_saving_file(&game);
	// for(int i = 0; game.file.file2D[i] != NULL; i++)
	// 	printf("%s", game.file.file2D[i]);
	printf("\n%d\n", game.file.nline);
	close (game.file.fd);
	return 0;
}