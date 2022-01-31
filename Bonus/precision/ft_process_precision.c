#include "../incs/ft_printf_bonus.h"

char	*ft_process_precision(char *str, t_bonus *flags)
{
	//printf("%d", flags->precision);
	//printf ("\nPROCESS PRECISION\n");
	char	*prc;
	int 	nbr;

	if (ft_strstr(str, "(null)"))
	{
		free(str);
		return ("");
	}
	nbr = flags->precision;
	prc = (char *)malloc(sizeof(char) * nbr + 1);
	prc[nbr] = '\0';
	while (nbr-- > 0)
		prc[nbr] = str[nbr];
	free(str);
	return (prc);
}
