/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:42:59 by cshinoha          #+#    #+#             */
/*   Updated: 2020/03/14 16:18:12 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "ft_printf.h"
# define BUFF_SIZE 300
# define BASE_LOWER "0123456789abcdefghijklmnopqrstuvwxyz"
# define BASE_UPPER "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_statement
{
	char			*res;
	int				fd;
}					t_stmt;

int					ft_error(char *mes, int code);
int					ft_error_fd(int fd, char *mes, int code);
void				*ft_tmemalloc(size_t type_size, size_t amount);
void				*ft_tmalloc(size_t type_size, size_t amount);
char				*ft_strsplbyindex(char const *s, char c, int index);
intmax_t			ft_abs(intmax_t n);
void				ft_lstfree(t_list *node, size_t len);
t_list				*ft_lstpush(t_list **begin_list,
									void *content,
									size_t content_size);
int					ft_gnl(int fd, char **line);
t_list				*ft_lstnew(void const *content, size_t content_size);
char				**ft_freematr(char **matr);
char				*ft_memcpy(void *dst, const void *src, size_t len);
void				ft_bzero(void *dst, size_t len);
intmax_t			ft_min(intmax_t x, intmax_t y);
intmax_t			ft_max(intmax_t x, intmax_t y);
void				*ft_memset(void *dst, int c, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *dst, const void *src, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
size_t				ft_sizemin(size_t n1, size_t ni2);
char				*ft_strchr(const char *s, int c);
long long			ft_strindexof(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strstartwith(char *ref, char *stack);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const*s2);
char				*ft_strfrjoin(char *s1, char *s2);
int					ft_iswhite(char c);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putchar_fd(int fd, char c);
void				ft_putstr(char const *s);
void				ft_putstr_fd(int fd, char const *s);
void				ft_putstrs(char **ar);
char				*ft_itoa(int n);
void				ft_putstrss(char **ar, int c);
void				ft_putstrss_fd(int fd, char **ar, int c);
void				ft_putendl(char const *s);
void				ft_putendl_fd(int fd, char const *s);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int fd, int n);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_intlen(int n);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isspace(int c);
int					ft_isseparator(char c, char separator);
int					ft_cntwords(char const *s, char c);
size_t				ft_nblen(long long n);
void				ft_swap(void *a, void *b, size_t size);
char				*ft_sitoa_base(intmax_t number, int base, int uppercase);
size_t				ft_silen(intmax_t number, int base);
char				*ft_uitoa_base(uintmax_t number, int base, int uppercase);
size_t				ft_uilen(uintmax_t number, int base);
char				*ft_litoa(intmax_t number);
char				*ft_itoa_static(int number);
char				*ft_litoa_static(intmax_t n);
char				*ft_sitoa_base_static(intmax_t number, int base,
											int uppercase);
char				*ft_uitoa_base_static(uintmax_t number, int base,
											int uppercase);
char				*ft_ftoa_static(double number, unsigned int precision);

#endif
