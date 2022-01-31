#include "../incs/ft_printf_bonus.h"

char	*ft_spclen(const char *str)
{
	size_t	i;

	i = 0;
	while(!ft_is_specifier(str[i]))
		i++;
	return ((char *)&str[i]);
}
