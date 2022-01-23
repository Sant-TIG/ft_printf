#include <stdarg.h>
#include "../incs/ft_printf_bonus.h"

static size_t	ft_spclen(const char *str)
{
	size_t	i;

	i = 0;
	while(!ft_is_specifier(str[i]))
		i++;
	return (i);
}

void	ft_write_specifier(va_list ap, t_print *flags)
{
	if (flags->id == 'c')
		ft_process_char(va_arg(ap, int), flags);
	else if (flags->id == 's')
		ft_process_string(va_arg(ap, char *), flags);
}

void	ft_init_flags(t_print *flags)
{
	flags->sign = 0;
	flags->id = 0;
	flags->width = 0;
	flags->len = 0;
	flags->precision = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_print	flags;
	size_t	i;

	i = 0;
	va_start(ap, format);
	ft_init_flags(&flags);
	while (format[i])
	{
		if (format[i] == '%' && format[++i] != '%')
		{	
			ft_control_conversion(&flags, &format[i]);
			ft_write_specifier(ap, &flags);
			i += ft_spclen(&format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			flags.len++;
		}
		i++;
	}
	return(flags.len);
}