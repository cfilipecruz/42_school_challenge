#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

/* ===================== CHAR CHECKS ===================== */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

/* ===================== STRINGS ===================== */
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);

/* ===================== MEMORY ===================== */
void	*ft_memset(void *p, int c, size_t size);
void	ft_bzero(void *p, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* ===================== MORE STRINGS ===================== */
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* ===================== CONVERSION ===================== */
int		ft_atoi(const char *str);

/* ===================== CASE ===================== */
int		ft_toupper(int c);
int		ft_tolower(int c);
#endif