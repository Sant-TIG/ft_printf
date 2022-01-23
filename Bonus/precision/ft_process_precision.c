#include "../incs/ft_printf_bonus.h"

char *ft_process_precision(t_print *flags, char *format)
{
	size_t	i;
	char	*str;
	char	*prc;
	int 	nbr;

	i = 1;
	if (format[i] == '.' && format[i + 1] != '0')
	{
		i++;
		if (ft_isdigit(format[i]))
		{
			str = ft_get_precision(&format[i], id);
			nbr = ft_atoi(str);
			prc = (char *)malloc(sizeof(char) * nbr + 1);
			prc[nbr] = '\0';
			while (nbr--)
			{
				prc[nbr] = arg[nbr];
			}
			return (prc);
		}
		return (NULL);
	}
	return (arg);
}
int	ft_process_width(t_print *flags, char*str)
{
	int	nbr;
	int	i;

	i = 0;
	if (flags->id == 'c')
		nbr = (flags->width) - 1;
	else if (flags->id == 's')
		nbr = (flags->width) - ft_strlen(str);
	while (nbr-- > 0)
		i += ft_putchar(' ');
	return (i);
}