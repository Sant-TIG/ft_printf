#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar_fd(char c, int fd);
int	ft_write_specifier(va_list ap, char c, int len);

#endif
