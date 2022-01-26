#include "../incs/ft_printf_bonus.h"

void	ft_control_conversion(t_print *flags, const char *str)
{
	size_t	i;
	char	*width_str;
	char	*prec_str;

	i = 0;
	flags->width = -1;
	flags->precision = -1;
	while (!ft_is_specifier(str[i]) && str[i] != '%')
	{
		if(str[i] == '-')
		{
			flags->sign = '-';
			i++;
		}
		else if (str[i] == '0')
		{
			//printf("\nZEROOOO\n");
			flags->zero = 1;
			i++;
		}
		else if (ft_isdigit(str[i]))
		{
			width_str = ft_get_width(&str[i]);
			flags->width = ft_atoi(width_str);
			while (ft_isdigit(str[i]))
				i++;
		}
		else if (str[i] ==  '.')
		{
			i++;
			prec_str = ft_get_precision(&str[i]);
			//printf("\n\n%s", prec_str);
			flags->precision = ft_atoi(prec_str);
			//printf("flags->precision %d", flags->precision);
			free(prec_str);
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	if (ft_is_specifier(str[i]))
		flags->id = str[i];
}