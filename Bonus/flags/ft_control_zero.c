#include "../incs/ft_printf_bonus.h"

void	ft_control_zero(const char **format, t_bonus *flags)
{
	if (flags->zero == 0)
		flags->zero = 1;
	++*format;
}
