#include "../incs/ft_printf_bonus.h"

char	*ft_process_precision_str(t_print *flags, char *str)
{
	//printf("precisionn =%d",ft_strlen(unbr_str) + (flags->precision - ft_strlen(unbr_str)));
	//printf("\nPROCESS PRECISION UINT\n");
	char	*new_str;
	int		nbr;

	nbr = flags->precision;
	if (nbr > ft_strlen(str))
		return (str);
	new_str = (char *)malloc(sizeof(char) * nbr + 1);
	if (!new_str)
		return (NULL);
	//printf("%d\n", nbr);
	new_str[nbr] = '\0';
	while (nbr--)
		new_str[nbr] = str[nbr];
	//printf("\nnew_str_nbr = %s\n", new_nbr_str);
	return (new_str);
}

void	ft_process_string(char *str, t_print *flags)
{
	if (!str)
		str = ft_strndup("(null)", 6);
	if ((flags->precision == 0))
		str = "";
	if (flags->precision != -1)
	{
		if (flags->precision < ft_strlen(str))
			str = ft_process_precision_str(flags, str);
	}
	if (flags->sign == '-')
		flags->len += ft_putstr(str) + ft_process_width(flags, str);
	else if (flags->width != 0)
		flags->len += ft_process_width(flags, str) + ft_putstr(str);
	else
		flags->len += ft_putstr(str);
}