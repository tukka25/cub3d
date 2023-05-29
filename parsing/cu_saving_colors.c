/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:14:04 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/29 21:44:57 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cu_saving_rgb_cmpnt(char *line, char *rgb_cmpnt, char **rgb, t_game *game)
{
	int	cmpnt;

	cmpnt = cu_atoi(rgb_cmpnt);
	if (cmpnt < 0)
	{
		free(line);
		cu_free_2d(rgb);
		cu_print_error("Invalid color identifier", game);
	}
	return (cmpnt);
}

int	cu_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	cu_check_color_args(char *line, t_game *game)
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
		cu_print_error("Invalid color identifier", game);
	}
	r = cu_saving_rgb_cmpnt(line, split[0], split, game);
	g = cu_saving_rgb_cmpnt(line, split[1], split, game);
	b = cu_saving_rgb_cmpnt(line, split[2], split, game);
	cu_free_2d(split);
	return (cu_create_rgb(r, g, b));
}

int	cu_checking_color(char *line, char *iden, t_game *game)
{
	if (cu_is_duplicate(iden, game))
	{
		free(line);
		cu_print_error("Duplicate color found", game);
	}
	return (cu_check_color_args(line, game));
}

void	cu_saving_colors(char *line, t_game *game)
{
	char	*trim;

	trim = cu_strtrimchar(line, ' ');
	if (trim[0] == 'F' && trim[1] == ' ')
		game->floor = cu_checking_color(trim, "F", game);
	else if (trim[0] == 'C' && trim[1] == ' ')
		game->ceiling = cu_checking_color(trim, "C", game);
	else if ((trim[0] == 'F' && trim[1] != ' ')
		|| (trim[0] == 'C' && trim[1] != ' '))
	{
		free(trim);
		cu_print_error("Invalid color identifier", game);
	}
	free(trim);
	return ;
}
