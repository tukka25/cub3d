/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 02:02:59 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/08 04:17:46 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
	{
		i++;
	}
	if (str[i] == '\n')
		return (1);
	return (0);
}

int	len_till_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	insert_map(t_cub *cub, char *av)
{
	cub->i = 0;
	cub->fd = open(av, O_RDONLY);
	if (cub->fd < 0)
		return ;
	cub->line = get_next_line(cub->fd);
	while (cub->line)
	{
		if (!ft_strnstr(cub->line, "SO", 2) && !ft_strnstr(cub->line, "NO", 2)
			&& !ft_strnstr(cub->line, "WE", 2)
			&& !ft_strnstr(cub->line, "EA", 2)
			&& !ft_strnstr(cub->line, "F", 1) && !ft_strnstr(cub->line, "C", 1)
			&& !ft_strnstr(cub->line, "\n", 1) && all_spaces(cub->line) == 0)
		{
			cub->map[cub->i] = ft_substr(cub->line, 0, len_till_nl(cub->line));
			cub->i++;
		}
		free(cub->line);
		cub->line = get_next_line(cub->fd);
	}
	cub->map[cub->i] = NULL;
	cub->i = 0;
	while (cub->map[cub->i])
	{
		printf("%s\n", cub->map[cub->i]);
		cub->i++;
	}
}

void	map_pars(t_cub *cub)
{
	cub->i = 0;
	cub->j = 0;
	while (cub->map[cub->i])
	{
		cub->j = 0;
		while (cub->map[cub->i][cub->j])
		{
			if (cub->map[cub->i][cub->j] != '1' && cub->map[cub->i][cub->j] != '0'
				&& cub->map[cub->i][cub->j] != 'N'
				&& cub->map[cub->i][cub->j] != 'E'
				&& cub->map[cub->i][cub->j] != 'S'
				&& cub->map[cub->i][cub->j] != 'W'
				&& cub->map[cub->i][cub->j] != ' '
				&& cub->map[cub->i][cub->j] != '\t')
			{
				free_and_exit(cub, "Invalid Map Content\n");
			}
			cub->j++;
		}
		cub->i++;
	}
}
