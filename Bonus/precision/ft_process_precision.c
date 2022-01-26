#include "../incs/ft_printf_bonus.h"

char	*ft_process_precision(t_print *flags, char *arg)
{
	//printf("%d", flags->precision);
	//printf ("\nPROCESS PRECISION\n");
	char	*prc;
	int 	nbr;

	
	nbr = flags->precision;
	prc = (char *)malloc(sizeof(char) * nbr + 1);
	prc[nbr] = '\0';
	while (nbr-- > 0)
		prc[nbr] = arg[nbr];
	free(arg);
	return (prc);
}

