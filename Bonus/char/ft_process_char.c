#include "../incs/ft_printf_bonus.h"

void	ft_process_char(int c,t_print *flags)
{
	if (flags->sign == '-')
		flags->len += ft_putchar(c) + ft_process_width(flags, "");
	else if (flags->width != 0)
		flags->len += ft_process_width(flags, "") + ft_putchar(c);
	else
		flags->len += ft_putchar(c);
}