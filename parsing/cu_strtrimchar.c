/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_strtrimchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:57:08 by talsaiaa          #+#    #+#             */
/*   Updated: 2023/05/30 19:56:49 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_start(char const *str, int const c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == c)
	{
		i++;
	}
	return (i);
}

static int	check_end(char const *str, int const c, int start, int len)
{
	int	end;

	end = len - 1;
	while (end > start && str[end] == c)
	{
		end--;
	}
	end++;
	return (end);
}

char	*cu_strtrimchar(char const *str, int const c)
{
	int		start;
	int		end;
	char	*trim;
	int		i;
	int		len;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	start = check_start(str, c);
	len = ft_strlen(str);
	end = check_end(str, c, start, len);
	if (!start && !end)
	{
		trim = ft_strdup(str);
		return (trim);
	}
	trim = (char *)malloc((end - start) + 1);
	if (!trim)
		return (NULL);
	while (start < end)
		trim[i++] = str[start++];
	trim[i] = 0;
	return (trim);
}
