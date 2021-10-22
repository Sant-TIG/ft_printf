#include "../incs/ft_printf_bonus.h"
#include <stdarg.h>

static size_t	ft_spclen(const char *str)
{
	size_t	i;

	i = 0;
	while(!ft_is_specifier(str[i]))
		i++;
	return (i);
}


static int	ft_write_specifier(va_list ap,const char *format, char id)
{
	int	len;

	len = 0;
	if (id == 'c')
		len = ft_process_character(va_arg(ap, int), format, id);
	if (id == 's')
		len = ft_process_string(va_arg(ap, char *), format, id);
	return (len);
}

static char	ft_identify_specifier(const char *str, int i)
{
	while(!ft_is_specifier(str[i]))
		i++;
	return (str[i]);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	char	id;
	size_t	i;
	size_t	format_len;

	i = 0;
	format_len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			id = ft_identify_specifier(format, i);
			format_len += ft_write_specifier(ap, &format[i + 1], id);
			i += ft_spclen(&format[i]) + 1;
		}
		else
		{
			i += ft_putchar(format[i]);
			format_len++;
		}
	}
	va_end(ap);
	return (format_len);
}