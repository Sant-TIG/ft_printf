#include "../incs/ft_printf_bonus.h"
#include <stdio.h>
char	*ft_process_precision_uint(t_print *flags, char *unbr_str)
{
	//printf("precisionn =%d",ft_strlen(unbr_str) + (flags->precision - ft_strlen(unbr_str)));
	//printf("\nPROCESS PRECISION UINT\n");
	char	*new_nbr_str;
	int		nbr;
	size_t	i;
	size_t	j;

	i = 0;

	nbr = (flags->precision) - ft_strlen(unbr_str);
	nbr += ft_strlen(unbr_str) + 1;
	new_nbr_str = (char *)malloc(sizeof(char) * nbr + 1);
	if (!new_nbr_str)
		return (NULL);
	//printf("%d\n", nbr);
	while (nbr-- > ft_strlen(unbr_str) + 1)
		new_nbr_str[i++] = '0';
	j = 0;
	while (nbr--)
		new_nbr_str[i++] = unbr_str[j++];
	new_nbr_str[i] = '\0';
	free(unbr_str);
	//printf("\nnew_str_nbr = %s\n", new_nbr_str);
	return (new_nbr_str);
}

void	ft_process_uint(unsigned int unbr, t_print *flags)
{
	char	*unbr_str;

	unbr_str = ft_uitoa(unbr);
	if ((flags->precision == 0 && unbr == 0))
		unbr_str = "";
	else if (flags->precision > ft_strlen(unbr_str))
		unbr_str = ft_process_precision_uint(flags, unbr_str);
	//printf("\nunbr_str = %s\n", unbr_str);
	if (flags->sign == '-')
		flags->len += ft_putstr(unbr_str) + ft_process_width(flags, unbr_str);
	else if (flags->width > 0 || flags->zero == 1)
	{
		//printf("\nZEROOOO2\n");
		flags->len += ft_process_width(flags, unbr_str) + ft_putstr(unbr_str);
	}
	else
		flags->len += ft_putstr(unbr_str);
}