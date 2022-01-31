#include "../incs/ft_printf_bonus.h"

void	ft_process_char(int c, t_bonus *flags)
{
	if (flags->width > 0)
	{
		if (flags->minus == 1)
			flags->len += ft_putchar(c) + ft_process_width ("", flags);
		else
			flags->len += ft_process_width("", flags) + ft_putchar(c);
	}
	else if (flags->minus == 1)
		flags->len += ft_putchar(c) + ft_process_width ("", flags);
	else
		flags->len += ft_putchar(c);
}
