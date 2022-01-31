#include "../incs/ft_printf_bonus.h"

void	ft_control_width(const char **format, t_bonus *flags)
{
	char	*width_str;

	width_str = ft_get_width(*format);
	flags->width = ft_atoi(width_str);
	free(width_str);
	while (ft_isdigit(**format) && *format)
		++*format;
}
