/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:39:48 by abdamoha          #+#    #+#             */
/*   Updated: 2023/02/02 21:41:41 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);

int		ft_isalnum(int a);

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_bzero(void *str, size_t n);

int		ft_toupper(int n);

int		ft_tolower(int n);

size_t	ft_strlen(const char *str);

void	*ft_memset(void *str, int ch, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

int		ft_isprint(int x);

int		ft_isdigit(int f);

int		ft_isascii(int c);

int		ft_isalpha(int a);

void	*ft_calloc(size_t count, size_t size);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_strdup(const char *s1);

char	*ft_strrchr(const char *s, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	**ft_split(char const *s, char c);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_itoa(int n);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *));

#endif