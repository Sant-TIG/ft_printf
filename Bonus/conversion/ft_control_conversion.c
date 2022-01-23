#include "../incs/ft_printf_bonus.h"

void	ft_control_conversion(t_print *flags, const char *str)
{
	size_t	i;
	char	*str_nbr;
	char	*prec_str;

	i = 0;
	while (!ft_is_specifier(str[i]) && str[i] != '%')
	{
		if(str[i] == '-')
		{
			flags->sign = '-';
			i++;
			flags->width = 0;
		}
		else if (ft_isdigit(str[i]))
		{
			str_nbr = ft_get_width(&str[i]);
			flags->width = ft_atoi(str_nbr);
			while (ft_isdigit(str[i]))
				i++;
		}
		else if (str[i] ==  '.')
		{
			i++;
			prec_str = ft_get_precision(&str[i]);
			flags->precision = ft_atoi(prec_str);
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	if (ft_is_specifier(str[i]))
		flags->id = str[i];
}