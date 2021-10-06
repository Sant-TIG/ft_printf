#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	len;

	len = 0;
	va_start(ap, format);
	while(*format != '\0')
	{
		if (*format == '%')
		{
			len = ft_write_specifier(ap, *++format, len);
			format++;
		}
		else
			len += ft_putchar_fd(*format++, 1);
	}
	va_end(ap);
	return (len);
}

int main()
{
	int len = 0, len1 = 0;

	printf("\n---NO %% CASE---\n");
	len = printf("abcdefg\n");
	len1 = ft_printf("abcdefg\n");
	printf("%d \t%d\n", len, len1);
	printf("\n---CHARACTER CASE---\n");
	len = printf("Esto es un caracter: %c\n", 'c');
	len1 = ft_printf("Esto es un caracter: %c\n", 'c');
	printf("%d \t%d\n", len, len1);
	printf("\n---STRING CASE---\n");
	len = printf("Esto es una cadena: %s\n", "cadena");
	len1 = ft_printf("Esto es una cadena: %s\n", "cadena");
	printf("%d \t%d\n", len, len1);
	printf("\n---POINTER CASE---\n");
	int* p = &len;
	len = printf("Esto es una direccion: %p\n", p);
	len1 = ft_printf("Esto es una direccion: %p\n", p);
	printf("%d \t%d\n", len, len1);
}