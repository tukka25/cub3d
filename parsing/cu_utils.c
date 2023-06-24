/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:06:01 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/24 21:13:46 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_args_check(char *av, t_cub *cub)
{
	if (!ft_strchr(av, '.') || ft_strncmp(".cub", (av + ft_strlen(av) - 4), 4)
		|| cub->game.file.fd < 0)
		cu_print_error("Argument must be an existing .cub file", cub);
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

void	cu_init(t_cub *cub)
{
	cub->game.north = NULL;
	cub->game.south = NULL;
	cub->game.west = NULL;
	cub->game.east = NULL;
	cub->game.floor = -1;
	cub->game.ceiling = -1;
	cub->game.file.fd = 0;
	cub->game.file.nline = 0;
	cub->game.file.line = NULL;
	cub->game.file.file_2d = NULL;
	cub->game.map.map_2d = NULL;
	cub->game.map.map_pos = -1;
	cub->game.map.nline = 0;
	cub->game.map.p_x = -1;
	cub->game.map.p_y = -1;
	cub->game.map.p_direction = 0;
	cub->game.map.map_width = 0;
	return ;
}

void	cu_print_error(char *msg, t_cub *cub)
{
	printf("Error\n");
	printf("%s\n", msg);
	if (cub->game.file.fd > 0)
		close(cub->game.file.fd);
	cu_freedom(cub);
	exit (1);
}

void	cu_check_missing(t_cub *cub)
{
	if (!cub->game.north || !cub->game.south || !cub->game.west || !cub->game.east)
		cu_print_error("Texture identifier not found", cub);
	if (cub->game.floor == -1 || cub->game.ceiling == -1)
		cu_print_error("Color identifier not found", cub);
	if (!cub->game.map.map_2d)
		cu_print_error("Map not found", cub);
	if (!cub->game.map.p_direction)
		cu_print_error("Player not found", cub);
}
