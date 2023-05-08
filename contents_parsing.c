/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:53:12 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/08 03:59:20 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	insert_to_array(char **str, int *arr)
{
	int	i;

	i = 0;
	if (ft_strlen_2d(str) > 3)
	{
		free_strings(str);
		error_exit("Floor Wrong Inputs\n");
	}
	arr = malloc(4 * sizeof(int));
	if (!arr)
		return ;
	while (str[i])
	{
		arr[i] = ft_atoi(str[i]);
		if (arr[i] > 255 || arr[i] == -1)
		{
			free(arr);
			free_strings(str);
			error_exit("Floor Wrong Inputs\n");
		}
		i++;
	}
	arr[i] = '\0';
}

void	check_req(t_cub *cub, char *line)
{
	char	**str;
	int		i;

	cub->tmp = NULL;
	i = 0;
	str = NULL;
	str = ft_split(line, ' ');
	if (!str)
		return ;
	if (ft_strcmp("F", str[0]) == 0)
	{
		if (ft_strlen_2d(str) > 2)
		{
			free_strings(str);
			error_exit("Floor Wrong Inputs\n");
		}
		cub->tmp = ft_split(str[1], ',');
		insert_to_array(cub->tmp, cub->f_colors);
	}
	if (ft_strcmp("C", str[0]) == 0)
	{
		if (ft_strlen_2d(str) > 2)
		{
			free_strings(str);
			error_exit("Ceiling Wrong Inputs\n");
		}
		cub->tmp = ft_split(str[1], ',');
		insert_to_array(cub->tmp, cub->c_colors);
	}
	free(cub->tmp);
	free(str);
}

static int	map_length(int fd, t_cub *cub)
{
	int	i;

	i = 0;
	cub->line = get_next_line(cub->fd);
	while (cub->line)
	{
		if (!ft_strnstr(cub->line, "SO", 2) && !ft_strnstr(cub->line, "NO", 2)
			&& !ft_strnstr(cub->line, "WE", 2)
			&& !ft_strnstr(cub->line, "EA", 2)
			&& !ft_strnstr(cub->line, "F", 1) && !ft_strnstr(cub->line, "C", 1)
			&& !ft_strnstr(cub->line, "\n", 1) && all_spaces(cub->line) == 0)
		{
			i++;
		}
		free(cub->line);
		cub->line = get_next_line(cub->fd);
	}
	close(fd);
	return (i);
}

void	check_map(t_cub *cub, char *av)
{
	cub->i = 0;
	cub->line = NULL;
	cub->tmp = NULL;
	cub->fd = open(av, O_RDONLY);
	if (cub->fd < 0)
		error_exit("Map Error\n");
	cub->i = map_length(cub->fd, cub);
	cub->map = malloc((cub->i + 1) * sizeof(char *));
	if (!cub->map)
		exit(0);
	insert_map(cub, av);
	// cub->line = get_next_line(cub->fd);
	// while (cub->line)
	// {
	// 	cub->tmp = ft_split(cub->line, ' ');
	// 	if (cub->tmp)
	// 	{
	// 		if (ft_strcmp("SO", cub->line) && ft_strcmp("NO", cub->tmp[0]) && ft_strcmp("WE", cub->tmp[0]) && ft_strcmp("EA", cub->tmp[0]) && ft_strcmp("F", cub->tmp[0]) && ft_strcmp("C", cub->tmp[0]))
	// 		{
				
	// 		}
	// 	}
	// 	free(cub->line);
	// 	cub->line = get_next_line(cub->fd);
	// }
}
