#include "../incs/ft_printf.h"

int	ft_putlnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == INT_MIN)
		return(ft_putlstr("-2147483648"));
	if (nbr < 0)
	{
		nbr *= -1;
		len = ft_putlchar('-');
	}
	if (nbr > 9)
		len += ft_putlnbr(nbr / 10);
	len += ft_putlchar((nbr % 10) + 48);
	return (len);
}