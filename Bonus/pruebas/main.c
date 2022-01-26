#include <stdio.h>
#include "../incs/ft_printf_bonus.h"
int main()
{
	ft_printf("%010u|\n", 42);
	ft_printf("%-07u|\n", 42);
	ft_printf("%04u|\n", 42);
	ft_printf("%02u|\n", 42);

}