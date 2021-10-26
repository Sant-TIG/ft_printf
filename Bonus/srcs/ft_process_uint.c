#include "../incs/ft_printf_bonus.h"
#include <stdio.h>

int	ft_process_uint(unsigned int unbr, const char *format, char id)
{
	int	len;
	size_t	i;

	i = 0;
	len = 0;
	//printf ("\n---%u---\n", unbr);
	if (ft_check_minus(&format[i], id))
	{
		len = ft_putlunbr(unbr) + ft_process_width_uint(unbr, &format[i],id);
		return (len);
	}
	else
	{
		len = ft_process_width_uint(unbr, &format[i], id) + ft_putlunbr(unbr);
		return (len);
	}
	return (len);
}