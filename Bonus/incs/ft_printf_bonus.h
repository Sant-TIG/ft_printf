#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

#include <stddef.h>

int		ft_atoi(const char *str);
char 	*ft_get_precision(const char *format);
char	*ft_get_width(const char *str);
int		ft_is_specifier(char c);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
int		ft_prclen(char *str);
int		ft_printf(const char *format, ...);
int     ft_process_char(int c, const char *format);
char 	*ft_process_precision(char *arg, const char *format, char id);
int		ft_process_string(char *arg, const char *format, char id);
int		ft_process_width(char *arg, const char *format, size_t len);
int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(char *str);

#endif