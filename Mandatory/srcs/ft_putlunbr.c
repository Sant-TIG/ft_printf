#include "../incs/ft_printf.h"

int	ft_putlunbr(unsigned int unbr)
{
	int	len;

	len = 0;
	if (unbr > 9)
		len += ft_putlunbr(unbr / 10);
	len += ft_putlchar((unbr % 10) + 48);
	return (len);
}