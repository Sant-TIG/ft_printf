#include "../incs/ft_printf_bonus.h"
#include <stdio.h>

static size_t	ft_uintlen(unsigned int unbr)
{
	size_t	unbr_len;

	unbr_len = 0;
	while (unbr > 0)
	{
		unbr /= 10;
		unbr_len++;
	}
	return (unbr_len);
}

static char	*ft_charconv(char *dest, unsigned int unbr, size_t unbr_len)
{
	if (unbr == 0)
		*dest = 48;
	while (unbr > 0)
	{
		*(dest + unbr_len--) = 48 + (unbr % 10);
		unbr /= 10;
	}
	return (dest);
}

char	*ft_uitoa(unsigned int unbr)
{
	//printf("\nUITOA\n");
	char	*dest;
	size_t		unbr_len;

	unbr_len = ft_uintlen(unbr);
	dest = (char *)malloc(sizeof(char) * unbr_len + 1);
	if (!dest)
		return (NULL);
	*(dest + unbr_len--) = '\0';
	dest = ft_charconv(dest, unbr, unbr_len);
	//printf("\ndest = %s\n", dest);
	return (dest);
}