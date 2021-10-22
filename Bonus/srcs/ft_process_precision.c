#include "../incs/ft_printf_bonus.h"
#include <stdlib.h>

char *ft_process_precision(char *arg, const char *format, char id)
{
	size_t	i;
	char	*str;
	char	*prc;
	int 	nbr;

	i = 0;
	nbr = 0;
	while (format[i] != '.' && format[i] != id)
		i++;
	if (format[i] == '.')
	{
		i++;
		if (format[i] != '0')
		{
			if (ft_isdigit(format[i]))
			{
				str = ft_get_precision(&format[i]);
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
		return (NULL);
	}
	return (arg);
}