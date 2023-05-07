/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:21:22 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/23 15:30:38 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (2, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write (2, &str[i], 1);
			i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write (2, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write (2, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}

int	ft_uputnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_uputnbr(nb / 10);
		i += ft_uputnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}

int	hexa_upper(unsigned int x)
{
	int		i;
	char	str[100];

	i = 0;
	while (x / 16 != 0)
	{
		if (x % 16 >= 10 && x % 16 <= 15)
			str[i++] = x % 16 + 55;
		else
			str[i++] = x % 16 + 48;
		x = x / 16;
	}
	if (x % 16 >= 10 && x % 16 <= 15)
		str[i++] = x % 16 + 55;
	else
		str[i++] = x % 16 + 48;
	str[i] = '\0';
	i = i - 1;
	while (i >= 0)
		write(2, &str[i--], 1);
	return (ft_strlen(str));
}
