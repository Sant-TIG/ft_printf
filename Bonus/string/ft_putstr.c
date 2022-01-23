#include "../incs/ft_printf_bonus.h"
#include <unistd.h>

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}