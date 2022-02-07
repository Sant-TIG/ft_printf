/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:02:46 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 16:44:21 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"

void	ft_control_flags(const char *format, t_bonus *flags)
{
	ft_init_flags(flags);
	while (!ft_is_specifier(*format) && *format != '%')
	{
		if (*format == '#')
			ft_control_hastack(&format, flags);
		if (*format == '+')
			ft_control_plus(&format, flags);
		if (*format == '-')
			ft_control_minus(&format, flags);
		if (*format == ' ')
			ft_control_space(&format, flags);
		if (*format == '0')
			ft_control_zero(&format, flags);
		if (ft_isdigit(*format))
			ft_control_width(&format, flags);
		if (*format == '.')
			ft_control_precision(&format, flags);
	}
	if (ft_is_specifier(*format))
		flags->id = *format;
}
