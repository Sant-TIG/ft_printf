#include "../incs/ft_printf_bonus.h"

int	ft_prclen(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}