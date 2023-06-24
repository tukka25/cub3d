/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:56:24 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/24 20:55:05 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**cu_file_to_2d(char **pre, char *line, int nline, t_cub *cub)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (nline + 1));
	if (!new)
		cu_print_error("Malloc error", cub);
	while (pre && pre[i])
	{
		new[i] = ft_strdup(pre[i]);
		free(pre[i]);
		i++;
	}
	new[i] = ft_strdup(line);
	new[i + 1] = 0;
	free(pre);
	free(line);
	return (new);
}

void	cu_saving_file(t_cub *cub)
{	
	cub->game.file.line = get_next_line(cub->game.file.fd);
	if (!cub->game.file.line)
		cu_print_error("File is empty", cub);
	while (cub->game.file.line)
	{
		cub->game.file.nline++;
		cub->game.file.file_2d = cu_file_to_2d(cub->game.file.file_2d, cub->game.file.line,
				cub->game.file.nline, cub);
		cub->game.file.line = get_next_line(cub->game.file.fd);
	}
	return ;
}
