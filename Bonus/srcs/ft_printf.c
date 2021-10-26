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
		len = ft_process_char(va_arg(ap, int), format);
	if (id == 's')
		len = ft_process_string(va_arg(ap, char *), format, id);
	/*if (id == 'i' || id == 'd')
		len = ft_process_int_dec(va_arg(ap, int), format, id);*/
	if (id == 'u')
		len = ft_process_uint(va_arg(ap, unsigned int), format, id);
	if (id == '%')
		len = ft_putchar('%');
	return (len);
}

static char	ft_identify_specifier(const char *str)
{
	size_t	i;

	i = 0;
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
		if (format[i] == '%')
		{
			i++;
			id = ft_identify_specifier(&format[i]);
			format_len += ft_write_specifier(ap, &format[i], id);
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