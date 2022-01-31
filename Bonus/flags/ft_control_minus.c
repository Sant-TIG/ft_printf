#include "../incs/ft_printf_bonus.h"

void	ft_control_minus(const char **format, t_bonus *flags)
{
	if (flags->minus == 0)
		flags->minus = 1;
	++*format;
}
