#include "../incs/ft_printf_bonus.h"

int	ft_process_width(char*str, t_bonus *flags)
{
	int	nbr;
	int	i;

	i = 0;
	if (flags->id == 'c')
		nbr = (flags->width) - 1;
	else
		nbr = (flags->width) - ft_strlen(str);
	if (flags->zero == 1 && flags->plus == 0)
	{
		//printf("hgfjhgsdfohlgsv");
		while (nbr-- > 0)
			i += ft_putchar('0');
		return (i);
	}
	else if (flags->plus == 1 || flags->space == 1)
	{
		while (--nbr > 0)
			i += ft_putchar(' ');
		return (i);
	}
	while (nbr-- > 0)
		i += ft_putchar(' ');
	return (i);
}
