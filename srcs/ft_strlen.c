#include "../incs/ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	str_len;

	str_len = 0;
	while (*str++)
		str_len++;
	return(str_len);
}
