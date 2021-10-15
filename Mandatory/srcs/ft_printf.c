/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:31:24 by sperez-p          #+#    #+#             */
/*   Updated: 2021/10/14 17:12:42 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/ft_printf.h"
#include <stdarg.h>

static int	ft_write_specifier(va_list ap, char c, int len)
{
	if (c == 'c')
		len += ft_putlchar(va_arg(ap, int));
	if (c == 's')
		len += ft_putlstr(va_arg(ap, char *));
	if (c == 'p')
		len += ft_putlstr("0x") + ft_putlhex(va_arg(ap, size_t), c);
	if (c == 'd' || c == 'i')
		len += ft_putlnbr(va_arg(ap, int));
	if (c == 'u')
		len += ft_putlunbr(va_arg(ap, unsigned int));
	if (c == 'x' || c == 'X')
		len += ft_putlhex(va_arg(ap, unsigned int), c);
	if (c == '%')
		len += ft_putlchar('%');
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
			len += ft_putlchar(*format);
		format++;
	}
	va_end(ap);
	return (len);
}
