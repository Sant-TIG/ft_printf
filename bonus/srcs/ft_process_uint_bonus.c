/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:13:54 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/11 10:23:07 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

void	ft_process_uint(unsigned int unbr, t_bonus *flags)
{
	char	*unbr_str;

	unbr_str = ft_nbrtoa_base(unbr, flags, DECBASE);
	if ((flags->precision == 0 && unbr == 0))
	{
		if (flags->width > 0 || flags->zero == 1)
			flags->len += ft_process_width(unbr_str, flags) + ft_putstr("");
		else
			flags->len += ft_putstr("");
		free(unbr_str);
	}
	else
	{
		if (flags->precision > ft_strlen(unbr_str))
			unbr_str = ft_process_precision_uint(flags, unbr_str);
		if (flags->minus == 1)
			flags->len += ft_putstr(unbr_str)
				+ ft_process_width(unbr_str, flags);
		else if (flags->width > 0 || flags->zero == 1)
			flags->len += ft_process_width(unbr_str, flags)
				+ ft_putstr(unbr_str);
		else
			flags->len += ft_putstr(unbr_str);
		free(unbr_str);
	}		
}
