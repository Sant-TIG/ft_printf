#include "../incs/ft_printf_bonus.h"
#include <stdlib.h>

char *ft_get_precision(const char *format)
{
	char 	*str;
	size_t	i;

	i = -1;
	str = (char *)malloc(sizeof(char) * (ft_prclen((char *)format) + 1));
	while (ft_isdigit(format[++i]))
		str[i] = format[i];
	str[i] = '\0';
	return (str);
}