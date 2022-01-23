#include "../incs/ft_printf_bonus.h"

char *ft_get_precision(const char *str)
{
	size_t	i;
	size_t	j;
	char	*dst;
	
	i = 0;
	j = 0;

	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i + j]))
		j++;
	dst = (char *)malloc(sizeof(char) * (j + 1));
	dst[j] = '\0';
	while (j--)
	{
		dst[j] = str[i + j];
	}
	return (dst);
}