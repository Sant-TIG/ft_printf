#include "../incs/ft_printf_bonus.h"

int	ft_strlen(const char *str)
{
	//printf("\nSTRLEN\n");
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}