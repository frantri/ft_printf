/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:15:42 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/26 20:26:01 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdint.h>

int					nbr_len_u			(uintmax_t n, int base);
int					nbr_len			 	(intmax_t n, int base);
int					ft_tabsize			(void **t);
int					ft_empty_string		(const char *s);
int					strmatch			(char *s1, char *s2);
void				init_0				(int *i1, int *i2, int *i3, int *i4);
void				init_2int			(int *i1, int v1, int *i2, int v2);
void				init_ptr			(void **ptr1, void **ptr2,
		void **ptr3, void **ptr4);
int					ft_match			(char *string, char *regex);
int					myprintf			(char *format, int fd, ...);
int					get_next_line		(int const fd, char **line);
void				ft_trim				(char **str);
char				*ft_strsubptr		(char *beg, char *end);
void				*ft_memset			(void *b, int c, size_t len);
int					ft_realloc			(void **mem1, size_t size1,
		void *mem2, size_t size2);
void				ft_bzero			(void *s, size_t n);
void				*ft_memcpy			(void *dst, const void *src, size_t n);
void				*ft_memccpy			(void *dst, const void *src,
		int c, size_t n);
void				*ft_memmove			(void *dst, const void *src,
		size_t len);
int					ft_memcmp			(const void *s1, const void *s2,
		size_t n);
void				*ft_memchr			(const void *s, int c, size_t n);

int					ft_get_index		(char *str, char c);
size_t				ft_strlen			(const char *s);
char				*ft_strcpy			(char *dst, const char *src);
char				*ft_strncpy			(char *dst, const char *src, size_t n);
char				*ft_strcat			(char *s1, const char *s2);
char				*ft_strncat			(char *s1, const char *s2, size_t n);
char				*ft_strrchr			(const char *s, int c);
char				*ft_strchr			(const char *s, int c);
char				*ft_strstr			(const char *s1, const char *s2);
char				*ft_strnstr			(const char *s1, const char *s2,
		size_t n);
int					ft_strcmp			(const char *s1, const char *s2);
int					ft_strncmp			(const char *s1, const char *s2,
		size_t n);
void				ft_strreplace		(char *str, char old, char new);
void				ft_freetab			(char **tab);
char				*ft_strdup			(const char *s);
size_t				ft_strlcat			(char *dest, const char *src, size_t n);
intmax_t			ft_atoi				(const char *str);
int					ft_isalnum			(int c);
int					ft_isalpha			(int c);
int					ft_isascii			(int c);
int					ft_isblank			(int c);
int					ft_isdigit			(int c);
int					ft_islower			(int c);
int					ft_isprint			(int c);
int					ft_isspace			(int c);
int					ft_isupper			(int c);
int					ft_tolower			(int c);
int					ft_toupper			(int c);
void				*ft_memalloc		(size_t size);
void				ft_memdel			(void **ap);
char				*ft_strnew			(size_t size);
void				ft_strdel			(char **as);
void				ft_strclr			(char *s);
void				ft_striter			(char *s,
		void (*f)(char *));
void				ft_striteri			(char *s,
		void (*f)(unsigned int, char*));
char				*ft_strmap			(char const *s, char (*f)(char));
char				*ft_strmapi			(const char *s,
		char (*f)(unsigned int, char));
int					ft_strequ			(const char *s1, const char *s2);
int					ft_strnequ			(const char *s1, const char *s2,
		size_t n);
char				*ft_strsub			(const char *s, unsigned int start,
		size_t len);
char				*ft_strjoin			(const char *s1, const char *s2);
char				*ft_strtrim			(const char *s);
char				**ft_strsplit		(const char *s, char c);
char				*ft_copy_word		(const char *s, char sep,
		unsigned int n);
void				ft_putchar			(char c);
void				ft_putstr			(const char *s);
void				ft_putendl			(const char *s);
void				ft_putnbr			(int nb);
void				ft_putchar_fd		(char c, int fd);
void				ft_putstr_fd		(const char *s, int fd);
void				ft_putendl_fd		(const char *s, int fd);
void				ft_putnbr_fd		(int nb, int fd);
#endif
