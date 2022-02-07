/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:55:40 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/07 19:01:20 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"
#include <stdarg.h>

static char	*ft_spclen(const char *str)
{
	size_t	i;

	i = 0;
	while(!ft_is_specifier(str[i]))
		i++;
	return ((char *)&str[i]);
}

static void	ft_write_specifier(va_list ap, t_bonus *flags)
{
	if (flags->id == 'c')
		ft_process_char(va_arg(ap, int), flags);
	else if (flags->id == 's')
		ft_process_str(va_arg(ap, char *), flags);
	else if (flags->id == 'u')
		ft_process_uint(va_arg(ap, unsigned int), flags);
	else if (flags->id == 'p')
		ft_process_pointer(va_arg(ap, size_t), flags);
	else if (flags->id == 'x' || flags->id == 'X')
		ft_process_hex(va_arg(ap, unsigned int), flags);
	else if (flags->id == 'i' || flags->id == 'd')
		ft_process_int(va_arg(ap, int), flags);
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	t_bonus	flags;

	va_start(ap, format);
	ft_init_struct(&flags);
	while (*format)
	{
		if (*format == '%' && *++format != '%')
		{
			ft_control_flags(format, &flags);
			ft_write_specifier(ap, &flags);
			format = ft_spclen(format);
		}
		else
			flags.len += ft_putchar(*format);
		format++;
	}
	return (flags.len);
}
