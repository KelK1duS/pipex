/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libwati.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:57:14 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 16:19:04 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBWATI_H
# define LIBWATI_H

# include <stddef.h>
# include <stdarg.h>

int		wati_isalpha(int c);
int		wati_isdigit(int c);
int		wati_isalnum(int c);
int		wati_isascii(int c);
int		wati_isprint(int c);
int		wati_isupper(int c);
int		wati_islower(int c);
int		wati_isspace(int c);

int		wati_toupper(int c);
int		wati_tolower(int c);
char	*wati_strupper(char *str0);
char	*wati_strlower(char *str0);

int		wati_abs(int nb);
int		wati_abs_f(float nb);
int		wati_abs_d(double nb);
int		wati_sig(int nb);
int		wati_sig_f(float nb);
int		wati_sig_d(double nb);

size_t	wati_strlen(const char *str);
size_t	wati_strlen_set(const char *s0, int c);

void	*wati_memset(void *s, int c, size_t n);
void	wati_bzero(void *s, size_t n);

void	*wati_memcpy(void *dest, const void *src, size_t n);
void	*wati_memmove(void *dest0, const void *src0, size_t n);
size_t	wati_strlcpy(char *dst, const char *src, size_t size);
size_t	wati_strlcat(char *dst, const char *src, size_t size);

char	*wati_strchr(const char *s, int c);
char	*wati_strrchr(const char *s, int c);
void	*wati_memchr(const void *s, int c, size_t n);

int		wati_strncmp(const char *s1, const char *s2, size_t n);
int		wati_memcmp(const void *s1, const void *s2, size_t n);
char	*wati_strnstr(const char *big, const char *little, size_t len);
char	*wati_strtrim(char const *s, char const *set);

int		wati_atoi(const char *nptr);
long	wati_atoll(const char *nptr);
char	*wati_itoa(int n);
int		wati_atoi_base(const char *nptr, char *base, size_t size);
size_t	wati_atou_base(const char *nptr, char *base, size_t size);

void	*wati_calloc(size_t nmemb, size_t size);
char	*wati_strdup(const char *s);
char	*wati_substr(char const *s, unsigned int start, size_t len);
char	*wati_strjoin(char const *s1, char const *s2);
char	**wati_split(char const *s, char c);
char	*wati_join(char **strs);

void	wati_free_tab(void *ptr);

char	*wati_strmapi(const char *s, char (*f)(unsigned int, char));
void	wati_striteri(char *s, void (*f)(unsigned int, char*));

void	wati_putchar_fd(char c, int fd);
void	wati_putstr_fd(char *s, int fd);
void	wati_putendl_fd(char *s, int fd);
void	wati_putnbr_fd(int n, int fd);
void	wati_putstrs_fd(char **s, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*wati_lstnew(void *content);
void	wati_lstadd_front(t_list **lst, t_list *new);
int		wati_lstsize(t_list *lst);
t_list	*wati_lstlast(t_list *lst);
void	wati_lstadd_back(t_list **lst, t_list *new);
void	wati_lstdelone(t_list *lst, void (*del)(void *));
void	wati_lstclear(t_list **lst, void (*del)(void *));
void	wati_lstiter(t_list *lst, void (*f)(void *));
t_list	*wati_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*wati_lstjoin(t_list *list);
void	wati_lstclean(t_list **lst);
char	**wati_lstsplit(t_list *list);

int		wati_printf(const char *format, ...);
int		wati_fprintf(int fd, const char *format, ...);
int		wati_vprintf(const char *format, va_list arg);
int		wati_vfprintf(int fd, const char *format, va_list arg);

int		wati_printf_arg(int fd, char format, va_list arg);

int		wati_printf_char_fd(char c, int fd);
int		wati_printf_str_fd(char *s, int fd);

int		wati_printf_unbr_base_fd(unsigned int n, char *base,
			size_t size, int fd);
int		wati_printf_snbr_base_fd(int n, char *base, size_t size, int fd);
int		wati_printf_ptr_fd(void *ptr, int fd);
int		wati_printf_usnbr_base_fd(size_t n, char *base, size_t size, int fd);

#endif
