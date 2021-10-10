#include "../incs/ft_printf.h"

int	ft_putlptr(size_t adr)
{
	int len;
	char* base;

	base = "0123456789abcdef";
	len = 0;
	if (adr == 0)
		len++;
	if (adr >= 16)
		len += ft_putlptr(adr / 16);
	len += ft_putchar(base[adr % 16]);
	return (len);
}
