/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:06:01 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/21 20:17:01 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_args_check(char *av, t_game *game)
{
	if (!ft_strchr(av, '.') || ft_strncmp(".cub", (av + ft_strlen(av) - 4), 4)
		|| game->file.fd < 0)
		cu_print_error("Argument must be an existing .cub file", game);
	return ;
}

int	cu_atoi(char *str)
{
	int		i;
	int		res;
	char	*trim;

	i = 0;
	res = 0;
	trim = cu_strtrimchar(str, ' ');
	if (!trim || !trim[i])
		return (-1);
	while (trim[i])
	{
		res = (trim[i] - '0') + (res * 10);
		if (res > 255 || !ft_isdigit(trim[i]))
		{
			free(trim);
			return (-1);
		}
		i++;
	}
	free(trim);
	return (res);
}

void	cu_init(t_game *game)
{
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->floor = -1;
	game->ceiling = -1;
	game->file.fd = 0;
	game->file.nline = 0;
	game->file.line = NULL;
	game->file.file_2d = NULL;
	game->map.map_2d = NULL;
	game->map.map_pos = -1;
	game->map.nline = 0;
	game->map.p_x = -1;
	game->map.p_y = -1;
	game->map.p_direction = 0;
	return ;
}

void	cu_print_error(char *msg, t_game *game)
{
	printf("Error\n");
	printf("%s\n", msg);
	if (game->file.fd > 0)
		close(game->file.fd);
	cu_freedom(game);
	exit (1);
}

void	cu_check_missing(t_game *game)
{
	if (!game->north || !game->south || !game->west || !game->east)
		cu_print_error("Texture identifier not found", game);
	if (game->floor == -1 || game->ceiling == -1)
		cu_print_error("Color identifier not found", game);
	if (!game->map.map_2d)
		cu_print_error("Map not found", game);
	if (!game->map.p_direction)
		cu_print_error("Player not found", game);
}
