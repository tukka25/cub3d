/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:14:04 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/24 20:53:11 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cu_saving_rgb_cmpnt(char *line, char *rgb_cmpnt, char **rgb, t_cub *cub)
{
	int	cmpnt;

	cmpnt = cu_atoi(rgb_cmpnt);
	if (cmpnt < 0)
	{
		free(line);
		cu_free_2d(rgb);
		cu_print_error("Invalid color numbers", cub);
	}
	return (cmpnt);
}

int	cu_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	cu_check_color_args(char *line, t_cub *cub)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	line[0] = ' ';
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	split = ft_split(line, ',');
	if (!split[1] || !split[2])
	{
		free(line);
		cu_free_2d(split);
		cu_print_error("Invalid color args", cub);
	}
	r = cu_saving_rgb_cmpnt(line, split[0], split, cub);
	g = cu_saving_rgb_cmpnt(line, split[1], split, cub);
	b = cu_saving_rgb_cmpnt(line, split[2], split, cub);
	cu_free_2d(split);
	return (cu_create_rgb(r, g, b));
}

int	cu_checking_color(char *line, char *iden, t_cub *cub)
{
	if (cu_is_duplicate(iden, cub))
	{
		free(line);
		cu_print_error("Duplicate color found", cub);
	}
	cu_is_2_commas(line, cub);
	return (cu_check_color_args(line, cub));
}

void	cu_saving_colors(char *line, t_cub *cub)
{
	char	*trim;

	trim = cu_strtrimchar(line, ' ');
	if (trim[0] == 'F' && trim[1] == ' ')
		cub->game.floor = cu_checking_color(trim, "F", cub);
	else if (trim[0] == 'C' && trim[1] == ' ')
		cub->game.ceiling = cu_checking_color(trim, "C", cub);
	else if ((trim[0] == 'F' && trim[1] != ' ')
		|| (trim[0] == 'C' && trim[1] != ' '))
	{
		free(trim);
		cu_print_error("Invalid color identifier", cub);
	}
	free(trim);
	return ;
}
