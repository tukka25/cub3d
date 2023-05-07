/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:22:19 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/12 18:11:21 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	printingaddress(unsigned long n)
{
	int		i;

	i = 0;
	write(2, "0", 1);
	write(2, "x", 1);
	i = hexa_address(n);
	return (2 + i);
}

// static size_t	ft_strlen(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

int	hexa_lower(unsigned int x)
{
	int		i;
	char	str[100];

	i = 0;
	while (x / 16 != 0)
	{
		if (x % 16 >= 10 && x % 16 <= 15)
			str[i++] = x % 16 + 87;
		else
			str[i++] = x % 16 + 48;
		x = x / 16;
	}
	if (x % 16 >= 10 && x % 16 <= 15)
		str[i++] = x % 16 + 87;
	else
	{
		str[i++] = x % 16 + 48;
	}
	str[i] = '\0';
	i = i - 1;
	while (i >= 0)
		write(2, &str[i--], 1);
	return (ft_strlen(str));
}

int	hexa_address(unsigned long x)
{
	int		i;
	char	str[100];

	i = 0;
	while (x / 16 != 0)
	{
		if (x % 16 >= 10 && x % 16 <= 15)
			str[i++] = x % 16 + 87;
		else
			str[i++] = x % 16 + 48;
		x = x / 16;
	}
	if (x % 16 >= 10 && x % 16 <= 15)
		str[i++] = x % 16 + 87;
	else
	{
		str[i++] = x % 16 + 48;
	}
	str[i] = '\0';
	i = i - 1;
	while (i >= 0)
		write(2, &str[i--], 1);
	return (ft_strlen(str));
}
