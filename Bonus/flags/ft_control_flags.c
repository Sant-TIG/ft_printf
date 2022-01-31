#include "../incs/ft_printf_bonus.h"

void	ft_control_flags(const char *format, t_bonus *flags)
{
	//char	*width_str;
	//printf("CONTROL FLAGS\n");
	ft_init_flags(flags);
	//printf("format = %s\n", format);
	while (!ft_is_specifier(*format) && *format != '%')
	{
		if (*format == '-')
			ft_control_minus(&format, flags);
		//printf("%d\n", flags->minus);
		if (ft_isdigit(*format))
			ft_control_width(&format, flags);
		//printf("%d\n", flags->width);
		if (*format == '.')
			ft_control_precision(&format, flags);
		//printf("%d\n", flags->precision);
	}
	if (ft_is_specifier(*format))
		flags->id = *format;
}
