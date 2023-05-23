/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_saving_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:56:24 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/23 18:22:09 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	cu_file_line_counter(int fd)
{
	char	*tmp;
	int		i;
	
	i = 0;
	tmp = get_next_line(fd);
	if (tmp == 0)
		cu_print_error("File is empty");
	i++;
	while (tmp)
	{
		tmp = get_next_line(fd);
		free(tmp);
		i++;
		if (!tmp)
			break ;
	}
	close(fd);
	return (i);
}

void	cu_saving_file(t_game *game)
{
	int	i;
	
	i = 0;
	game->file.nline = cu_file_line_counter(game->file.fd);
	game->file.file_2d = (char **)malloc((game->file.nline + 1) * sizeof(char *));
	if (!game->file.file_2d)
		cu_print_error("Malloc error");
	game->file.line = get_next_line(game->file.fd);
	printf("%s", game->file.line);
// 	game->file.file_2d[i] = ft_strdup(game->file.line);
// 	free(game->file.line);
// 	printf("%s", game->file.file_2d[i]);
// 	return ;
}
