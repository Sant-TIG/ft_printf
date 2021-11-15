/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:31:24 by sperez-p          #+#    #+#             */
/*   Updated: 2021/11/12 17:02:43 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/ft_printf.h"
#include <stdarg.h>

static int	ft_write_specifier(va_list ap, char c, int len)
{
	if (c == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		len += ft_putstr("0x") + ft_puthex(va_arg(ap, size_t), c);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		len += ft_putunbr(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_puthex(va_arg(ap, unsigned int), c);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			len = ft_write_specifier(ap, *++format, len);
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (len);
}
