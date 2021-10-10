#include "../incs/ft_printf.h"

int	ft_putlstr(char *str)
{
	if (!str)
		return(write(1, "(null)", 6));
	write(1, str, ft_strlen(str));
}
