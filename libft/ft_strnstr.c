/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 04:58:15 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/10/16 01:21:31 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == 0)
		return (&((char *)haystack)[j]);
	while (haystack[i] && i < len)
	{
		i = i - j;
		j = 0;
		while (needle [j] && needle[j] == haystack[i] && i < len)
		{
			j++;
			i++;
		}
		if (needle[0] == haystack[i - j] && needle[j] == 0)
			return (&((char *)haystack)[i - j]);
		i++;
	}
	return (0);
}
