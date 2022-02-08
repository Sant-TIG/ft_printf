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

static void	ft_treat_zero(char *hex_str, t_bonus *flags)
{
	if ((flags->width > 0 || flags->zero == 1))
		flags->len += ft_process_width(hex_str, flags) + ft_putstr("");
	else
		flags->len += ft_putstr("");
}

static void ft_treat_hastack(char *hex_str, t_bonus *flags)
{
	if (ft_strstr(hex_str, "0"))
	{
		if (flags->id == 'X')
			flags->len += ft_putstr("0") + ft_process_width(hex_str, flags);
		else if (flags->id == 'x')
			flags->len += ft_putstr("0") + ft_process_width(hex_str, flags);
	}
	else
	{
		if (flags->id == 'X')
			flags->len += ft_putstr("0X") + ft_putstr(hex_str) + ft_process_width(hex_str, flags);
		else if (flags->id == 'x')
			flags->len += ft_putstr("0x") + ft_putstr(hex_str) + ft_process_width(hex_str, flags);
	}
}

static void ft_treat_width(char *hex_str, t_bonus *flags)
{
	if (flags->minus == 1)
		flags->len += ft_putstr(hex_str) + ft_process_width(hex_str, flags);
	else
		flags->len += ft_process_width(hex_str, flags) + ft_putstr(hex_str);
}

void 	ft_process_hex(unsigned int hex, t_bonus *flags)
{
	char	*hex_str;

	if (flags->id == 'x')
		hex_str = ft_nbrtoa_base(hex, flags, LOWERXBASE);
	else
		hex_str = ft_nbrtoa_base(hex, flags, UPPERXBASE);
	if ((flags->precision == 0 && hex == 0) && flags->hastack == 0)
	{
		ft_treat_zero(hex_str, flags);
		free(hex_str);
	}
	else
	{
		if (flags->precision > ft_strlen(hex_str))
			hex_str = ft_process_precision_uint(flags, hex_str);
		if (flags->minus == 1 && flags->width == -1)
			flags->len += ft_putstr(hex_str);
		else if (flags->hastack == 1)
			ft_treat_hastack(hex_str, flags);
		else if (flags->width > 0)
			ft_treat_width(hex_str, flags);
		else
			flags->len += ft_putstr(hex_str);
		free(hex_str);
	}
}
