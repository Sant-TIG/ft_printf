#include "incs/ft_printf.h"

int main()
{
	int	len = 0, len1 = 0;

	printf("\n---NO %% CASE---\n");
	len = printf("Printf: Aqui no pasamos ningun parametro adicional\n");
	len1 = ft_printf("Ft_printf: Aqui no pasamos ningun parametro adicional\n");
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 3);
	printf("\n---%% CASE---\n");
	len = printf("Printf: %%\n");
	len1 = ft_printf("Ft_printf: %%\n");
	printf("%d \t%d\n", len, len1 - 3);
	ft_printf("\n---CHARACTER CASE---\n");
	len = printf("Printf: Estos son varios caracteres: %c, %c, %c, %c, %c, %c, %c.\n", 'a','1','\0','Z',  '0' - 256, '0' + 256, ' ');
	len1 = ft_printf("Ft_printf: Estos son varios caracteres: %c, %c, %c, %c, %c, %c, %c.\n", 'a','1','\0','Z', '0' - 256, '0' + 256, ' ');
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 3);
	ft_printf("\n---SRING CASE---\n");
	len = printf("Printf: Estas son varias cadenas: %s, %s, %s, %s, %s.\n", "", "c", "4", "cadena ", NULL);
	len1 = ft_printf("Ft_printf: Estas son varias cadenas: %s, %s, %s, %s, %s.\n", "", "c", "4", "cadena ", NULL);
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 3);
	ft_printf("\n---POINTER CASE---\n");
	len = printf("Printf: Estas son varias direcciones: %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p.\n", 0, 0, NULL, NULL, -1, 1, 15, 16, 17, LONG_MAX, LONG_MIN, INT_MAX, INT_MIN, ULLONG_MAX, -ULONG_MAX);
	len1 = ft_printf("Ft_printf: Estas son varias direcciones: %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p.\n", 0, 0, NULL, NULL, -1, 1, 15, 16, 17, LONG_MAX, LONG_MIN, INT_MAX, INT_MIN, ULLONG_MAX, -ULONG_MAX);
	printf("Printf = %d\tFt_printf = %d\n", len, len1);
	ft_printf("\n---LOWERHEX CASE---\n");
	len = printf("Printf: Estos son varios numeros en hexadecimal txiki: %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len1 = ft_printf("Ft_printf: Estos son varios numeros en hexadecimal txiki: %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len += printf("Printf: Estos son varios numeros en hexadecimal txiki: %x, %x, %x, %x, %x, %x, %x.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	len1 += ft_printf("Ft_printf: Estos son varios numeros en hexadecimal txiki: %x, %x, %x, %x, %x, %x, %x.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 6);
	ft_printf("\n---UPPERHEX CASE---\n");
	len = printf("Printf: Estos son varios numeros en hexadecimal mayor: %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len1 = ft_printf("Ft_printf: Estos son varios numeros en hexadecimal mayor: %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len += printf("Printf: Estos son varios numeros en hexadecimal mayor: %X, %X, %X, %X, %X, %X, %X.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	len1 += ft_printf("Ft_printf: Estos son varios numeros en hexadecimal mayor: %X, %X, %X, %X, %X, %X, %X.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 6);
	ft_printf("\n---DECIMAL CASE---\n");
	len = printf("Printf: Estos son varios numeros decimales: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len1 = ft_printf("Ft_printf: Estos son varios numeros decimales: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len += printf("Printf: Estos son varios numeros decimales: %d, %d, %d, %d, %d, %d, %d.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	len1 += ft_printf("Ft_printf: Estos son varios numeros decimales: %d, %d, %d, %d, %d, %d, %d.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 6);
	ft_printf("\n---INTEGER CASE---\n");
	len = printf("Printf: Estos son varios numeros enteros: %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len1 = ft_printf("Ft_printf: Estos son varios numeros enteros: %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len += printf("Printf: Estos son varios numeros enteros: %i, %i, %i, %i, %i, %i, %i.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	len1 += ft_printf("Ft_printf: Estos son varios numeros enteros: %i, %i, %i, %i, %i, %i, %i.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 6);
	ft_printf("\n---UNSIGNED INT CASE---\n");
	len = printf("Printf: Estos son varios numeros enteros sin signo: %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len1 = ft_printf("Ft_printf: Estos son varios numeros enteros sin signo: %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
	len += printf("Printf: Estos son varios numeros enteros sin signo: %u, %u, %u, %u, %u, %u, %u.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	len1 += ft_printf("Ft_printf: Estos son varios numeros enteros sin signo: %u, %u, %u, %u, %u, %u, %u.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("Printf = %d\tFt_printf = %d\n", len, len1 - 6);
}
