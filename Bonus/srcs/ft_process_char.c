#include "../incs/ft_printf_bonus.h"
#include <stdlib.h>

int ft_process_char(int c, const char *format)
{
    size_t  i;
    char    *str;
    int     len;

    i = 0;
    len = 0;
    str = (char *)malloc(sizeof(char) * 2);
    str[0] = c;
    str[1] = '\0';
    if (format[i] == '-')
    {
        len = ft_putstr(str) + ft_process_width(str, &format[i + 1], len);
        return (len);
    }
    if (ft_isdigit(format[i]))
    {
        len = ft_process_width(str, format, len) + ft_putstr(str);
        return (len);   
    }
    else
        return (ft_putstr(str));
}