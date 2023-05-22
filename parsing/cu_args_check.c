/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:16:48 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/03/15 10:38:42 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cu_args_check(int ac, char *av)
{
	if (ac != 2)
		cu_print_error("Invalid number of arguments");
	if (!ft_strchr(av, '.') || ft_strncmp("cub", (av + ft_strlen(av) - 3), 3)
		|| open(av, O_DIRECTORY) > 0 || open(av, O_RDONLY) < 0)
		cu_print_error("Argument must be a .cub file");
}