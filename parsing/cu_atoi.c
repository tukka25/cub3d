/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:12:12 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/29 21:20:50 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cu_atoi(char *str)
{
	int		i;
	int		res;
	char	*tmp;

	i = 0;
	res = 0;
	tmp = cu_strtrimchar(str, ' ');
	while (tmp[i])
	{
		if (!ft_isdigit(tmp[i]))
		{
			free(tmp);
			return (-1);
		}
		res = (tmp[i] - '0') + (res * 10);
		if (res > 255)
		{
			free(tmp);
			return (-1);
		}
		i++;
	}
	free(tmp);
	return (res);
}
