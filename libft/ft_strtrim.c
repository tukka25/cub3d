/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 23:24:35 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/10/10 05:37:03 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	check_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[start])
				start++;
			j++;
		}
		i++;
	}
	return (start);
}

static	int	check_end(char const *s1, char const *set, int start, int len)
{
	int	j;
	int	end;

	j = 0;
	end = len - 1;
	while (len > start)
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[end])
				end--;
			j++;
		}
		len--;
	}
	end++;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trim;
	int		i;
	int		len;

	i = 0;
	if (s1 == 0)
		return (0);
	start = check_start(s1, set);
	len = ft_strlen(s1);
	end = check_end(s1, set, start, len);
	trim = (char *)malloc((end - start) + 1);
	if (trim == 0)
		return (0);
	while (start < end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}
