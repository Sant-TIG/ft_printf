#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}