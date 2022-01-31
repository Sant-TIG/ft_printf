#include "../incs/ft_printf_bonus.h"

void	ft_control_precision(const char **format, t_bonus *flags)
{
	char	*prec_str;

	++*format;
	prec_str = ft_get_precision(*format);
	flags->precision = ft_atoi(prec_str);
	free(prec_str);
	while (ft_isdigit(**format))
		++*format;
}
