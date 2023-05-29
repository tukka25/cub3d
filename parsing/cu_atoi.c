/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:12:12 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/29 21:44:15 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cu_atoi(char *str)
{
	int		i;
	int		res;
	char	*trim;

	i = 0;
	res = 0;
	trim = cu_strtrimchar(str, ' ');
	while (trim[i])
	{
		if (!ft_isdigit(trim[i]))
		{
			free(trim);
			return (-1);
		}
		res = (trim[i] - '0') + (res * 10);
		if (res > 255)
		{
			free(trim);
			return (-1);
		}
		i++;
	}
	free(trim);
	return (res);
}
