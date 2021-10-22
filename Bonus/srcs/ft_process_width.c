#include "../incs/ft_printf_bonus.h"

int	ft_process_width(char *arg, const char *format, size_t len)
{
	int		i;
	int		nbr;
	char 	*str;

	i = 0;
	nbr = 0;
	if (ft_isdigit(format[i]))
	{
		str = ft_get_width(format);
		nbr = ft_atoi(str) - ft_strlen(arg);
		while (nbr-- )
			i += ft_putchar(' ');
		return (i);
	}
	return (0);
}