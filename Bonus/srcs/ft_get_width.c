#include "../incs/ft_printf_bonus.h"
#include <stdlib.h>

char	*ft_get_width(const char *str)
{
	size_t	i;
	char	*dst;
	int		nbr;
	
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	dst[i] = '\0';
	while (i--)
		dst[i] = str[i];
	return (dst);
}