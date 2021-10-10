#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_putlchar(char c);
int	ft_putlstr(char *str);
int	ft_putlptr(size_t adr);
size_t ft_strlen(char *str);

#endif
