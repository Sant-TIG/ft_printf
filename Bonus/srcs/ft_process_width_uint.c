#include "../incs/ft_printf_bonus.h"

int	ft_process_width_uint(unsigned int unbr, const char *format, char id)
{
	int		i;
	int		nbr;
	char 	*str;

	i = 0;
	nbr = 0;
	while ((!ft_isdigit(format[i]) && format[i] != id) || format[i] == '0')
		i++;
	if (ft_isdigit(format[i]) && format[i - 1] == '0' && !ft_check_minus(format, id))
	{
		str = ft_get_width(&format[i]);
		nbr = ft_atoi(str) - ft_strlen(str);
		while (nbr-- )
			i += ft_putchar('0');
		return (i);
	}
	if (ft_isdigit(format[i]))
	{
		str = ft_get_width(&format[i]);
		nbr = ft_atoi(str) - ft_strlen(str);
		while (nbr-- )
			i += ft_putchar(' ');
		return (i);
	}
	return (0);
}