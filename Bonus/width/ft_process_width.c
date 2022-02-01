#include "../incs/ft_printf_bonus.h"

int	ft_process_width(char*str, t_bonus *flags)
{
	int	nbr;
	int	i;

	i = 0;
	/*if (ft_strstr(str, "0") && flags->width > ft_strlen(str))
	{
		nbr = flags->width;
		while (nbr-- > 0)
			i += ft_putchar(' ');
		return (i);
	}*/
	if (flags->id == 'c')
		nbr = (flags->width) - 1;
	else
		nbr = (flags->width) - ft_strlen(str);
	if (flags->zero == 1 && flags->plus == 0 && flags->precision <= -1)
	{
		//printf("hgfjhgsdfohlgsv");
		while (nbr-- > 0)
			i += ft_putchar('0');
		return (i);
	}
	else if (flags->precision != -1 && flags->width >= 0 && ft_strstr(str, "0"))
	{
		if (flags->precision == ft_strlen(str))
			nbr = 0;
		else
			nbr = flags->width;
		while (nbr--)
			i+= ft_putchar(' ');
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
