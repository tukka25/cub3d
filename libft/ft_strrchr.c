/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 04:45:51 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/10/12 16:46:20 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int		i;
	unsigned char		*dest;

	i = 0;
	dest = (unsigned char *)s;
	while (dest[i])
		i++;
	while (i + 1)
	{
		if (dest[i] == (unsigned char )c)
			return (&((char *)dest)[i]);
		i--;
	}
	return (0);
}
