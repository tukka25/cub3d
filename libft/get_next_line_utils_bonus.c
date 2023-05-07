/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:55:36 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/28 13:40:01 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*joining(char *str, char *tmp, int j)
{
	t_vars	vars;

	vars.d = 0;
	vars.i = 0;
	vars.f = ft_strdup(tmp);
	if (ft_strlen_and_ft_strchr(tmp, '\n', 0) != 0)
	{
		vars.tmp2 = ft_strjoin(str, vars.f);
		vars.s = malloc(ft_strlen_and_ft_strchr(vars.tmp2, 0, 1) + 2);
		if (!vars.s)
			return (NULL);
		if (vars.tmp2 != NULL)
			while (vars.tmp2[vars.d] != '\0')
				vars.s[vars.i++] = vars.tmp2[vars.d++];
		vars.s[vars.i] = '\n';
		vars.s[vars.i + 1] = '\0';
		free(vars.tmp2);
	}
	else if (j == BUFFER_SIZE)
		vars.s = ft_strjoin(str, vars.f);
	else if (j < BUFFER_SIZE && j != 0)
			vars.s = check_eof(&str, NULL, &vars, j);
	else
		return (free(vars.f), str);
	return (free(vars.f), free(str), vars.s);
}

size_t	ft_strlen_and_ft_strchr(char *str, int c, int n)
{
	char	tmp;
	size_t	i;

	i = -1;
	tmp = (char ) c;
	if (n == 1)
	{
		i = 0;
		if (!str || str == NULL)
			return (0);
		while (str[i] != '\0')
			i++;
		return (i);
	}
	else
	{
		if (!str)
			return (0);
		while (str[++i] != '\0')
			if (str[i] == tmp)
				return (1);
		return (0);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc((ft_strlen_and_ft_strchr(s1, 0, 1)
				+ ft_strlen_and_ft_strchr(s2, 0, 1)) * sizeof(char) + 1);
	if (!str)
		return (0);
	if (s1 != NULL)
		while (s1[i] != '\0')
			str[j++] = s1[i++];
	i = 0;
	if (s2 != NULL)
		while ((s2[i] != '\0' && s2[i] != '\n'))
			str[j++] = s2[i++];
	str[j] = '\0';
	if (*str == '\0')
		return (free(str), NULL);
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	if (s1 == NULL)
		return (NULL);
	i = ft_strlen_and_ft_strchr(s1, 0, 1);
	str = (char *)malloc((i * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*check_eof(char **str, char **buf, t_vars *vars, int p)
{
	if (p == -1)
	{
		free(*str);
		if (*buf[0] == 0)
			return (free(*buf), NULL);
		*str = ft_strdup(*buf);
		free(*buf);
		*buf = NULL;
		return (str);
	}
	vars->tmp2 = rest_less(vars->f, p);
	vars->s = ft_strjoin(*str, vars->tmp2);
	free(vars->tmp2);
	return (vars->s);
}
