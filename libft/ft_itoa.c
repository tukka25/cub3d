/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:58:31 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/10/17 02:34:15 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	digit_counter(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
		i = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*mallocating(int n)
{
	int		i;
	char	*itoa;

	i = digit_counter(n);
	itoa = (char *)malloc(i + 1);
	if (itoa == NULL)
		return (NULL);
	itoa[i] = '\0';
	return (itoa);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*itoa;

	len = digit_counter(n) - 1;
	itoa = mallocating(n);
	if (n == -2147483648)
	{
		itoa[len] = '8';
		len = len - 1;
		n = -214748364;
	}
	if (n < 0)
	{
		itoa[0] = '-';
		n = n * -1;
	}
	while (n > 9)
	{
		itoa[len--] = n % 10 + 48;
		n = n / 10;
	}
	if (n <= 9)
		itoa[len] = n + 48;
	return (itoa);
}
