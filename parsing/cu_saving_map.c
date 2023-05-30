/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:47:00 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/30 21:22:34 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	cu_is_map_begininng(char *line)
{
	int		i;
	char	*dup;
	char	*trim;

	i = 0;
	dup = ft_strdup(line);
	if (dup[ft_strlen(dup) - 1] == '\n')
		dup[ft_strlen(dup) - 1] = 0;
	if (!dup || !dup[i])
		return (false);
	trim = cu_strtrimchar(dup, ' ');
	free(dup);
	if (!trim || !trim[i])
		return (false);
	while(trim[i])
	{
		if (trim[i] != '1' && trim[i] != ' ')
			return (false);
		i++;
	}
	free(trim);
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

int		cu_2d_len(char **arrays)
{
	int	i;

	if (!arrays)
		return (0);
	i = 0;
	while (arrays && arrays[i])
		i++;
	return (i);
}

void	cu_saving_map(char *line, int index, t_game *game)
{	
	if (!cu_is_map_begininng(line) && game->map.map_pos == -1)
		return ;
	if (game->map.map_pos != -1)
		return ;
	if (!game->north && !game->south && !game->west && !game->east
		&& game->floor == -1 && game->ceiling == -1)
		cu_print_error("Map should be the last thing in the file", game);
	if (game->map.map_pos == -1)
	{
		game->map.map_pos = index;
		game->map.map_2d = cu_2d_dup(game->file.file_2d, index,
			(game->file.nline - index));
	}
	game->map.nline = cu_2d_len(game->map.map_2d);
	/* after making sure the last line is correct, run this check
	if (game->map.nline + game->map.map_pos != game->file.nline)
		cu_print_error("Map should be the last thing in the file", game); */
	return ;
}
