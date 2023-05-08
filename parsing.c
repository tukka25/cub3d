/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:39:11 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/08 04:12:26 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_cub(t_cub *cub)
{
	cub->i = 0;
	cub->j = 0;
	cub->map = NULL;
}

static void	check_map_file(char **av)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_exit("Map Error\n");
	close(fd);
}

static void	floor_ceiling_init(int fd, t_cub *cub)
{
	char	*line;

	line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		check_req(cub, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	check_map_content(t_cub *cub, char *av)
{
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_exit("Map Error\n");
	floor_ceiling_init(fd, cub);
	check_map(cub, av);
}

void	pars(char **av, t_cub *cub)
{
	init_cub(cub);
	check_map_file(av);
	check_map_content(cub, av[1]);
}
