/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:53:31 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 17:54:27 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

int	ft_process_width(char*str, t_bonus *flags)
{
	int	nbr;
	int	i;

	i = 0;
	if (flags->id == 'c')
		nbr = (flags->width) - 1;
	else if (flags->sign != 0)
		nbr = (flags->width) - ft_strlen(str) - 1;
    else if (flags->id == 'p')
        nbr = (flags->width) - ft_strlen(str) - 2;
	else
		nbr = (flags->width) - ft_strlen(str);
	if (flags->precision != -1 && flags->width >= 0 && ft_strstr(str, "0"))
	{
		if (flags->precision == ft_strlen(str))
			nbr = 0;
		else
			nbr = flags->width;
		while (nbr--)
			i+= ft_putchar(' ');
		return (i);
	}	
	else if (flags->plus == 1)
	{
		if (flags->zero == 1)
		{
			i += ft_putchar('+');
			while (nbr-- > 1)
				i += ft_putchar('0');
			return (i);
		}
		while (nbr-- > 1)
			i += ft_putchar(' ');
		i += ft_putchar('+');
		return (i);			
	}
	else if (flags->space == 1)
	{
		if (flags->zero == 1)
		{
			while (nbr-- > 0)
				i += ft_putchar('0');
			return (i);
		}
	}
	else if (flags->zero == 1)
	{
		if (flags->precision > 0)
		{
			while (nbr-- > 0)
				i += ft_putchar(' ');
		}
		while (nbr-- > 0)
			i += ft_putchar('0');
		return (i);
	}
	while (nbr-- > 0)
		i += ft_putchar(' ');
	return (i);
}

