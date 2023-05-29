/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:14:04 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/29 19:02:14 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_rgb(int r, int g, int b)
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
		cu_free_2d(tmp);
		cu_print_error("Invalid color identifier", game);
	}
	r = cu_atoi(tmp[0]);
	g = cu_atoi(tmp[1]);
	b = cu_atoi(tmp[2]);
	if (r < 0 || g < 0 || b < 0)
	{
		cu_free_2d(tmp);
		cu_print_error("Invalid color number", game);
	}
	cu_free_2d(tmp);
	return (create_rgb(r, g, b));
}

int	cu_checking_color(char *line, char *cmp, t_game *game)
{
	cu_check_duplicate(cmp, game);
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
	free(tmp);
	return ;
}
