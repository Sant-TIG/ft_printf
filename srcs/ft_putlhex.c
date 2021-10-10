#include "../incs/ft_printf.h"

int	ft_putlhex(size_t adr, char c)
{
	int len;
	char* xbase;
	char* Xbase;

	xbase = "0123456789abcdef";
	Xbase = "0123456789ABCDEF";
	len = 0;
	if (adr == 0)
		len++;
	if (c == 'x' || c == 'p')
	{
		if (adr >= 16)
			len += ft_putlhex(adr / 16, c);
		len += ft_putlchar(xbase[adr % 16]);
		return(len);
	}
	if (c == 'X')
	{
		if (adr >= 16)
			len += ft_putlhex(adr / 16, c);
		len += ft_putlchar(Xbase[adr % 16]);
		return(len);
	}
}
