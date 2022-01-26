#include "../incs/ft_printf_bonus.h"

int	ft_putunbr(unsigned int unbr)
{
	char	*unbr_str;
	int		len;

	unbr_str = ft_uitoa(unbr);
	if (!unbr_str)
		return (0);
	len = ft_putstr(unbr_str);
	free(unbr_str);
	return (len);
}
/*
int	ft_putunbr(unsigned int unbr)
{
	int	len;

	len = 0;
	if (unbr > 9)
		len += ft_putunbr(unbr / 10);
	len += ft_putchar((unbr % 10) + 48);
	r*/