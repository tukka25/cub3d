/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:18:20 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/10/12 16:35:01 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned int			i;
	unsigned char			*dest;

	i = 0;
	dest = (unsigned char *)s;
	while (dest[i])
	{
		if (dest[i] == (unsigned char )c)
			return (&((char *)dest)[i]);
		i++;
	}
	if (c == '\0')
		return (&((char *)dest)[i]);
	return (0);
}
