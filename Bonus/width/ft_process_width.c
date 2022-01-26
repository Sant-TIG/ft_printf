#include "../incs/ft_printf_bonus.h"

int	ft_process_width(t_print *flags, char*str)
{
	int	nbr;
	int	i;

	i = 0;
	if (flags->id == 'c')
		nbr = (flags->width) - 1;
	else if (flags->id == 's' || flags->id == 'u')
		nbr = (flags->width) - ft_strlen(str);
	if (flags->zero == 1)
	{
		//printf("hgfjhgsdfohlgsv");
		while (nbr-- > 0)
			i += ft_putchar('0');
		return (i);
	}
	while (nbr-- > 0)
		i += ft_putchar(' ');
	return (i);
}