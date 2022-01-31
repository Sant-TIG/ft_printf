#include "../incs/ft_printf_bonus.h"

int	ft_strstr(char *str, char *str1)
{
	while (*str && *str1 && *str == *str1)
	{
		str++;
		str1++;
	}
	if (*str != *str1)
		return (0);
	return(1);
}
