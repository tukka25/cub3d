/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:14:04 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/29 21:31:29 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cu_saving_rgb(char *line, char *rgb_cmpnt, char **rgb, t_game *game)
{
	int	tmp;

	tmp = cu_atoi(rgb_cmpnt);
	if (tmp < 0)
	{
		free(line);
		cu_free_2d(rgb);
		cu_print_error("Invalid color identifier", game);
	}
	return (tmp);
}

int	cu_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	cu_check_color_args(char *line, t_game *game)
{
	char	**tmp;
	int		r;
	int		g;
	int		b;

	line[0] = ' ';
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	tmp = ft_split(line, ',');
	if (!tmp[1] || !tmp[2])
	{
		free(line);
		cu_free_2d(tmp);
		cu_print_error("Invalid color identifier", game);
	}
	r = cu_saving_rgb(line, tmp[0], tmp, game);
	g = cu_saving_rgb(line, tmp[1], tmp, game);
	b = cu_saving_rgb(line, tmp[2], tmp, game);
	cu_free_2d(tmp);
	return (cu_create_rgb(r, g, b));
}

int	cu_checking_color(char *line, char *cmp, t_game *game)
{
	if (cu_is_duplicate(cmp, game))
	{
		free(line);
		cu_print_error("Duplicate color found", game);
	}
	return (cu_check_color_args(line, game));
}

void	cu_saving_colors(char *line, t_game *game)
{
	char	*tmp;

	tmp = cu_strtrimchar(line, ' ');
	if (tmp[0] == 'F' && tmp[1] == ' ')
		game->floor = cu_checking_color(tmp, "F", game);
	else if (tmp[0] == 'C' && tmp[1] == ' ')
		game->ceiling = cu_checking_color(tmp, "C", game);
	else if ((tmp[0] == 'F' && tmp[1] != ' ')
		|| (tmp[0] == 'C' && tmp[1] != ' '))
	{
		free(tmp);
		cu_print_error("Invalid color identifier", game);
	}
	free(tmp);
	return ;
}
