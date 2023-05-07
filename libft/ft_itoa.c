/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:19:11 by abdamoha          #+#    #+#             */
/*   Updated: 2022/10/24 20:24:40 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_of_digits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while ((n / 10) != 0)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

static char	*printing(long nb, int len, char *str)
{
	char	result;

	while (nb > 0)
	{
		result = (nb % 10) + '0';
		str[len - 1] = result;
		nb = nb / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	nb = n;
	len = number_of_digits(nb);
	str = malloc(len * (sizeof(char)) + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	str = printing(nb, len, str);
	return (str);
}
