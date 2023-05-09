/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:53:12 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/09 17:19:34 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*insert_to_array(char **str)
{
	int	i;
	int	*arr;

	i = 0;
	if (ft_strlen_2d(str) > 3)
	{
		free_strings(str);
		error_exit("Floor Wrong Inputs\n");
	}
	arr = malloc(4 * sizeof(int));
	if (!arr)
		return (NULL);
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
	return (arr);
}

void	check_req(t_cub *cub, char *line)
{
	char	**str;

	cub->tmp = NULL;
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
		cub->f_colors = insert_to_array(cub->tmp);
	}
	if (ft_strcmp("C", str[0]) == 0)
	{
		if (ft_strlen_2d(str) > 2)
		{
			free_strings(str);
			error_exit("Ceiling Wrong Inputs\n");
		}
		cub->tmp = ft_split(str[1], ',');
		cub->c_colors = insert_to_array(cub->tmp);
	}
	free_strings(cub->tmp);
	free_strings(str);
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
	map_pars(cub);
	// printf("px = %c\n", cub->map[cub->m.py_index][cub->m.px_index]);
	// printf("py = %d\n", cub->m.py_index);
}
