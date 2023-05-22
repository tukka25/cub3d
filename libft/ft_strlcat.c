/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:57:36 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/10/16 00:56:15 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;

	i = 0;
	j = ft_strlen(dst);
	x = j;
	y = ft_strlen(src);
	if (dstsize == x)
		return (y + x);
	if (x > dstsize)
		return (y + dstsize);
	if (dstsize == 0)
		return (y);
	while (src[i] && (i < dstsize - x - 1))
		dst[j++] = src[i++];
	dst[j] = 0;
	return (y + x);
}
