/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 04:58:15 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/23 16:08:31 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/* Function that searches for string needle in string haystack no more than len
	and returns if found the whole string*/

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
