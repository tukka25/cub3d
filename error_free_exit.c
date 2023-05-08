/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:49:18 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/08 04:11:11 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	free_strings(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_and_exit(t_cub *cub, char *str)
{
	if (cub->c_colors)
		free(cub->c_colors);
	if (cub->f_colors)
		free(cub->f_colors);
	if (cub->map)
		free_strings(cub->map);
	if (str)
		ft_putstr_fd(str, 2);
	exit (1);
}
