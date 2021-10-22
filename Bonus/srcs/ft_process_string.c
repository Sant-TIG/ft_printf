#include "../incs/ft_printf_bonus.h"

int	ft_process_string(char *arg, const char *format, char id)
{
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	if (!arg)
	{
		if (format[i] == '-')
		{
			len = ft_putstr("(null)") + ft_process_width("(null)", &format[i], 6);
			return (len);
		}
		if (ft_isdigit(format[i]))
		{
			len = ft_process_width("(null)", &format[i], 6) + ft_putstr("(null)");
			return (len);
		}
		return (ft_putstr("(null)"));
	}
	arg = ft_process_precision(arg, format, id);
	if (format[i] == '-')
	{
		i++;
		len = ft_putstr(arg) + ft_process_width(arg, &format[i], ft_strlen(arg));
		return (len);
	}
	if (ft_isdigit(format[i]))
	{
		len = ft_process_width(arg, &format[i], ft_strlen(arg)) + ft_putstr(arg);
		return (len);
	}
	else
		return (ft_putstr(arg));
	return (len);
}