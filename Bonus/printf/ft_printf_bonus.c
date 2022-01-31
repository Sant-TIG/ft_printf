#include <stdarg.h>
#include "../incs/ft_printf_bonus.h"

int ft_printf(const char *format, ...)
{
	//printf("PRINTF\n");
	va_list	ap;
	t_bonus	flags;

	va_start(ap, format);
	ft_init_struct(&flags);
	while (*format)
	{
		if (*format == '%' && *++format != '%')
		{
			//printf("format = %s\n", format);
			ft_control_flags(format, &flags);
			ft_write_specifier(ap, &flags);
			format = ft_spclen(format);
			//printf("format = %s\n", format);
		}
		else
			flags.len += ft_putchar(*format);
		//printf("*format = %c\n", *format);
		format++;
		//printf("format = %s\n", format);
	}
	return (flags.len);
}
