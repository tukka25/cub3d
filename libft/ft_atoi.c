/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:12:33 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/07 21:26:27 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ignore_zero(const char *str, int j)
{
	if ((str[j] == '+' || str[j] == '-') && str[j + 1] != '\0')
		++j;
	while (str[j] == '0')
		j++;
	return (j);
}

int	ft_atoi(const char *str)
{
	int					sign;
	int					j;
	unsigned long long	result;

	j = 0;
	result = 0;
	sign = 1;
	while ((str[j] >= 9 && str[j] <= 13) || (str[j] == ' '))
		j++;
	if (str[j] == '-')
		return (-1);
	j = ignore_zero(str, j);
	while (str[j] >= '0' && str[j] <= '9')
	{
		result = result * 10 + str[j++] - '0';
		if (((result > INT_MAX && sign == 1)
				|| (result > 2147483648 && sign == -1)))
			return (-1);
	}
	if ((str[j] >= ' ' && str[j] <= '/')
		|| (str[j] >= ':' && str[j] < 127)
		|| !ft_isascii(str[j]))
		return (-1);
	return (result * sign);
}
