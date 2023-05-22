/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:26:56 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/10/03 02:43:29 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j] && i < n - 1)
	{
		i++;
		j++;
	}
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[j]);
}
