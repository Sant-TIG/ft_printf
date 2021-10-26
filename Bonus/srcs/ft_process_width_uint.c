#include "../incs/ft_printf_bonus.h"

static int	ft_uintlen(unsigned int unbr)
{
	int i;

	i = 0;
	while (unbr > 9)
	{
		unbr /= 10;
		i++;
	}
	i++;
	return (i);
}

int	ft_process_width_uint(unsigned int unbr, const char *format, char id)
{
	int		i;
	int		nbr;
	char 	*str;
	char	*ustr;

	i = 0;
	nbr = 0;
	while ((!ft_isdigit(format[i]) && format[i] != id) || format[i] == '0')
		i++;
	if (ft_isdigit(format[i]) && format[i - 1] == '0' && !ft_check_minus(format, id))
	{
		str = ft_get_width(&format[i]);
		nbr = ft_atoi(str) - ft_uintlen(unbr);
		while (nbr-- )
			i += ft_putchar('0');
		return (i);
	}
	if (ft_isdigit(format[i]))
	{
		str = ft_get_width(&format[i]);
		nbr = ft_atoi(str) - ft_uintlen(unbr);
		while (nbr-- )
			i += ft_putchar(' ');
		return (i);
	}
	return (0);
}