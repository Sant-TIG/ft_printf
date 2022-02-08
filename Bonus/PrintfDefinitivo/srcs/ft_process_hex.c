/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:13:25 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/08 18:37:53 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

void 	ft_process_hex(unsigned int hex, t_bonus *flags)
{
	char	*hex_str;

	hex_str = ft_hextoa(hex, flags);
	if ((flags->precision == 0 && hex == 0) && flags->hastack == 0)
	{
		if ((flags->width > 0 || flags->zero == 1))
			flags->len += ft_process_width(hex_str, flags) + ft_putstr("");
		else
			flags->len += ft_putstr("");
		free(hex_str);
	}
	else
	{
		if (flags->precision > ft_strlen(hex_str))
			hex_str = ft_process_precision_uint(flags, hex_str);
		if (flags->minus == 1 && flags->width == -1)
			flags->len += ft_putstr(hex_str);
		else if (flags->hastack == 1 && hex != 0)
		{
			if (flags->id == 'X' && hex != 0)
				flags->len += ft_putstr("0X") + ft_putstr(hex_str) + ft_process_width(hex_str, flags);
			else if ((flags->id == 'x') && hex != 0 )
				flags->len += ft_putstr("0x") + ft_putstr(hex_str) + ft_process_width(hex_str, flags);
		}
		else if (flags->hastack == 1 && hex == 0)
		{
			if (flags->id == 'X')
				flags->len += ft_putstr("0") + ft_process_width(hex_str, flags);
			else if (flags->id == 'x')
				flags->len += ft_putstr("0") + ft_process_width(hex_str, flags);
			
		}
		else if (flags->width > 0)
		{
			if (flags->minus == 1)
				flags->len += ft_putstr(hex_str) + ft_process_width(hex_str, flags);
			else
				flags->len += ft_process_width(hex_str, flags) + ft_putstr(hex_str);
		}
		else
			flags->len += ft_putstr(hex_str);
		free(hex_str);
	}
}
