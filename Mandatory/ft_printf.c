#include "incs/ft_printf.h"

/*
  
*/

int	ft_write_specifier(va_list ap, char c, int len)
{
	if (c =='%')
		len += ft_putlchar('%');	
	if (c == 'c')
		len += ft_putlchar(va_arg(ap, int));
	if (c == 's')
		len += ft_putlstr(va_arg(ap, char *));
	if (c == 'p')
		len += ft_putlstr("0x") + ft_putlhex(va_arg(ap, size_t), c);
	if (c == 'x' || c == 'X')
		len += ft_putlhex(va_arg(ap, unsigned int), c);
	return(len);
}

/*
  
*/

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	len;

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

int main()
{
	int	len = 0, len1 = 0;

	printf("\n---NO %% CASE---\n");
	len = printf("Aqui no pasamos ningun parametro adicional\n");
	len1 = ft_printf("Aqui no pasamos ningun parametro adicional\n");
	printf("Printf = %d\tFt_printf = %d\n", len, len1);
	printf("\n---%% CASE---\n");
	len = printf("%%\n");
	len1 = ft_printf("%%\n");
	printf("%d \t%d\n", len, len1);
	ft_printf("\n---CHARACTER CASE---\n");
	len = printf("Estos son varios caracteres: %c, %c, %c, %c, %c, %c, %c.\n", 'a','1','\0','Z',  '0' - 256, '0' + 256, ' ');
	len1 = ft_printf("Estos son varios caracteres: %c, %c, %c, %c, %c, %c, %c.\n", 'a','1','\0','Z', '0' - 256, '0' + 256, ' ');
	printf("Printf = %d\tFt_printf = %d\n", len, len1);
	ft_printf("\n---SRING CASE---\n");
	len = printf("Estas son varias cadenas: %s, %s, %s, %s, %s.\n", "", "c", "4", "cadena ", NULL);
	len1 = ft_printf("Estas son varias cadenas: %s, %s, %s, %s, %s.\n", "", "c", "4", "cadena ", NULL);
	printf("Printf = %d\tFt_printf = %d\n", len, len1);
	ft_printf("\n---POINTER CASE---\n");
	len = printf("Estas son varias direcciones: %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p.\n", 0, 0, NULL, NULL, -1, 1, 15, 16, 17, LONG_MAX, LONG_MIN, INT_MAX, INT_MIN, ULLONG_MAX, -ULONG_MAX);
	len1 = ft_printf("Estas son varias direcciones: %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p.\n", 0, 0, NULL, NULL, -1, 1, 15, 16, 17, LONG_MAX, LONG_MIN, INT_MAX, INT_MIN, ULLONG_MAX, -ULONG_MAX);
	printf("Printf = %d\tFt_printf = %d\n", len, len1);
	ft_printf("\n---LOWERHEX CASE---\n");
	len = printf("Estos son varios numeros en hexadecimal txiki: %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len1 = ft_printf("Estos son varios numeros en hexadecimal txiki: %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	printf("Printf = %d\tFt_printf = %d\n", len, len1);
}
