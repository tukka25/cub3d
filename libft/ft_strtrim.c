/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:53:09 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/09 23:47:47 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(char const *set, char c)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

static int	check_begining(char const *s1, char const *set)
{
	int	i;
	int	count2;

	i = 0;
	count2 = 0;
	while (s1[i] != '\0')
	{
		if (checker(set, s1[i]) == 1)
				count2++;
		else if (checker(set, s1[i]) == 0)
			return (count2);
		i++;
	}
	return (count2);
}

static int	check_end(char const *s1, char const *set)
{
	int	i;
	int	count1;

	i = ft_strlen(s1) - 1;
	count1 = 0;
	while (i > 0)
	{
		if (checker(set, s1[i]) == 1)
				count1++;
		else if (checker(set, s1[i]) == 0)
			return (count1);
		i--;
	}
	return (count1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	size_t	count;
	char	*new_string;

	if (!s1 || !set)
		return (NULL);
	count = check_end(s1, set) + check_begining(s1, set);
	if (count >= ft_strlen(s1))
		return (ft_strdup(""));
	len = ft_strlen(s1) - count;
	if (len == 0)
	{
		new_string = malloc(1);
		new_string[0] = '\0';
		return (new_string);
	}
	count = check_begining(s1, set);
	new_string = ft_substr(s1, count, len);
	if (!new_string)
		return (NULL);
	new_string[len] = '\0';
	return (new_string);
}
