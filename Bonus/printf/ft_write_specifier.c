#include "../incs/ft_printf_bonus.h"

void	ft_write_specifier(va_list ap, t_bonust *flags)
{
	if (flags->id == 'c')
		ft_process_char(va_arg(ap, int), flags);
	else if (flags->id == 's')
		ft_process_string(va_arg(ap, char *), flags);
	/*else if (flags->id == 'p')
		ft_process_pointer(va_arg(ap, unsigned long long), flags);
	if (flags->id == 'u')
		ft_process_uint(va_arg(ap, unsigned int), flags);
	else if (flags->id == 'd' || flags->id == 'i')
		ft_process_int(va_arg(ap, size_t), flags);
	else if (flags->id == 'x' || flags->id == 'X')
		ft_process_hex(va_arg(ap, unsigned int), flags);*/
}
