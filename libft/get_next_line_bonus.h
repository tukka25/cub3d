/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:40 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/28 20:56:15 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_vars
{
	int		i;
	int		d;
	char	*tmp2;
	char	*s;
	char	*f;
}	t_vars;

typedef struct read_vars
{
	char			*tmp;
	char			*str;
	int				n_pos;
}	t_rvars;

char	*get_next_line(int fd);

size_t	ft_strlen_and_ft_strchr(char *str, int c, int n);

char	*ft_strdup(char *s1);

char	*ft_strjoin(char *s1, char *s2);

char	*joining(char *str, char *tmp, int j);

char	*rest_less(char *buf, int j);

char	*ft_substr(char *s, unsigned int start, size_t len);

char	*saving(char *buf, int d);

char	*handle(char *buf, int j);

void	*check_eof(char **str, char **buf, t_vars *vars, int p);
#endif