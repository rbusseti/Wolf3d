/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 21:16:15 by rbusseti          #+#    #+#             */
/*   Updated: 2014/10/12 17:47:21 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_list
{
    struct s_list	*prev;
    struct s_list	*next;
    void		*content;
}			t_list;

/*
** STRINGS
*/

char				*ft_strjoin_char(char const *str, char c);
char				**ft_strsplit(char const *s1, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strequ(char const *s1, char const *s2);
int			       	ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *str);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
char				*ft_strdup(char const *str1);
char				*ft_strcpy(char *s1, char const *s2);
char				*ft_strncpy(char *s1, char const *s2, size_t n);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncat(char *s1, char const *s2, size_t n);
size_t				ft_strlen(char const *str);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
char				*ft_strstr(char const *s1, char const *s2);
char				*ft_strnstr(char const *s1, char const *s2, size_t n);
int				ft_strcmp(char const *s1, char const *s2);
int			      	ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_strcmp_case(char *s1, char *s2);

/*
** LIST
*/

t_list				*ft_create_elem(void *content);
int				ft_list_push_back(t_list **list, void *content);
void				ft_delete_link(t_list **list);

/*
** GET NEXT LINE
*/

int		       		get_next_line(int const fd, char **line);
char				*ft_strjoin_gnl(char const *s1, char const *s2);
char				*ft_strdup_gnl(const char *str);

/*
** PRINT
*/

void				ft_putchar(char c);
void				ft_putendl(char const *str);
void				ft_putnbr(int c);
void				ft_putstr(char const *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putchar_fd(char c, int fd);

/*
** MEMORY
*/

void				ft_memdel(void **ad);
void				*ft_memalloc(size_t size);
int	       			ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t len);

/*
** IS IT ?
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

/*
** CONVERT
*/

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(char const *str);
char					*ft_itoa(int n);

/*
** OTHERS
*/

int					ft_tputs_putchar(int c);

#endif
