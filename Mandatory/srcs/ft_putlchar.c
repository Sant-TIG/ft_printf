#include "../incs/ft_printf.h"

int	ft_putlchar(char c)
{
	write(1, &c, 1);
}