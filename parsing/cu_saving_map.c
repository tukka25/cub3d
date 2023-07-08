/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:47:00 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/07/06 15:31:45 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*cu_dup_and_trim(char *line)
{
	char	*dup;
	char	*trim;

	dup = ft_strdup(line);
	if (dup[ft_strlen(dup) - 1] == '\n')
		dup[ft_strlen(dup) - 1] = 0;
	if (!dup[0])
	{
		free (dup);
		return (NULL);
	}
	trim = cu_strtrimchar(dup, ' ');
	free(dup);
	if (!trim)
	{
		free(trim);
		return (NULL);
	}
	return (trim);
}

bool	cu_is_map_begininng(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = cu_dup_and_trim(line);
	if (!tmp)
	{
		free(tmp);
		return (false);
	}
	while (tmp[i])
	{
		if (tmp[i] != '1' && tmp[i] != ' ' && tmp[i] != '0' && tmp[i] != 'N'
			&& tmp[i] != 'S' && tmp[i] != 'W' && tmp[i] != 'E')
		{
			free(tmp);
			return (false);
		}
		i++;
	}
	free(tmp);
	return (true);
}

char	**cu_2d_dup(char **arrays, int start, int nline)
{
	char	**dup;
	int		i;

	dup = (char **)malloc(sizeof(char *) * (nline + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (arrays && arrays[start])
		dup[i++] = ft_strdup(arrays[start++]);
	dup[i] = 0;
	return (dup);
}

int	cu_2d_len(char **arrays)
{
	int	i;

	if (!arrays)
		return (0);
	i = 0;
	while (arrays && arrays[i])
		i++;
	return (i);
}

void	cu_saving_map(char *line, int index, t_cub *cub)
{
	if (!cu_is_map_begininng(line) && cub->game.map.map_pos == -1)
		return ;
	if (cub->game.map.map_pos != -1)
		return ;
	if (!cub->game.north || !cub->game.south || !cub->game.west
		|| !cub->game.east || cub->game.floor == -1 || cub->game.ceiling == -1)
		cu_print_error("Map should be the last thing in the file", cub);
	if (cub->game.map.map_pos == -1)
	{
		cub->game.map.map_pos = index;
		cub->game.map.map_2d = cu_2d_dup(cub->game.file.file_2d, index,
				(cub->game.file.nline - index));
	}
	cub->game.map.nline = cu_2d_len(cub->game.map.map_2d);
	cu_check_map(cub);
	return ;
}
