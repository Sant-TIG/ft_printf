#include "../incs/ft_printf_bonus.h"

char	*ft_get_width(const char *str)
{
	size_t	i;
	size_t	j;
	char	*dst;
	
	//printf("str = %s\n", str);
	i = 0;
	j = 0;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i + j]))
		j++;
	dst = (char *)malloc(sizeof(char) * (j + 1));
	if (!dst)
		return (NULL);
	dst[j] = '\0';
	while (j--)
		dst[j] = str[i + j];
	return (dst);
}
