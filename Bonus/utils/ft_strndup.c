#include "../incs/ft_printf_bonus.h"

char	*ft_strndup(const char *str, size_t len)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strcpy(dst, str, len + 1);
	return (dst);
}