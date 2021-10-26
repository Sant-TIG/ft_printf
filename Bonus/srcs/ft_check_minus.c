#include <stddef.h>

int	ft_check_minus(const char *format, char id)
{
	size_t	i;

	i = 0;
	while (format[i] != '-' && format[i] != id)
		i++;
	return (format[i] == '-');
}