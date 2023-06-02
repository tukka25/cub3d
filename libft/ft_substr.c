/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:58:10 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/06/02 20:55:48 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/* Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (len > (size_t) ft_strlen(s))
		len = (size_t) ft_strlen(s);
	if (len > (size_t) ft_strlen(s) - start)
		len = (size_t) ft_strlen(s) - start;
	if (start > (size_t) ft_strlen(s))
		len = 0;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	if ((size_t) start < (size_t) ft_strlen(s))
	{
		while (len--)
		{
			substr[i++] = s[(size_t) start++];
		}
	}
	substr[i] = '\0';
	return (substr);
}
