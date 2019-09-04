/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:03:02 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/29 18:12:53 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_abs(intmax_t i);
void				*ft_memset(void *ptr, int value, size_t length);
void				ft_bzero(void *str, unsigned int length);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memccpy(void *dest, const void *src,
								int stop, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *str, int waldo, size_t length);
int					ft_memcmp(const void *str1, const void *str2,
								size_t length);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t length);
char				*ft_strndup(const char *src, size_t n);
char				*ft_strcat(char *dest, const char *addition);
char				*ft_strncat(char *dest, const char *addition,
								size_t length);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *src, int waldo);
char				*ft_strrchr(const char *src, int waldo);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int letter);
int					ft_toupper(int letter);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strjoin_free_s1(char*s1, const char *s2);
char				*ft_strjoin_free_s2(const char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_lutoa(unsigned long n);
char				*ft_lltoa_base(intmax_t n, int base, int upper);
char				*ft_llutoa_base(uintmax_t n, int base, int upper);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new_lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list	*(*f)(t_list *elem));
void				ft_lstadd_end(t_list **alst, t_list *new_node);
int					ft_pow(int num, int power);
int					ft_numlen(intmax_t n);
int					ft_unumlen(uintmax_t n);
int					ft_lstlen(t_list *lst);
void				*ft_realloc(void *ptr, int size);
int					ft_issquare(int num);
int					ft_wrdcount(char const *str, char c);
char				*ft_realloc_str(char *str, size_t size);
int					ft_copy_until(char **dest, char *src, int stop);
void				ft_putspace(int num_spaces);
int					ft_ascii_cmp(char *s1, char *s2);
void				ft_sort_list_ascii(char ***lst, int start, int stop);
void				ft_free_strsplit(char ***strings);
char				*ft_uitoa_base(int n, int base, int upper);
char				*ft_itoa_base(int n, int base, int upper);
void				ft_print_bits(int num, int num_bits);

#endif
