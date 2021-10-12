#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_putlchar(char c);
int	ft_putlstr(char *str);
int	ft_putlhex(size_t adr, char c);
size_t ft_strlen(char *str);

#endif
