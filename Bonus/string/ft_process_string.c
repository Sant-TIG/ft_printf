#include "../incs/ft_printf_bonus.h"

void	ft_process_string(char *str, t_print *flags)
{
	if (!str)
		str = ft_strndup("(null)", 6);
	//if (flags->precision != 0)
		//str = ft_process_precision(flags, str);
	if (flags->sign == '-')
		flags->len += ft_putstr(str) + ft_process_width(flags, str);
	else if (flags->width != 0)
		flags->len += ft_process_width(flags, str) + ft_putstr(str);
	else
		flags->len += ft_putstr(str);
}